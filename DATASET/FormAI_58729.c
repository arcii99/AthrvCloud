//FormAI DATASET v1.0 Category: Socket programming ; Style: scientific
/*
 * This program creates a client-server communication using C sockets.
 * The client sends a mathematical expression to the server, which evaluates
 * it and returns the result to the client.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

    int sock = 0;
    struct sockaddr_in serv_addr;
    char expression[100] = {0};
    double result = 0.0;

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    // Connect the socket with the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        return -1;
    }

    while(1) {
        printf("Enter a mathematical expression (or 'exit' to quit): ");
        fgets(expression, 100, stdin);

        // Send the expression to the server
        send(sock, expression, strlen(expression), 0);

        // Exit condition
        if (strcmp(expression, "exit\n") == 0) {
            printf("Goodbye!\n");
            break;
        }

        // Receives the result from the server
        read(sock, &result, sizeof(double));
        printf("Result: %lf\n", result);

        // Clearing the buffer
        memset(expression, 0, sizeof(expression));
    }

    // Closing the socket
    close(sock);
    return 0;
}