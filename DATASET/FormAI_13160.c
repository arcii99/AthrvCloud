//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <time.h>

#define MAX_CONNECTIONS 10
#define PACKET_SIZE 1024
#define MAX_LATENCY 50 // in ms
#define MAX_BANDWIDTH 1024 // in Kbps

bool stop_threads = false;

struct Connection {
    int socket_fd;
    int packet_loss_count;
    int packets_received;
    int packets_sent;
    struct sockaddr_in address;
};

struct NetworkStats {
    float latency;
    float bandwidth;
    int packet_loss;
};

void signal_handler(int signal_number) {
    printf("\nStopping threads...\n");
    stop_threads = true;
}

void* server_thread(void* params) {
    struct Connection* connections = (struct Connection*) params;

    // Create server socket
    int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1) {
        perror("Error creating server socket!\n");
        exit(EXIT_FAILURE);
    }

    // Bind socket to local address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);
    if (bind(server_socket_fd, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket to address!\n");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_socket_fd, MAX_CONNECTIONS) == -1) {
        perror("Error listening for connections!\n");
        exit(EXIT_FAILURE);
    }

    printf("Server is up and listening for connections on port 8080...\n");

    while (!stop_threads) {
        // Accept incoming connection
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket_fd = accept(server_socket_fd, (struct sockaddr*) &client_address, &client_address_length);
        if (client_socket_fd == -1) {
            perror("Error accepting incoming connection!\n");
            continue;
        }

        printf("New client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Add the new connection to the list of connections
        int i;
        for (i = 0; i < MAX_CONNECTIONS; i++) {
            if (connections[i].socket_fd == 0) {
                connections[i].socket_fd = client_socket_fd;
                connections[i].packets_received = 0;
                connections[i].packets_sent = 0;
                connections[i].packet_loss_count = 0;
                connections[i].address = client_address;
                break;
            }
        }

        if (i == MAX_CONNECTIONS) {
            printf("Maximum connections reached, dropping incoming connection...\n");
            close(client_socket_fd);
        }
    }

    // Close server socket
    close(server_socket_fd);

    return NULL;
}

void* client_thread(void* params) {
    struct Connection* connection = (struct Connection*) params;
    char buffer[PACKET_SIZE];
    struct timespec start_time, end_time;
    int bytes_sent;
    int bytes_received;

    while (!stop_threads) {
        // Send a packet to the server
        clock_gettime(CLOCK_REALTIME, &start_time);
        bytes_sent = send(connection->socket_fd, buffer, PACKET_SIZE, 0);
        if (bytes_sent == -1) {
            perror("Error sending packet to server!\n");
            break;
        }
        connection->packets_sent++;

        // Receive a packet from the server
        bytes_received = recv(connection->socket_fd, buffer, PACKET_SIZE, 0);
        if (bytes_received == -1) {
            perror("Error receiving packet from server!\n");
            break;
        }
        clock_gettime(CLOCK_REALTIME, &end_time);
        connection->packets_received++;

        // Calculate latency
        float latency = (end_time.tv_sec - start_time.tv_sec) * 1000;
        latency += (float) (end_time.tv_nsec - start_time.tv_nsec) / 1000000;
        if (latency > MAX_LATENCY) {
            printf("High latency detected from %s:%d: %.2f ms\n", inet_ntoa(connection->address.sin_addr), ntohs(connection->address.sin_port), latency);
        }

        // Calculate packet loss
        if (bytes_received == 0) {
            connection->packet_loss_count++;
        }
        else {
            connection->packet_loss_count = 0;
        }

        if (connection->packet_loss_count > 5) {
            printf("Packet loss detected from %s:%d\n", inet_ntoa(connection->address.sin_addr), ntohs(connection->address.sin_port));
        }

        // Sleep for a while to simulate network latency
        usleep(MAX_LATENCY * 1000);
    }

    close(connection->socket_fd);
    connection->socket_fd = 0;

    return NULL;
}

int main() {
    // Initialize random seed for bandwidth simulation
    srand(time(NULL));

    // Initialize connections list
    struct Connection connections[MAX_CONNECTIONS];
    int i;
    for (i = 0; i < MAX_CONNECTIONS; i++) {
        connections[i].socket_fd = 0;
    }

    // Setup signal handler
    signal(SIGINT, signal_handler);

    // Create server thread
    pthread_t server_thread_id;
    if (pthread_create(&server_thread_id, NULL, server_thread, (void*) connections) != 0) {
        perror("Error creating server thread!\n");
        exit(EXIT_FAILURE);
    }

    // Create client threads
    pthread_t client_thread_ids[MAX_CONNECTIONS];
    for (i = 0; i < MAX_CONNECTIONS; i++) {
        if (pthread_create(&client_thread_ids[i], NULL, client_thread, (void*) &connections[i]) != 0) {
            perror("Error creating client thread!\n");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for threads to finish
    pthread_join(server_thread_id, NULL);
    for (i = 0; i < MAX_CONNECTIONS; i++) {
        if (connections[i].socket_fd != 0) {
            pthread_join(client_thread_ids[i], NULL);
        }
    }

    return 0;
}