//FormAI DATASET v1.0 Category: Socket programming ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8888
#define MAX_CONNECTIONS 10

// Define buffer size for incoming messages
#define BUFFER_SIZE 1024

// Define a mutex to protect shared variables
pthread_mutex_t mutex;

// Define a struct to hold client information
struct client {
  int socket;
  struct sockaddr_in address;
  bool is_active;
};

// Define an array of client structs for tracking connections
struct client clients[MAX_CONNECTIONS];

// Initialize all client structs
void initialize_clients() {
  int i;
  for (i = 0; i < MAX_CONNECTIONS; i++) {
    clients[i].socket = -1;
    clients[i].is_active = false;
  }
}

// Add a new client to the client array
void add_client(int socket, struct sockaddr_in address) {
  int i;
  for (i = 0; i < MAX_CONNECTIONS; i++) {
    // If the slot is empty, add the client
    if (clients[i].socket == -1) {
      clients[i].socket = socket;
      clients[i].address = address;
      clients[i].is_active = true;
      break;
    }
  }
}

// Remove a client from the client array
void remove_client(int socket) {
  int i;
  for (i = 0; i < MAX_CONNECTIONS; i++) {
    if (clients[i].socket == socket) {
      clients[i].socket = -1;
      clients[i].is_active = false;
      break;
    }
  }
}

// Handle incoming messages from a client
void handle_client(int socket) {
  char buffer[BUFFER_SIZE];
  int bytes_received;

  // Receive messages and broadcast to all clients
  while (true) {
    bytes_received = recv(socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
      perror("Error receiving message");
      break;
    } else if (bytes_received == 0) {
      printf("Client disconnected\n");
      break;
    } else {
      // Lock the mutex to protect shared variables
      pthread_mutex_lock(&mutex);

      // Broadcast message to all active clients
      int i;
      for (i = 0; i < MAX_CONNECTIONS; i++) {
        if (clients[i].is_active && clients[i].socket != socket) {
          send(clients[i].socket, buffer, bytes_received, 0);
        }
      }

      // Unlock the mutex
      pthread_mutex_unlock(&mutex);
    }
  }

  // Close the socket and remove the client
  close(socket);
  remove_client(socket);
}

// Thread function for handling new client connections
void *connection_handler(void *socket_ptr) {
  int new_socket = *(int *) socket_ptr;

  // Add the new client to the client array
  add_client(new_socket, clients->address);

  // Handle messages from the client
  handle_client(new_socket);

  return 0;
}

int main(int argc, char const *argv[]) {
  int server_socket, new_socket;
  struct sockaddr_in address;
  int addr_len = sizeof(address);
  pthread_t thread_id;

  // Initialize clients array
  initialize_clients();

  // Create a server socket
  if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  // Bind the server socket to a port
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);
  if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("Error binding socket");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(server_socket, MAX_CONNECTIONS) < 0) {
    perror("Error listening for connections");
    exit(EXIT_FAILURE);
  }

  // Accept incoming connections and spawn a thread to handle each one
  while (true) {
    if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t *)&addr_len)) < 0) {
      perror("Error accepting connection");
      exit(EXIT_FAILURE);
    }

    if (pthread_create(&thread_id, NULL, connection_handler, &new_socket) < 0) {
      perror("Error creating thread");
      exit(EXIT_FAILURE);
    }
  }

  // Close the server socket
  close(server_socket);

  return 0;
}