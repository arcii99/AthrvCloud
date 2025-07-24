//FormAI DATASET v1.0 Category: Chat server ; Style: Romeo and Juliet
// Romeo and Juliet Chat Server Program
// By: [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Function to remove newline character from a string
void remove_newline(char* str) {
    int length = strlen(str);
    if (str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}

//struct to hold the client information
struct client_info {
    int client_sockfd;
    struct sockaddr_in client_addr;
};

//array to hold the client information
struct client_info clients[MAX_CLIENTS];

//mutex to synchronize access to clients array from main and client threads
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

//function for handling client connections
void* handle_client(void* arg) {
    int client_sockfd = *(int*)arg;
    char buffer[BUFFER_SIZE];

    //let the client know that they have been connected
    snprintf(buffer, BUFFER_SIZE, "Welcome to the Chat Server! Please type your name: ");
    send(client_sockfd, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);

    //get the client name
    int name_length = recv(client_sockfd, buffer, BUFFER_SIZE, 0);
    if (name_length == 0) {
        close(client_sockfd);
        pthread_exit(NULL);
    }
    char client_name[BUFFER_SIZE];
    strcpy(client_name, buffer);
    remove_newline(client_name);

    //let all other clients know that a new client has joined
    snprintf(buffer, BUFFER_SIZE, ">>> %s has joined the chat\n", client_name);
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].client_sockfd != 0 && clients[i].client_sockfd != client_sockfd) {
            send(clients[i].client_sockfd, buffer, strlen(buffer), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);

    //start the chat
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int message_length = recv(client_sockfd, buffer, BUFFER_SIZE, 0);
        if (message_length == 0) {
            //if the client disconnected, let all other clients know
            snprintf(buffer, BUFFER_SIZE, ">>> %s has left the chat\n", client_name);
            pthread_mutex_lock(&clients_mutex);
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i].client_sockfd != 0 && clients[i].client_sockfd != client_sockfd) {
                    send(clients[i].client_sockfd, buffer, strlen(buffer), 0);
                }
            }
            pthread_mutex_unlock(&clients_mutex);
            break;
        }
        //otherwise, broadcast the message to all other clients
        remove_newline(buffer);
        snprintf(buffer, BUFFER_SIZE, "%s: %s\n", client_name, buffer);
        pthread_mutex_lock(&clients_mutex);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].client_sockfd != 0 && clients[i].client_sockfd != client_sockfd) {
                send(clients[i].client_sockfd, buffer, strlen(buffer), 0);
            }
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    //close the client socket and exit the thread
    close(client_sockfd);
    pthread_exit(NULL);
}

int main(int argc, char** argv) {
    //initialize the server socket
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        printf("Error creating server socket\n");
        return -1;
    }
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8888);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    //bind the server socket to the address and port
    if (bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding server socket\n");
        close(server_sockfd);
        return -1;
    }

    //listen for client connections
    if (listen(server_sockfd, MAX_CLIENTS) == -1) {
        printf("Error listening for client connections\n");
        close(server_sockfd);
        return -1;
    }

    //initialize the client socket array
    for (int i = 0; i < MAX_CLIENTS; i++) {
        clients[i].client_sockfd = 0;
    }

    //accept client connections and handle them in new threads
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_size = sizeof(client_addr);
        int client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_addr, &client_addr_size);
        if (client_sockfd == -1) {
            printf("Error accepting client connection\n");
            continue;
        }

        //find an empty slot in the client socket array
        pthread_mutex_lock(&clients_mutex);
        int i;
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].client_sockfd == 0) {
                clients[i].client_sockfd = client_sockfd;
                clients[i].client_addr = client_addr;
                pthread_t client_thread;
                if (pthread_create(&client_thread, NULL, handle_client, (void*)&clients[i].client_sockfd) != 0) {
                    printf("Error creating client thread\n");
                    close(client_sockfd);
                }
                break;
            }
        }
        if (i == MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            close(client_sockfd);
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    close(server_sockfd);

    return 0;
}