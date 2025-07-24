//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER 2048

int main(int argc, char *argv[]) {
    int socket_desc, recv_size;
    struct sockaddr_in server;
    char *message, recv_buffer[MAX_BUFFER];

    // Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_desc == -1) {
        printf("Error: Could not create socket");
        return 1;
    }

    // Connect to the server
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(110);

    if (connect(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        printf("Error: Could not connect to server");
        return 1;
    }

    // Receive connection greeting
    if ((recv_size = recv(socket_desc, recv_buffer, MAX_BUFFER, 0)) < 0) {
        printf("Error: Could not receive greeting message from server");
        return 1;
    }

    printf("Server greeting: %s\n", recv_buffer);

    // Send username
    message = "USER username\r\n";

    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Error: Could not send username to server");
        return 1;
    }

    if ((recv_size = recv(socket_desc, recv_buffer, MAX_BUFFER, 0)) < 0) {
        printf("Error: Could not receive response message from server");
        return 1;
    }

    printf("Server response: %s\n", recv_buffer);

    // Send password
    message = "PASS password\r\n";

    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Error: Could not send password to server");
        return 1;
    }

    if ((recv_size = recv(socket_desc, recv_buffer, MAX_BUFFER, 0)) < 0) {
        printf("Error: Could not receive response message from server");
        return 1;
    }

    printf("Server response: %s\n", recv_buffer);

    // Send list command
    message = "LIST\r\n";

    if (send(socket_desc, message, strlen(message), 0) < 0) {
        printf("Error: Could not send list command to server");
        return 1;
    }

    if ((recv_size = recv(socket_desc, recv_buffer, MAX_BUFFER, 0)) < 0) {
        printf("Error: Could not receive response message from server");
        return 1;
    }

    printf("Server response:\n%s\n", recv_buffer);

    // Close the socket
    close(socket_desc);

    return 0;
}