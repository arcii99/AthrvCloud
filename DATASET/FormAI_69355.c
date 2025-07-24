//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int sockfd, new_sockfd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char response[1024] = {0};
    char *welcome_message = "Welcome to the Mathematical Server! Please enter a math problem to solve.\n";
    char *exit_message = "Goodbye!\n";

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // bind socket to localhost:8080
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // start listening for incoming connections
    if (listen(sockfd, 1) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // accept incoming connection
        new_sockfd = accept(sockfd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        if (new_sockfd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // send welcome message to client
        send(new_sockfd, welcome_message, strlen(welcome_message), 0);

        while (1) {
            // read client request
            memset(buffer, 0, sizeof(buffer));
            if (read(new_sockfd, buffer, 1024) == 0)
                break;

            // solve math problem
            int a, b, result;
            char operator;
            sscanf(buffer, "%d %c %d", &a, &operator, &b);
            switch (operator) {
                case '+':
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    if (b == 0) {
                        strcpy(response, "ERROR: Cannot divide by zero.\n");
                        goto send_response;
                    }
                    result = a / b;
                    break;
                default:
                    strcpy(response, "ERROR: Invalid operator entered.\n");
                    goto send_response;
            }
            sprintf(response, "RESULT: %d\n", result);

            // send response back to client
            send_response:
            send(new_sockfd, response, strlen(response), 0);
        }

        // send exit message to client and close connection
        send(new_sockfd, exit_message, strlen(exit_message), 0);
        close(new_sockfd);
    }

    return 0;
}