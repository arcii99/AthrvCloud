//FormAI DATASET v1.0 Category: Temperature monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CONNECTIONS 10

// Initialize mutex lock for threads
pthread_mutex_t lock;

// Method to generate random temperature readings
float generate_temperature() {
    float temp = (rand() % 100)/10.0;
    return temp;
}

// Method to handle client connections
void *handle_client(void *arg) {
    int client_socket = *(int*)arg;
    char buffer[BUFFER_SIZE];
    while(1) {
        // Generate random temperature reading
        float temperature_reading = generate_temperature();
        sprintf(buffer, "%.1f", temperature_reading);
        // Send temperature reading to client
        send(client_socket, buffer, strlen(buffer), 0);
        sleep(5);
    }
    close(client_socket);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    // Seed the random number generator
    srand(time(NULL));

    int server_socket, client_socket, opt = 1;
    struct sockaddr_in address;
    int address_length = sizeof(address);

    // Create TCP socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Set socket options
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    // Set address parameters
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address and port
    bind(server_socket, (struct sockaddr *)&address, sizeof(address));

    // Listen for incoming connections
    listen(server_socket, MAX_CONNECTIONS);

    printf("Temperature monitor server running on port %d\n", PORT);

    pthread_t thread_id[MAX_CONNECTIONS];
    int connection_count = 0;
    // Accept incoming connections
    while (1) {
        // Accept client connection
        client_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&address_length);

        if (client_socket < 0) {
            perror("Error accepting client connection");
            exit(EXIT_FAILURE);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Lock mutex before creating thread
        pthread_mutex_lock(&lock);

        // Create new thread to handle client connection
        pthread_create(&thread_id[connection_count], NULL, handle_client, (void*)&client_socket);
        connection_count++;

        // Unlock mutex after thread created
        pthread_mutex_unlock(&lock);
    }
    return 0;
}