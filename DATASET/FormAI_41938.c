//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char message[MAX_BUFFER_SIZE], server_reply[MAX_BUFFER_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket");
    }

    // Server configuration
    server.sin_addr.s_addr = inet_addr("POP3_SERVER_IP_ADDRESS");
    server.sin_family = AF_INET;
    server.sin_port = htons(110);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed. Error");
        return 1;
    }

    // Receive greeting from server
    if (recv(sock, server_reply, MAX_BUFFER_SIZE, 0) < 0) {
        puts("recv failed");
    }
    printf("%s\n", server_reply);

    // Send username to server
    printf("Username: ");
    fgets(message, MAX_BUFFER_SIZE, stdin);
    strcat(message, "\r\n");
    send(sock, message, strlen(message), 0);
    memset(message, 0, MAX_BUFFER_SIZE);

    // Receive response from server
    if (recv(sock, server_reply, MAX_BUFFER_SIZE, 0) < 0) {
        puts("recv failed");
    }
    printf("%s\n", server_reply);

    // Send password to server
    printf("Password: ");
    fgets(message, MAX_BUFFER_SIZE, stdin);
    strcat(message, "\r\n");
    send(sock, message, strlen(message), 0);
    memset(message, 0, MAX_BUFFER_SIZE);

    // Receive response from server
    if (recv(sock, server_reply, MAX_BUFFER_SIZE, 0) < 0) {
        puts("recv failed");
    }
    printf("%s\n", server_reply);

    // Close connection
    close(sock);
    return 0;
}