//FormAI DATASET v1.0 Category: Simple Web Server ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define RESPONSE_HEADER "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"

int main(int argc, char const *argv[]) {

  // Create socket file descriptor
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == -1) {
    perror("Failed to create socket");
    exit(EXIT_FAILURE);
  }

  // Set socket options and bind to address
  int optval = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
    perror("Failed to set socket options");
    exit(EXIT_FAILURE);
  }
  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) == -1) {
    perror("Failed to bind socket");
    exit(EXIT_FAILURE);
  }
  
  // Listen for incoming connections
  if (listen(server_fd, 10) == -1) {
    perror("Failed to listen for connections");
    exit(EXIT_FAILURE);
  }
  
  // Handle connections
  while (1) {
    struct sockaddr_in client_address;
    int client_fd, request_length;
    char buffer[1024];
    
    // Accept incoming connection
    socklen_t client_address_length = sizeof(client_address);
    client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_length);
    if (client_fd == -1) {
      perror("Failed to accept connection");
      exit(EXIT_FAILURE);
    }
    
    // Read HTTP request
    request_length = read(client_fd, buffer, 1024);
    if (request_length <= 0) continue;
    buffer[request_length] = '\0';
    
    // Send HTTP response
    write(client_fd, RESPONSE_HEADER, strlen(RESPONSE_HEADER));
    write(client_fd, "<html><body><h1>Hello World!</h1></body></html>", 46);
    
    // Close connection
    close(client_fd);
  }
  
  // Close server socket
  close(server_fd);
  return 0;
}