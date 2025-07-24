//FormAI DATASET v1.0 Category: Client Server Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main(int argc, char const *argv[]) {
    int sockfd, new_sockfd, len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    pid_t childpid;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failure");
        exit(EXIT_FAILURE);
    }

    // Assigning IP and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    // Listening
    if (listen(sockfd, 5) < 0) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    len = sizeof(client_addr);

    printf("Server is up and running!\n");

    for (;;) {
        new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &len);

        if (new_sockfd < 0) {
            perror("Accept error");
            exit(EXIT_FAILURE);
        }

        // Creating child process
        if ((childpid = fork()) == 0) {
            close(sockfd);

            // Receiving message from client
            recv(new_sockfd, buffer, sizeof(buffer), 0);
            printf("Message received: %s\n", buffer);

            // Preparing response message
            char response[] = "Hello from the server!";

            // Sending response message to client
            send(new_sockfd, response, strlen(response), 0);

            // Closing socket
            close(new_sockfd);

            exit(EXIT_SUCCESS);
        }
        else {
            close(new_sockfd);
        }
    }

    return 0;
}