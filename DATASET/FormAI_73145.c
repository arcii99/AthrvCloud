//FormAI DATASET v1.0 Category: Client Server Application ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define PORT_NUMBER 9002
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

  int server_socket, client_socket;
  struct sockaddr_in server_address, client_address;
  socklen_t client_address_size;
  char buffer[BUFFER_SIZE];

  // Create the server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Check if the server socket was created successfully
  if(server_socket < 0) {
    perror("Failed to create the server socket.");
    exit(1);
  }

  // Set the server address
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = htonl(INADDR_ANY);
  server_address.sin_port = htons(PORT_NUMBER);

  // Bind the server address to the server socket
  if(bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
    perror("Failed to bind the server address to the server socket.");
    exit(1);
  }

  // Listen to incoming client connections
  if(listen(server_socket, 1) < 0) {
    perror("Failed to listen to incoming client connections.");
    exit(1);
  }

  printf("The server is listening on port %d...\n", PORT_NUMBER);

  // Accept incoming client connections
  client_address_size = sizeof(client_address);
  client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_size);

  // Check if the client connection was accepted successfully
  if(client_socket < 0) {
    perror("Failed to accept the incoming client connection.");
    exit(1);
  }

  printf("A client has connected to the server.\n");

  // Receive messages from the client
  while(1) {
    bzero(buffer, BUFFER_SIZE);
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("Client: %s", buffer);

    // Exit the program if the client types "exit"
    if(strncmp(buffer, "exit", 4) == 0) {
      printf("The client has disconnected from the server.\n");
      break;
    }

    // Send a response to the client
    bzero(buffer, BUFFER_SIZE);
    printf("Server: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    send(client_socket, buffer, strlen(buffer), 0);
  }

  // Close the client socket
  close(client_socket);

  // Close the server socket
  close(server_socket);

  return 0;
}