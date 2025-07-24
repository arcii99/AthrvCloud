//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

#define PROXY_PORT 8080 // Proxy Listen Port
#define BUFFER_SIZE 1024 // Buffer Size to handle HTTP Requests/Responses

void handle_connection(int client_socket, struct sockaddr_in *client_address) {
  int proxy_socket;
  struct sockaddr_in server_address;
  char buffer[BUFFER_SIZE];
  int bytes_received;

  memset(buffer, 0, BUFFER_SIZE);

  // Create a new socket for proxy connection
  if ((proxy_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Unable to create proxy socket");
    exit(EXIT_FAILURE);
  }

  // Set the server_address struct
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // Change IP Address to your Destination Server IP
  server_address.sin_port = htons(80); // Change the Port to your Destination Server Port

  // Connect to the Destination Server
  if (connect(proxy_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("Unable to connect to server");
    exit(EXIT_FAILURE);
  }

  // Forward the HTTP Request to Destination Server
  send(proxy_socket, buffer, strlen(buffer), 0);

  // Receive HTTP Response from Destination Server
  while ((bytes_received = recv(proxy_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
    // Forward the HTTP Response to Client
    send(client_socket, buffer, bytes_received, 0);
    memset(buffer, 0, BUFFER_SIZE);
  }

  close(proxy_socket);
  close(client_socket);
}

int main() {
  int server_socket, client_socket;
  struct sockaddr_in server_address, client_address;
  socklen_t client_length = sizeof(client_address);
  pid_t pid;

  // Create a new socket for server
  if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Unable to create server socket");
    exit(EXIT_FAILURE);
  }

  // Set the server_address struct
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = htonl(INADDR_ANY);
  server_address.sin_port = htons(PROXY_PORT);

  // Bind the server socket to the server address
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("Unable to bind server socket");
    exit(EXIT_FAILURE);
  }

  // Start listening on the server socket
  if (listen(server_socket, 10) < 0) {
    perror("Unable to listen on server socket");
    exit(EXIT_FAILURE);
  }

  printf("Simple HTTP Proxy listening at %d\n", PROXY_PORT);

  while (1) {
    // Accept incoming client connection
    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_length)) < 0) {
      perror("Unable to accept client connection");
      continue;
    }

    if ((pid = fork()) == 0) {
      // Child process, handle the connection
      close(server_socket);
      handle_connection(client_socket, &client_address);
      exit(EXIT_SUCCESS);
    } else if (pid > 0) {
      // Parent process, continue accepting incoming connections
      close(client_socket);
      continue;
    } else {
      perror("Unable to fork child process");
      exit(EXIT_FAILURE);
    }
  }

  return 0; // Should never be reached
}