//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define PORT 9999
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int server_fd, socket_fd;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE] = {0};

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt error");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connections...\n");

    int addrlen = sizeof(address);
    if ((socket_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
        perror("Accept error");
        exit(EXIT_FAILURE);
    }

    printf("Client connected with IP %s and port %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

    time_t current_time;
    int bytes_received;

    while(1) {
        bytes_received = read(socket_fd, buffer, BUFFER_SIZE);
        if (bytes_received < 0) {
            printf("Read error");
            exit(EXIT_FAILURE);
        } else if (bytes_received == 0) {
            printf("Client disconnected\n");
            break;
        } else {
            buffer[bytes_received] = '\0';
            current_time = time(NULL);
            printf("QoS: Network traffic at %s: %s", ctime(&current_time), buffer);
        }
    }

    close(socket_fd);
    close(server_fd);

    return 0;
}