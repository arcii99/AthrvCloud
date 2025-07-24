//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFSIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char message[BUFFSIZE], server_reply[BUFFSIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
    }
    puts("Socket created");

    // Server configuration
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(143);

    // Connect to remote server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connect failed");
        return 1;
    }
    puts("Connected\n");

    // Receive greeting from server
    if (recv(sock, server_reply, BUFFSIZE, 0) < 0) {
        perror("recv failed");
        return 1;
    }
    printf("%s\n", server_reply);

    // Send login command
    strcpy(message, ". LOGIN username password\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }
    puts("Login sent\n");

    // Receive response from server
    if (recv(sock, server_reply, BUFFSIZE, 0) < 0) {
        perror("recv failed");
        return 1;
    }
    printf("%s\n", server_reply);

    // Send list command
    strcpy(message, ". LIST\n");
    if (send(sock, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }
    puts("List sent\n");

    // Receive response from server
    if (recv(sock, server_reply, BUFFSIZE, 0) < 0) {
        perror("recv failed");
        return 1;
    }
    printf("%s\n", server_reply);

    // Close socket
    close(sock);
    puts("Socket closed");

    return 0;
}