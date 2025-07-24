//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PROXY_PORT 8080
#define BUFFER_SIZE 4096

// Function to handle a client request
void handle_request(int client_sock, struct sockaddr_in* dest_addr) {
  // Create a new socket to connect to the destination server
  int dest_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (dest_sock < 0) {
    perror("Failed to create socket for destination server");
    close(client_sock);
    return;
  }

  // Connect to the destination server
  if (connect(dest_sock, (struct sockaddr*) dest_addr, sizeof(*dest_addr)) < 0) {
    perror("Failed to connect to destination server");
    close(client_sock);
    close(dest_sock);
    return;
  }

  // Create a buffer to store the request
  char buffer[BUFFER_SIZE] = {0};

  // Receive the request from the client
  int bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0);
  if (bytes_received < 0) {
    perror("Failed to receive request from client");
    close(client_sock);
    close(dest_sock);
    return;
  }

  // Forward the request to the destination server
  int bytes_sent = send(dest_sock, buffer, bytes_received, 0);
  if (bytes_sent < 0) {
    perror("Failed to forward request to destination server");
    close(client_sock);
    close(dest_sock);
    return;
  }

  // Receive the response from the destination server
  bytes_received = recv(dest_sock, buffer, BUFFER_SIZE, 0);
  if (bytes_received < 0) {
    perror("Failed to receive response from destination server");
    close(client_sock);
    close(dest_sock);
    return;
  }

  // Forward the response to the client
  bytes_sent = send(client_sock, buffer, bytes_received, 0);
  if (bytes_sent < 0) {
    perror("Failed to forward response to client");
    close(client_sock);
    close(dest_sock);
    return;
  }

  // Close the sockets
  close(client_sock);
  close(dest_sock);
}

int main() {
  // Create a socket to listen for incoming connections
  int server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0) {
    perror("Failed to create socket for server");
    exit(EXIT_FAILURE);
  }

  // Bind the server socket to the port
  struct sockaddr_in server_addr = {0};
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(PROXY_PORT);
  if (bind(server_sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
    perror("Failed to bind server socket");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(server_sock, 5) < 0) {
    perror("Failed to listen for incoming connections");
    exit(EXIT_FAILURE);
  }

  printf("HTTP proxy server started on port %d\n", PROXY_PORT);

  // Accept incoming connections and handle them asynchronously
  while (true) {
    // Accept a new client connection
    struct sockaddr_in client_addr = {0};
    socklen_t client_addr_len = sizeof(client_addr);
    int client_sock = accept(server_sock, (struct sockaddr*) &client_addr, &client_addr_len);
    if (client_sock < 0) {
      perror("Failed to accept incoming connection");
      continue;
    }

    // Spawn a new thread to handle the client request
    handle_request(client_sock, &client_addr);
  }

  // Close the server socket
  close(server_sock);

  return EXIT_SUCCESS;
}