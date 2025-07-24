//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: active
// A program that sends and receives messages between a client and server using TCP/IP protocol.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 9000
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
  int server_socket, client_socket, bytes_received;
  char buffer[BUFFER_SIZE];
  struct sockaddr_in server_address, client_address;

  // Create the TCP server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
      error("ERROR opening socket");
  }

  // Setup the server address structure
  bzero((char *) &server_address, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT);

  // Bind the server socket to the specified IP and port
  if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
      error("ERROR on binding");
  }

  // Listen for incoming connections
  listen(server_socket, 5);
  printf("Server listening on port %d...\n", PORT);

  socklen_t client_address_size = sizeof(client_address);

  // Accept incoming connections and send/receive messages
  while (1) {
    // Accept incoming client connection
    client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_size);
    if (client_socket < 0) {
      error("ERROR on accept");
    }

    // Read message from client
    bzero(buffer, BUFFER_SIZE);
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received < 0) {
      error("ERROR reading from socket");
    } else {
      printf("Received message from client: %s\n", buffer);
    }

    // Send message to client
    char response[] = "Server received message";
    bytes_received = send(client_socket, response, strlen(response), 0);
    if (bytes_received < 0) {
      error("ERROR writing to socket");
    }

    // Close the client socket
    close(client_socket);
  }

  // Close the server socket
  close(server_socket);

  return 0;
}