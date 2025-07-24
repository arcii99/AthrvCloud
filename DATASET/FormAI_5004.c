//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define MAX_BUFFER_SIZE 1024

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int connection_status = connect(sock, (struct sockaddr *) &server_address, sizeof(server_address));

    if (connection_status < 0) {
        printf("Could not connect to server.\n");
        exit(1);
    }

    printf("Connected to server!\n");

    char message[MAX_BUFFER_SIZE];
    printf("Enter message to send: ");
    fgets(message, MAX_BUFFER_SIZE, stdin);

    int sent_status = send(sock, message, strlen(message), 0);

    if (sent_status < 0) {
        printf("Failed to send message.\n");
        exit(1);
    }

    printf("Message successfully sent to server!\n");

    char server_response[MAX_BUFFER_SIZE];
    int received_status = recv(sock, server_response, MAX_BUFFER_SIZE, 0);

    if (received_status < 0) {
        printf("Failed to receive message from server.\n");
        exit(1);
    }

    printf("Server responded with: %s\n", server_response);

    close(sock);

    return 0;
}