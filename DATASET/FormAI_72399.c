//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int client_socket, server_socket;
  struct sockaddr_in client_addr, server_addr;
  char buffer[4096];

  // Create the client socket
  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket < 0) {
    perror("Failed to create socket");
    exit(1);
  }

  // Bind to the local address
  memset(&client_addr, 0, sizeof(client_addr));
  client_addr.sin_family = AF_INET;
  client_addr.sin_addr.s_addr = INADDR_ANY;
  client_addr.sin_port = htons(8080);
  if (bind(client_socket, (struct sockaddr*)&client_addr, sizeof(client_addr)) < 0) {
    perror("Failed to bind socket");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(client_socket, 10) < 0) {
    perror("Failed to listen for connections");
    exit(1);
  }

  printf("Server is running on port %d\n", 8080);

  while (1) {
    // Accept a connection from a client
    socklen_t client_len = sizeof(client_addr);
    int client = accept(client_socket, (struct sockaddr *)&client_addr, &client_len);
    if (client < 0) {
      perror("Failed to accept connection from client");
      continue;
    }

    // Read the client's request
    memset(buffer, 0, sizeof(buffer));
    int n = recv(client, buffer, sizeof(buffer), 0);
    if (n < 0) {
      perror("Failed to read from client");
      close(client);
      continue;
    }

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
      perror("Failed to create socket");
      close(client);
      continue;
    }

    // Connect to the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.1"); // Change this to the IP address of your server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      perror("Failed to connect to server");
      close(client);
      continue;
    }

    // Forward the client's request to the server
    if (send(server_socket, buffer, strlen(buffer), 0) < 0) {
      perror("Failed to send request to server");
      close(client);
      close(server_socket);
      continue;
    }

    // Read the server's response
    memset(buffer, 0, sizeof(buffer));
    while ((n = recv(server_socket, buffer, sizeof(buffer), 0)) > 0) {
      // Forward the server's response to the client
      if (send(client, buffer, n, 0) < 0) {
        perror("Failed to send response to client");
        close(client);
        close(server_socket);
        break;
      }
      memset(buffer, 0, sizeof(buffer));
    }

    // Close the client and server sockets
    close(client);
    close(server_socket);
  }

  return 0;
}