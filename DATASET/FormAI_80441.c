//FormAI DATASET v1.0 Category: Chat server ; Style: intelligent
/* This is a Chat server program created by an intelligent chatbot.
 * This program allows multiple clients to connect and chat through the server.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS] = {0}; // Initialize array to hold client socket file descriptors

int main(int argc, char const *argv[]) {

  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[BUFFER_SIZE] = {0};
  char *welcome_message = "Welcome to the Chat Server!";

  // Creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("ERROR: Could not create socket");
    exit(EXIT_FAILURE);
  }

  // Set socket options to allow multiple connections & reuse the same address
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("ERROR: Could not set socket options");
    exit(EXIT_FAILURE);
  }

  // Set server address properties
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // Bind the socket to the server address
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("ERROR: Could not bind socket to address");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(server_fd, MAX_CLIENTS) < 0) {
    perror("ERROR: Could not listen for incoming connections");
    exit(EXIT_FAILURE);
  }

  while(1) { // Server runs forever until manually stopped

    // Wait for incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
      perror("ERROR: Could not accept incoming connection");
      exit(EXIT_FAILURE);
    }

    // Welcome new client with a message
    send(new_socket, welcome_message, strlen(welcome_message), 0);

    // Add new client file descriptor to clients array
    for (int i = 0; i < MAX_CLIENTS; i++) {
      if (clients[i] == 0) {
        clients[i] = new_socket;
        printf("New client connected: %d\n", new_socket);
        break;
      }
    }

    // Send message to other clients that a new client has connected
    char *new_client_message = "A new client has joined the chat room.";
    for (int i = 0; i < MAX_CLIENTS; i++) {
      if (clients[i] != new_socket && clients[i] != 0) {
        send(clients[i], new_client_message, strlen(new_client_message), 0);
      }
    }

    // Read incoming messages from client and broadcast to other clients
    while (1) {
      valread = read(new_socket, buffer, BUFFER_SIZE);
      if (valread <= 0) { // Client disconnected
        // Remove client from clients array
        for (int i = 0; i < MAX_CLIENTS; i++) {
          if (clients[i] == new_socket) {
            clients[i] = 0;
            printf("Client disconnected: %d\n", new_socket);
            break;
          }
        }
        // Send message to other clients that a client has disconnected
        char *client_disconnect_message = "A client has left the chat room.";
        for (int i = 0; i < MAX_CLIENTS; i++) {
          if (clients[i] != new_socket && clients[i] != 0) {
            send(clients[i], client_disconnect_message, strlen(client_disconnect_message), 0);
          }
        }
        break; // Exit loop and wait for next connection
      } else { // Broadcast message to other clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
          if (clients[i] != new_socket && clients[i] != 0) {
            send(clients[i], buffer, strlen(buffer), 0);
          }
        }
      }
      memset(buffer, 0, BUFFER_SIZE); // Clear buffer for next message
    }

    close(new_socket); // Close connection with client

  }

  return 0;
}