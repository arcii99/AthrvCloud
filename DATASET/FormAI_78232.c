//FormAI DATASET v1.0 Category: Simple Web Server ; Style: complex
// This is a complex style implementation of a simple web server in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {

  int server_fd, client_fd;
  struct sockaddr_in server_addr, client_addr;
  char buffer[BUFFER_SIZE] = { 0 };
  char response[BUFFER_SIZE] = { 0 };

  // Create a socket
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    printf("Could not create socket\n");
    exit(EXIT_FAILURE);
  }

  // Set socket options
  int opt = 1;
  setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

  // Bind socket to a port
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    printf("Could not bind to port %d\n", PORT);
    exit(EXIT_FAILURE);
  }

  // Start listening for incoming connections
  if (listen(server_fd, 3) < 0) {
    printf("Could not listen for incoming connections\n");
    exit(EXIT_FAILURE);
  }

  printf("Server started at port %d\n", PORT);

  while(1) {

    int client_addr_length = sizeof(client_addr);

    if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_addr_length)) < 0) {
      printf("Could not accept incoming connection\n");
      continue;
    }

    // Read incoming request from client
    read(client_fd, buffer, BUFFER_SIZE);

    printf("Received request from client:\n%s\n", buffer);

    // Process request and generate response
    if (strstr(buffer, "GET") != NULL) {
      sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello World!</h1></body></html>");
    }
    else {
      sprintf(response, "HTTP/1.1 400 Bad Request\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Error 400: Bad Request</h1></body></html>");
    }

    // Send response back to client
    send(client_fd, response, strlen(response), 0);

    close(client_fd);
  }

  return 0;
}