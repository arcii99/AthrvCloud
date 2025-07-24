//FormAI DATASET v1.0 Category: Simple Web Server ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CONNECTIONS 10

char* response = "<html><head><title>Welcome to my Web Server</title></head><body><h1>Hello World!</h1></body></html>";

int main() {
  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};

  // Create socket file descriptor
  server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == 0) {
    fprintf(stderr, "Socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Set socket options
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    fprintf(stderr, "Setsockopt failed");
    exit(EXIT_FAILURE);
  }

  // Set address info
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons( PORT );

  // Bind socket to address
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    fprintf(stderr, "Binding failed");
    exit(EXIT_FAILURE);
  }
  
  // Listen for connections
  if (listen(server_fd, MAX_CONNECTIONS) < 0) {
    fprintf(stderr, "Listen failed");
    exit(EXIT_FAILURE);
  }

  // Accept incoming connections
  while(1) {
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
      fprintf(stderr, "Accept failed");
      exit(EXIT_FAILURE);
    }
    printf("Connection accepted\n");

    // Read request from client
    valread = read( new_socket , buffer, 1024);
    printf("%s\n",buffer );

    // Write response to client
    send(new_socket , response , strlen(response) , 0 );
    printf("Response sent\n");
    close(new_socket);
  }

  return 0;
}