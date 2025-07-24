//FormAI DATASET v1.0 Category: Temperature monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 5000
#define MAX_BUFFER_SIZE 1024

pthread_mutex_t lock;
int temperature = 25;

void* start_client(void* arg) {
    char buffer[MAX_BUFFER_SIZE];
    int client_socket = *(int*) arg;

    while(1) {
        bzero(buffer, sizeof(buffer));
        int n = read(client_socket, buffer, sizeof(buffer));
        if(n <= 0) {
            break;
        }

        if(buffer[0] == 'G') {
            pthread_mutex_lock(&lock);
            int temp = temperature;
            pthread_mutex_unlock(&lock);
            sprintf(buffer, "%d", temp);
            write(client_socket, buffer, sizeof(buffer));
        }

        if(buffer[0] == 'S') {
            int temp = atoi(&buffer[1]);
            pthread_mutex_lock(&lock);
            temperature = temp;
            pthread_mutex_unlock(&lock);
            sprintf(buffer, "Temperature set to %d", temp);
            write(client_socket, buffer, sizeof(buffer));
        }
    }

    close(client_socket);
    return NULL;
}

int start_server() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_length = sizeof(client_address);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set server address
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind server to address
    if(bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Binding failed");
        exit(1);
    }

    // Start listening for clients
    if(listen(server_socket, 5) < 0) {
        perror("Listening failed");
        exit(1);
    }

    printf("Server running...\n");

    while(1) {
        // Accept incoming client connection
        client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_length);
        if(client_socket < 0) {
            perror("Client connection failed");
            continue;
        }

        printf("Client connected: %s\n", inet_ntoa(client_address.sin_addr));

        // Start client communication in a separate thread
        pthread_t client_thread;
        if(pthread_create(&client_thread, NULL, start_client, &client_socket)) {
            perror("Failed to create client thread");
            close(client_socket);
        }
        pthread_detach(client_thread);
    }

    close(server_socket);
    return 0;
}

int main() {
    pthread_mutex_init(&lock, NULL);
    return start_server();
}