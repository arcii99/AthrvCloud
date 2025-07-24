//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    int sock_desc, read_size;
    struct sockaddr_in serv_addr;
    char *message, server_reply[2000];

    // Create socket
    sock_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_desc == -1) {
        printf("Could not create socket");
        exit(1);
    }

    // Set server address
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(110);

    // Connect to server
    if (connect(sock_desc, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) != 0) {
        printf("Connection Error");
        exit(1);
    }

    // Send user info to server
    message = "USER example@example.com\r\n";
    if (send(sock_desc, message, strlen(message), 0) < 0) {
        printf("Send Error");
        exit(1);
    }

    memset(server_reply, 0, sizeof(server_reply));
    // Read server response
    if ((read_size = recv(sock_desc, server_reply, 2000, 0)) <= 0) {
        printf("Receive Error");
        exit(1);
    }

    printf("Server Response: %s\n", server_reply);

    // Send password to server
    message = "PASS mypassword\r\n";
    if (send(sock_desc, message, strlen(message), 0) < 0) {
        printf("Send Error");
        exit(1);
    }

    memset(server_reply, 0, sizeof(server_reply));
    // Read server response
    if ((read_size = recv(sock_desc, server_reply, 2000, 0)) <= 0) {
        printf("Receive Error");
        exit(1);
    }

    printf("Server Response: %s\n", server_reply);

    // Send list command to server
    message = "LIST\r\n";
    if (send(sock_desc, message, strlen(message), 0) < 0) {
        printf("Send Error");
        exit(1);
    }

    memset(server_reply, 0, sizeof(server_reply));
    // Read server response
    if ((read_size = recv(sock_desc, server_reply, 2000, 0)) <= 0) {
        printf("Receive Error");
        exit(1);
    }

    printf("Server Response: %s\n", server_reply);

    // Close the socket
    close(sock_desc);
    return 0;
}