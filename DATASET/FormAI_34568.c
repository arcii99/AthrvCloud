//FormAI DATASET v1.0 Category: Client Server Application ; Style: scalable
// A C Client Server Application example program in a scalable style.
// The server listens for incoming connections on a socket port.
// The client connects to the server and sends a message.
// The server receives the message and sends it back to the client.
// The client receives the message and closes the connection.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
  int server_fd, client_fd;
  struct sockaddr_in server_address, client_address;
  socklen_t client_address_size = sizeof(client_address);
  char buffer[BUFFER_SIZE];

  // Step 1: create a socket
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Step 2: bind the socket to a specific port
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(1234);
  if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  // Step 3: listen for incoming connections
  if (listen(server_fd, 1) == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  // Step 4: accept a client connection
  if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_address_size)) == -1) {
    perror("accept");
    exit(EXIT_FAILURE);
  }

  // Step 5: receive a message from the client
  if (recv(client_fd, buffer, BUFFER_SIZE, 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  printf("Received message: %s\n", buffer);

  // Step 6: send the message back to the client
  if (send(client_fd, buffer, strlen(buffer), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Step 7: close the connection
  close(client_fd);
  close(server_fd);

  return 0;
}