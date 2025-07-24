//FormAI DATASET v1.0 Category: Client Server Application ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT_NUMBER 8080
#define BUFFER_SIZE 1024

int main() {
  int server_socket, client_socket, addr_len, bytes_received;
  struct sockaddr_in server_addr, client_addr;
  char buffer[BUFFER_SIZE];

  // create the socket
  server_socket = socket(PF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // bind the socket to a port
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT_NUMBER);
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // listen for incoming connections
  if (listen(server_socket, 5) < 0) {
    perror("Error listening for connections");
    exit(1);
  }

  printf("Server listening on port %d\n", PORT_NUMBER);

  // accept incoming connections
  addr_len = sizeof(client_addr);
  client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addr_len);
  if (client_socket < 0) {
    perror("Error accepting connection");
    exit(1);
  }

  printf("Client connected\n");

  // receive data from client
  memset(buffer, 0, BUFFER_SIZE);
  bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
  if (bytes_received < 0) {
    perror("Error receiving data from client");
    exit(1);
  }

  printf("Received data from client: %s\n", buffer);

  // send response to client
  if (send(client_socket, "Hello from the server!", 22, 0) < 0) {
    perror("Error sending data to client");
    exit(1);
  }

  printf("Response sent to client\n");

  // close the sockets
  close(client_socket);
  close(server_socket);

  return 0;
}