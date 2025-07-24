//FormAI DATASET v1.0 Category: Client Server Application ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

void *handleClient(void *arg);

int main(int argc, char *argv[]) {

    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char *welcomeMessage = "Welcome to the Mind-Bending Server!\n";
    char buffer[1024] = {0};
    pthread_t thread;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // Binding to the specified port
    if (bind(server_fd, (struct sockaddr *) &address,
             sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started listening on port %d\n", ntohs(address.sin_port));

    while (1) {
        if ((new_socket = accept(server_fd, (struct sockaddr *) &address,
                                 (socklen_t *) &addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New client connected from %s:%d\n",
               inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Send the welcome message to the client
        send(new_socket, welcomeMessage, strlen(welcomeMessage), 0);

        // Create a new thread to handle the client
        if (pthread_create(&thread, NULL, handleClient, (void *) &new_socket) < 0) {
            perror("could not create thread");
            exit(EXIT_FAILURE);
        }
    }

}

void *handleClient(void *arg) {
    int socket = *(int *) arg;
    char buffer[1024] = {0};

    while (1) {
        // Read input from the client
        int bytesRead = read(socket, buffer, 1024);

        if (bytesRead < 0) {
            perror("could not read from client");
            exit(EXIT_FAILURE);
        } else if (bytesRead == 0) {
            printf("Client disconnected\n");
            break;
        } else {
            // Process input and send back response
            printf("Received %d bytes from the client: %s\n", bytesRead, buffer);
            printf("Sending a mind-bending response...\n");

            char response[1024];
            sprintf(response, "The answer is %d\n", (int) (rand() % 100));
            send(socket, response, strlen(response), 0);

            memset(buffer, 0, 1024);
        }
    }

    close(socket);
    pthread_exit(NULL);
}