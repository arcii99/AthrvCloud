//FormAI DATASET v1.0 Category: Networking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main() {
  int server_sock, client_sock, valread;
  struct sockaddr_in server_addr, client_addr;
  char buffer[BUFFER_SIZE] = {0};
  int addrlen = sizeof(client_addr);

  // Create server socket
  if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Set server socket options
  int opt = 1;
  if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("Setsockopt failed");
    exit(EXIT_FAILURE);
  }
  
  // Set server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(SERVER_PORT);

  // Bind server socket
  if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(server_sock, 3) < 0) {
    perror("Listen failed");
    exit(EXIT_FAILURE);
  }

  printf("Server listening on port %d\n", SERVER_PORT);

  // Accept incoming connections
  if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
    perror("Accept failed");
    exit(EXIT_FAILURE);
  }

  printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

  // Read data from client
  valread = read(client_sock, buffer, BUFFER_SIZE);
  printf("Received data: %s\n", buffer);

  // Send response to client
  char* response = "Hello, client!";
  send(client_sock, response, strlen(response), 0);
  printf("Response sent to client: %s\n", response);

  // Clean up
  close(client_sock);
  close(server_sock);
  printf("Server shutdown\n");

  return 0;
}