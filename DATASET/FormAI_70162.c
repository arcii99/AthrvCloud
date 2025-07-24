//FormAI DATASET v1.0 Category: Networking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080

int main() {
  int server_fd;
  struct sockaddr_in address;
  char buffer[1024] = {0};
  const char* message = "Hello from the server!";
  
  // Create server socket
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }
  
  // Initialize address
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);
  
  // Bind socket to address
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("Bind failed");
    exit(EXIT_FAILURE);
  }
  
  // Listen for incoming connections
  if (listen(server_fd, 3) < 0) {
    perror("Listen failed");
    exit(EXIT_FAILURE);
  }
  
  // Accept incoming connection request
  int client_fd;
  int addrlen = sizeof(address);
  if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
    perror("Accept failed");
    exit(EXIT_FAILURE);
  }
  
  // Send message to client
  send(client_fd, message, strlen(message), 0);
  printf("Message sent to client\n");
  
  // Receive message from client
  int length;
  if ((length = read(client_fd, buffer, 1024)) > 0) {
    printf("Message received from client: %s\n", buffer);
  }
  
  // Close sockets
  close(client_fd);
  close(server_fd);
  
  return 0;
}