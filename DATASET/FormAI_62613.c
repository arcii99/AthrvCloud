//FormAI DATASET v1.0 Category: Socket programming ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024
#define PORT 8080

int main(int argc, char *argv[]) {

    int server_socket_fd, new_socket_fd, client_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_BUFFER_SIZE] = {0};
    pid_t pid;

    // Create a socket for the server
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the server address to the socket
    if (bind(server_socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket_fd, 5) < 0)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections
    while(1) {
        client_len = sizeof(client_addr);
        if ((new_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_addr, &client_len))<0)
        {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // Create a new process for each incoming connection
        if ((pid = fork()) < 0) {
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) {
            // Child process
            close(server_socket_fd);

            // Read data from the client
            read(new_socket_fd, buffer, sizeof(buffer));
            printf("Received message: %s\n", buffer);

            // Reverse the message
            int len = strlen(buffer);
            char* reverse = (char*)malloc(len+1);
            for (int i = 0; i < len; i++) {
                reverse[len-i-1] = buffer[i];
            }
            reverse[len] = '\0';

            // Send the reversed message back to the client
            send(new_socket_fd, reverse, strlen(reverse), 0);
            free(reverse);

            // Close the socket and exit the child process
            close(new_socket_fd);
            exit(0);
        }
        else {
            // Parent process
            close(new_socket_fd);
        }
    }

    return 0;
}