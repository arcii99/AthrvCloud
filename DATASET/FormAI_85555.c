//FormAI DATASET v1.0 Category: System event logger ; Style: distributed
// A C System Event Logger Example Program in a Distributed Style

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_EVENTS 100

// Event structure
struct Event {
    char timestamp[50];
    char service_name[50];
    char message[100];
};

// Global variables
int clients[MAX_CLIENTS];
struct Event events[MAX_EVENTS];
int n_events = 0;

// Mutex lock for accessing events
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// Function to add a new event to events array
void add_event(char* service_name, char* message) {
    // Get current timestamp
    time_t curr_time;
    char timestamp[50];
    time(&curr_time);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&curr_time));

    // Create new event
    struct Event new_event;
    strcpy(new_event.timestamp, timestamp);
    strcpy(new_event.service_name, service_name);
    strcpy(new_event.message, message);

    // Add new event to events array
    pthread_mutex_lock(&lock);
    events[n_events++] = new_event;
    pthread_mutex_unlock(&lock);
}

// Function to send events to clients
void send_events(int client_socket) {
    char events_str[1000] = "";
    for (int i = 0; i < n_events; i++) {
        char event_str[200] = "";
        sprintf(event_str, "%s %s: %s\n", events[i].timestamp, events[i].service_name, events[i].message);
        strcat(events_str, event_str);
    }
    send(client_socket, events_str, strlen(events_str), 0);
}

// Function to handle client connections
void* handle_client(void* arg) {
    int client_socket = *(int *)arg;

    // Add new client to clients array
    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == 0) {
            clients[i] = client_socket;
            break;
        }
    }

    // Send events to new client
    send_events(client_socket);

    // Receive incoming messages
    char buffer[1024] = {0};
    while (1) {
        int valread = read(client_socket, buffer, 1024);
        if (valread == 0) {
            // Client disconnected
            clients[i] = 0;
            break;
        }
        // Add new event to events array
        add_event("Client", buffer);
        // Send updated events to all clients
        for (int j = 0; j < MAX_CLIENTS; j++) {
            if (clients[j] != 0 && clients[j] != client_socket) {
                send_events(clients[j]);
            }
        }
        memset(buffer, 0, sizeof(buffer));
    }

    // Close client socket
    close(client_socket);

    return NULL;
}

int main(int argc, char const *argv[]) {
    // Initialize clients array
    for (int i = 0; i < MAX_CLIENTS; i++) {
        clients[i] = 0;
    }

    // Create server socket
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections and create new thread to handle each client
    while (1) {
        int new_socket;
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, (void *)&new_socket)) {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
        pthread_detach(thread);
    }

    return 0;
}