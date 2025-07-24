//FormAI DATASET v1.0 Category: Simple Web Server ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define PORT 8080

int main(int argc, char const *argv[]) {
  int server_fd, client_fd;
  struct sockaddr_in server_addr, client_addr;
  char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE html><html><head><title>Hello, World!</title></head><body><h1>Hello, World!</h1></body></html>";
  
  // Create server socket
  if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Couldn't create server socket");
    exit(EXIT_FAILURE);
  }

  // Bind socket to address and port
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);
  memset(server_addr.sin_zero, '\0', sizeof server_addr.sin_zero);
  
  if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof server_addr) < 0) {
    perror("Bind Failed");
    exit(EXIT_FAILURE);
  }

  // Listen for connections
  if(listen(server_fd, 10) < 0) {
    perror("Listen Failed");
    exit(EXIT_FAILURE);
  }

  printf("Listening on port %d\n", PORT);
  socklen_t addrlen = sizeof client_addr;

  while(1) {
    // Accept client connection
    if((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen)) < 0) {
      perror("Connection Failed");
      exit(EXIT_FAILURE);
    }

    char buf[BUF_SIZE];
    memset(buf, 0, BUF_SIZE);
    ssize_t bytes_read = recv(client_fd, &buf, BUF_SIZE, 0);

    if(bytes_read > 0) {
      printf("%s", buf);
      send(client_fd, response, strlen(response), 0);
    }

    close(client_fd);
  }

  return 0;
}