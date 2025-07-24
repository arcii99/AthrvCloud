//FormAI DATASET v1.0 Category: Simple Web Server ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  char buffer[1024] = {0};
  char *hello = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, World!</h1></body></html>";
  
  // Create socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Failed to create server socket");
    exit(1);
  }

  // Set server properties
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(8080);

  // Bind server socket to specified address and port
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("Failed to bind server socket");
    exit(1);
  }
  
  // Listen for incoming connections
  if (listen(server_fd, 3) < 0) {
    perror("Failed to listen for incoming connections");
    exit(1);
  }
  
  // Continuously accept incoming connections and parse HTTP requests
  while (1) {
    printf("Listening for incoming connections...\n");
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
      perror("Failed to accept incoming connection");
      exit(1);
    }
    printf("Accepted new connection\n");
    valread = read(new_socket, buffer, 1024);
    printf("Received request:\n%s\n", buffer);
    write(new_socket, hello, strlen(hello));
    printf("Response sent.\n");
    close(new_socket);
  }
  
  return 0;
}