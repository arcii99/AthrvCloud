//FormAI DATASET v1.0 Category: System administration ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_MSG_LEN 1024

int main(int argc, char *argv[]) {
    int my_socket, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_MSG_LEN] = {0};

    // Create socket file descriptor
    if ((my_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Attach socket to port 8080
    if (setsockopt(my_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to given port
    if (bind(my_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen to incoming connections
    if (listen(my_socket, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept a new connection and display IP address of the client
    if ((new_socket = accept(my_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    printf("New connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

    // Execute system command sent by the client
    while (1) {
        memset(buffer, 0, MAX_MSG_LEN);
        if (read(new_socket , buffer, MAX_MSG_LEN) == 0) {
            printf("Client %s:%d disconnected.\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
            break;
        }
        printf("Client %s:%d > %s", inet_ntoa(address.sin_addr), ntohs(address.sin_port), buffer);

        if (strcmp(buffer, "exit\n") == 0) {
            printf("Client %s:%d disconnected.\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
            break;
        }
        else {
            char cmd_output[MAX_MSG_LEN] = {0};
            FILE *fp = popen(buffer, "r");
            while (fgets(cmd_output, MAX_MSG_LEN, fp) != NULL) {
                send(new_socket, cmd_output, strlen(cmd_output), 0);
            }
            pclose(fp);
        }
    }
    close(new_socket);
    close(my_socket);
    return 0;
}