//FormAI DATASET v1.0 Category: Simple Web Server ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 80
#define MAX_REQUEST_SIZE 1024

int main() {
  printf("Wow! I can't believe I made a web server!\n");

  struct sockaddr_in serv_addr, cli_addr;
  char buffer[MAX_REQUEST_SIZE] = {0};

  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd < 0) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  memset(&serv_addr, '0', sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(server_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error binding socket");
    exit(EXIT_FAILURE);
  }

  listen(server_fd, 3);
  printf("Server listening on port %d\n", PORT);

  while (1) {
    socklen_t cli_addr_size = sizeof(cli_addr);
    int new_socket = accept(server_fd, (struct sockaddr*)&cli_addr, &cli_addr_size);
    if (new_socket < 0) {
      perror("Error accepting connection");
      exit(EXIT_FAILURE);
    }

    read(new_socket, buffer, MAX_REQUEST_SIZE);
    printf("Received request:\n%s\n", buffer);

    char* response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<!DOCTYPE html><html><body><h1>Welcome to my web server!</h1></body></html>";

    send(new_socket, response, strlen(response), 0);
    printf("Sent response:\n%s\n", response);

    close(new_socket);
  }

  close(server_fd);
  return 0;
}