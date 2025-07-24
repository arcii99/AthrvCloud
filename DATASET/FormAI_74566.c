//FormAI DATASET v1.0 Category: Networking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 6969
#define BACKLOG 5
#define MSG_SIZE 100

int main() {

    printf("Welcome to Networking with Chatty, the friendliest chatbot on the internet!\n");
    printf("Let's create a server to receive messages from our clients.\n");

    struct sockaddr_in server_addr, client_addr;
    int server_fd, client_fd;
    socklen_t client_len;
    char buffer[MSG_SIZE];

    // First we create the socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Oopsie, something went wrong when trying to create the socket.\n");
        printf("Here is the error message: %m\n");
        exit(EXIT_FAILURE);
    }

    // Now we define the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    // Time to bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Whoopsie daisy, something went wrong during the bind process.\n");
        printf("Here is the error message: %m\n");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Now we listen for incoming connections
    if (listen(server_fd, BACKLOG) == -1) {
        printf("Oh no, we couldn't listen to incoming connections.\n");
        printf("Here is the error message: %m\n");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Sweet, our server is up and running!\n");
    printf("Waiting for clients to connect...\n");

    // Time to accept a client connection
    client_len = sizeof(client_addr);

    if ((client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_len)) == -1) {
        printf("Uh oh, we couldn't accept the client connection.\n");
        printf("Here is the error message: %m\n");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Yay, we have a client!\n");
    printf("Let's start chatting!\n");

    while (1) {
        // First we receive a message from the client
        memset(&buffer, 0, sizeof(buffer));
        recv(client_fd, buffer, MSG_SIZE, 0);

        printf("Client: %s", buffer);

        // Now we prepare our message to send back
        char response[MSG_SIZE] = "Haha! That's hilarious, ";

        // We will take the first word of the client's message
        char *token = strtok(buffer, " ");
        strcat(response, token);

        // Now we add a fun response
        strcat(response, "! You crack me up!");

        // And send it back to the client
        send(client_fd, response, strlen(response) + 1, 0);
    }

    // We clean up after ourselves
    close(client_fd);
    close(server_fd);

    return(EXIT_SUCCESS);
}