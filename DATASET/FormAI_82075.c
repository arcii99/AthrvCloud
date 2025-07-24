//FormAI DATASET v1.0 Category: Client Server Application ; Style: multi-threaded
// This is an example program for a multi-threaded C client-server application
// In this program, the server will handle multiple client requests
// and communicate with each client through a separate thread

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 12345
#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 1024


void* handle_client(void* args){
    // This function will handle communication with each new client connection
    int client_socket = *(int*)args;
    char buffer[BUFFER_SIZE];
    bzero(buffer, BUFFER_SIZE);

    // Read incoming messages from the client
    while (1){
        int read_size = read(client_socket, buffer, BUFFER_SIZE);
        if (read_size == 0){
            printf("Client disconnected.\n");
            break;
        }
        // Echo the message back to the client
        write(client_socket, buffer, strlen(buffer));
        bzero(buffer, BUFFER_SIZE);
    }
    // Close the socket and exit the thread
    close(client_socket);
    pthread_exit(NULL);
}

int main(){
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_size = sizeof(client_address);
    pthread_t client_threads[MAX_CONNECTIONS];
    int thread_index = 0;

    // Create the socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1){
        printf("Error creating socket.\n");
        return 1;
    }
    printf("Socket created.\n");

    // Bind the socket to a port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1){
        printf("Error binding socket to port.\n");
        return 1;
    }
    printf("Socket bound to port %d.\n", PORT);

    // Listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) == -1){
        printf("Error listening for connections.\n");
        return 1;
    }
    printf("Listening for incoming connections...\n");

    // Accept incoming connections and handle them in a new thread
    while (1){
        client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_size);
        if (client_socket == -1){
            printf("Error accepting incoming connection.\n");
            continue;
        }
        printf("New client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Create new thread to handle client communication
        pthread_create(&client_threads[thread_index], NULL, handle_client, (void*)&client_socket);
        thread_index++;

        // Limit the number of concurrent threads
        if (thread_index == MAX_CONNECTIONS){
            for (int i=0; i<MAX_CONNECTIONS; i++){
                pthread_join(client_threads[i], NULL);
            }
            thread_index = 0;
        }
    }

    // Close the server socket
    close(server_socket);
    return 0;
}