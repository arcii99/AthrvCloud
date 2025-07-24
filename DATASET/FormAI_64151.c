//FormAI DATASET v1.0 Category: Chat server ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
  printf("Welcome to the Happy Chat Server!\n");

  // Create a socket for the server
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    printf("Failed to create socket, exiting...\n");
    return 1;
  }

  // Bind the socket to the localhost and port 8888
  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(8888);

  if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
    printf("Failed to bind socket, exiting...\n");
    return 1;
  }

  printf("Server is listening for clients...\n");

  // Listen for incoming connections
  if (listen(server_socket, 3) < 0) {
    printf("Failed to listen for incoming connections, exiting...\n");
    return 1;
  }

  // Accept incoming connections and handle requests
  struct sockaddr_in client_address;
  int client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&client_address);
  if (client_socket < 0) {
    printf("Failed to accept incoming connection, exiting...\n");
    return 1;
  }
  printf("Client connected!\n");

  // Send a welcome message to the client
  char* welcome_message = "Welcome to the Happy Chat Server! Type your message and press enter to send.\n";
  send(client_socket, welcome_message, strlen(welcome_message), 0);

  while(1) {
    char buffer[1024] = {0};
    int read_value = read(client_socket, buffer, 1024);
    if (read_value < 0) {
      printf("Failed to read from client socket, exiting...\n");
      return 1;
    }

    if (strcmp(buffer, "exit\n") == 0) {
      // Client has requested to exit, close the connection
      printf("Client has left the chat, closing connection...\n");
      close(client_socket);
      return 0;
    }

    // Display the client's message on the server side
    printf("Client: %s", buffer);

    // Send the client's message back to them
    send(client_socket, buffer, strlen(buffer), 0);
  }

  return 0;
}