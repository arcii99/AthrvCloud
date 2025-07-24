//FormAI DATASET v1.0 Category: Simple Web Server ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define RESPONSE_TEMPLATE "HTTP/1.1 200 OK\nContent-Length: %ld\n\n%s"
#define MAX_BUFFER_SIZE 2048

int main(int argc, char const *argv[]) {
  int server_fd, new_socket;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[MAX_BUFFER_SIZE] = {0};
  char response[MAX_BUFFER_SIZE] = {0};

  // Creating server socket
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Error: Socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Attaching socket to port
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
    perror("Error: setsockopt failed");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(8080);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("Error: bind failed");
    exit(EXIT_FAILURE);
  }

  if (listen(server_fd, 3) < 0) {
    perror("Error: listen failed");
    exit(EXIT_FAILURE);
  }

  printf("Listening on port 8080...\n");

  while (1) {
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
      perror("Error: accept failed");
      exit(EXIT_FAILURE);
    }

    memset(buffer, 0, MAX_BUFFER_SIZE);
    if (read(new_socket, buffer, MAX_BUFFER_SIZE) < 0) {
      perror("Error: read failed");
      exit(EXIT_FAILURE);
    }

    char response_body[MAX_BUFFER_SIZE] = "<h1>Hello from Simple Web Server!</h1>";

    sprintf(response, RESPONSE_TEMPLATE, strlen(response_body), response_body);

    if (write(new_socket, response, strlen(response)) < 0) {
      perror("Error: write failed");
      exit(EXIT_FAILURE);
    }

    close(new_socket);
  }

  return 0;
}