//FormAI DATASET v1.0 Category: Networking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // initialize socket
    int socket_fd;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER_SIZE];

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error: Could Not Create Socket.\n");
        exit(1);
    }
    printf("Socket Created Successfully.\n");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        printf("Error: Invalid Address.\n");
        exit(1);
    }

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Connection Failed.\n");
        exit(1);
    }
    printf("Connected to Server Successfully.\n");

    // get user input and send to server
    while (1) {
        printf("Enter a Message (type 'exit' to quit): ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);

        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }

        if (send(socket_fd, buffer, strlen(buffer), 0) < 0) {
            printf("Error: Message Failed to Send.\n");
            exit(1);
        }

        printf("Message Sent Successfully.\n");
    }

    close(socket_fd);
    printf("Socket Closed Successfully.\n");

    return 0;
}