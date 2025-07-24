//FormAI DATASET v1.0 Category: Simple Web Server ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {

  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[BUFFER_SIZE] = {0};
  char *hello = "HTTP/1.1 200 OK\nContent-Type: text/plain\nContent-Length: 12\n\nHello world!";

  // Create a socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
      perror("Socket creation failed");
      exit(EXIT_FAILURE);
  }

  // Set socket options
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
      perror("Setsockopt failed");
      exit(EXIT_FAILURE);
  }

  // Set IP and port
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // Bind the socket
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
      perror("Bind failed");
      exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(server_fd, 3) < 0) {
      perror("Listen failed");
      exit(EXIT_FAILURE);
  }

  printf("Server started on port %d\n", PORT);
  while (1) {
    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Read incoming data
    valread = read( new_socket , buffer, BUFFER_SIZE);
    printf("%s\n",buffer );

    // Send response
    send(new_socket , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");

    // Close the socket
    close(new_socket);
  }

  // Close the server
  close(server_fd);
  return 0;
}