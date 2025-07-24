//FormAI DATASET v1.0 Category: Chat server ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 5000 //set the server port
#define MAX_CLIENTS 10 //maximum number of clients

void *client_handler(void *arg); //function handler for client connections

int main(int argc, char *argv[]) {

    int server_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    pthread_t tid[MAX_CLIENTS];
    char *message = "Connected"; //reply message to clients

    //Create socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        perror("Error: Failed to create socket");
        exit(EXIT_FAILURE);
    }
    printf("Server socket created successfully!\n");

    //Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    //Bind the socket to address and port
    if (bind(server_sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error: Failed to bind socket");
        exit(EXIT_FAILURE);
    }
    printf("Socket binded successfully!\n");

    //Listen for incoming connections
    if (listen(server_sockfd, MAX_CLIENTS) == -1) {
        perror("Error: Failed to listen");
        exit(EXIT_FAILURE);
    }
    printf("Waiting for incoming connections...\n");

    int client_count = 0;
    while (true) {
        socklen_t client_size = sizeof(client_addr);
        //Accept incoming connections
        client_sockfd = accept(server_sockfd, (struct sockaddr *) &client_addr, &client_size);
        if (client_sockfd == -1) {
            perror("Error: Failed to accept client connection");
            exit(EXIT_FAILURE);
        }
        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        //create thread for each connected client
        if (pthread_create(&tid[client_count], NULL, client_handler, (void *) &client_sockfd) != 0) {
            perror("Error: Failed to create thread");
        }

        //Reply to client with welcome message
        printf("%s\n", message);
        if (send(client_sockfd, message, strlen(message), 0) == -1) {
            perror("Error: Failed to send message to client");
            exit(EXIT_FAILURE);
        }
        client_count++;
    }
    close(server_sockfd);
    return 0;
}

void *client_handler(void *arg) {
    int client_sockfd = *(int *) arg;
    char buffer[1024];
    int read_size;

    while ((read_size = recv(client_sockfd, buffer, 1024, 0)) > 0) {
        printf("Message received from client: %s\n", buffer);
        if (send(client_sockfd, buffer, strlen(buffer), 0) == -1) {
            perror("Error: Failed to send message to client");
            exit(EXIT_FAILURE);
        }
        memset(buffer, 0, 1024); //reset buffer after each message
    }
    if (read_size == 0) {
        printf("Client disconnected\n");
        fflush(stdout);
    } else if (read_size == -1) {
        perror("Error: Failed to receive message from client");
    }
    close(client_sockfd);
    pthread_exit(NULL);
}