//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define PORT_NUM 8888
#define BUFFER_SIZE 1024

int main() {
  int server_socket, client_socket;
  struct sockaddr_in server_addr, client_addr;

  // create socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  if (server_socket < 0) {
    perror("Failed to create socket");
    exit(EXIT_FAILURE);
  }

  // bind socket to IP address and port number
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT_NUM);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    perror("Failed to bind socket");
    exit(EXIT_FAILURE);
  }

  // listen for incoming connections
  if (listen(server_socket, 5) < 0) {
    perror("Failed to listen for connections");
    exit(EXIT_FAILURE);
  }

  printf("Server is listening on port %d...\n", PORT_NUM);

  while (1) {
    // accept incoming connection
    socklen_t client_addr_len = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_addr_len);

    if (client_socket < 0) {
      perror("Failed to accept incoming connection");
      continue;
    }

    // receive and print client message
    char buffer[BUFFER_SIZE] = {0};
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

    if (bytes_received < 0) {
      perror("Failed to receive client message");
      close(client_socket);
      continue;
    }

    printf("Received message from client: %s\n", buffer);

    // acknowledge message by sending response
    char response[] = "Server received your message";
    int bytes_sent = send(client_socket, response, strlen(response), 0);

    if (bytes_sent < 0) {
      perror("Failed to send response to client");
    }

    close(client_socket);
  }

  close(server_socket);
  return 0;
}