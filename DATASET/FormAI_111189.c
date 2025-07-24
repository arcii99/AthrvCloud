//FormAI DATASET v1.0 Category: Firewall ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <pthread.h>
#include <time.h>

// Define the maximum size of our buffer in which we will store incoming data
#define MAX_BUFFER_SIZE 1024

// Define the number of threads to be used in the server
#define NUM_THREADS 3

// Define the maximum number of client connections the server will accept
#define MAX_CLIENTS 10

// Define the port number on which the server will listen for incoming connections
#define PORT 8080

// Define the IP address of the server
#define SERVER_IP "127.0.0.1"

// Define the structure that will hold information about each client connection
typedef struct {
    int client_socket;
    struct sockaddr_in client_address;
} client_info;

// Declare global variables for the server socket and the list of client connections
int server_socket;
client_info client_list[MAX_CLIENTS];

// Declare functions for starting and stopping the server
void start_server();
void stop_server();

// Declare functions for handling client connections
void handle_client(void *arg);
void add_client(int client_socket, struct sockaddr_in client_address);
void remove_client(int client_socket);

int main() {
    // Start the server
    start_server();

    // Wait indefinitely for incoming client connections
    while (1) {}

    // Stop the server
    stop_server();

    return 0;
}

void start_server() {
    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create server socket");
        exit(1);
    }

    // Set socket options to allow reuse of the address and port
    int reuse = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
        perror("Failed to set socket options");
        exit(1);
    }

    // Bind the server socket to a port and IP address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr(SERVER_IP);
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind server socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Failed to listen for incoming connections");
        exit(1);
    }

    // Start multiple threads to handle client connections
    pthread_t thread_list[NUM_THREADS];
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&thread_list[i], NULL, (void *)handle_client, NULL) != 0) {
            perror("Failed to create thread for handling client connections");
            exit(1);
        }
    }

    printf("Server started and listening for incoming connections on port %d\n", PORT);
}

void stop_server() {
    // Close all client connections
    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (client_list[i].client_socket > 0) {
            close(client_list[i].client_socket);
        }
    }

    // Close the server socket
    close(server_socket);

    printf("Server stopped\n");
}

void handle_client(void *arg) {
    // Infinite loop to handle incoming client connections
    while (1) {
        // Look for an empty slot in the client connection list
        int i;
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (client_list[i].client_socket == 0) {
                break;
            }
        }

        // If all slots are taken, wait for a slot to become available
        if (i == MAX_CLIENTS) {
            continue;
        }

        // Accept an incoming client connection and add it to the list
        socklen_t client_address_length = sizeof(client_list[i].client_address);
        client_list[i].client_socket = accept(server_socket, (struct sockaddr *)&client_list[i].client_address, &client_address_length);
        if (client_list[i].client_socket < 0) {
            perror("Failed to accept incoming client connection");
            continue;
        }
        add_client(client_list[i].client_socket, client_list[i].client_address);

        // Receive incoming data from the client and echo back the same message
        char buffer[MAX_BUFFER_SIZE];
        while (recv(client_list[i].client_socket, buffer, MAX_BUFFER_SIZE, 0) > 0) {
            printf("Received message: %s", buffer);

            // Echo back the same message to the client
            send(client_list[i].client_socket, buffer, strlen(buffer), 0);
            printf("Echos back the same message to the client: %s", buffer);
            memset(buffer, 0, MAX_BUFFER_SIZE);
        }

        // If the client connection is closed, remove it from the list
        printf("Client connection closed\n");
        remove_client(client_list[i].client_socket);
        client_list[i].client_socket = 0;
    }
}

void add_client(int client_socket, struct sockaddr_in client_address) {
    // Print information about the new client connection
    char *client_ip = inet_ntoa(client_address.sin_addr);
    int client_port = ntohs(client_address.sin_port);
    printf("Accepted new client connection from %s:%d\n", client_ip, client_port);
}

void remove_client(int client_socket) {
    // Find the client connection in the list and remove it
    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (client_list[i].client_socket == client_socket) {
            client_list[i].client_socket = 0;
            break;
        }
    }
}