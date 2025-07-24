//FormAI DATASET v1.0 Category: Email Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char message[MAX_SIZE], server_reply[MAX_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        return 1;
    }

    // Server connection parameters
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8888);

    // Connect to server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return 1;
    }

    printf("Connected to server\n");

    // Receive welcome message from server
    if (recv(sock, server_reply, MAX_SIZE, 0) < 0) {
        perror("Receive failed");
        return 1;
    }

    printf("Server: %s", server_reply);

    // Send email message
    printf("\nEnter message body (maximum 1024 characters):\n");
    fgets(message, MAX_SIZE, stdin);

    if (send(sock, message, strlen(message), 0) < 0) {
        perror("Send failed");
        return 1;
    }

    printf("\nEmail sent successfully!\n");

    close(sock);
    return 0;
}