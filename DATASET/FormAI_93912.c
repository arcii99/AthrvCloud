//FormAI DATASET v1.0 Category: Client Server Application ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {

  int server_sock, new_sock, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addr_len = sizeof(address);
  char buffer[1024] = { 0 };
  char *hello = "Hello from server!";

  // Create the server socket
  if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Set the socket options
  if (setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("Set socket options failed");
    exit(EXIT_FAILURE);
  }

  // Bind the socket to a port
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(server_sock, (struct sockaddr *)&address, sizeof(address))<0) {
    perror("Bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(server_sock, 3) < 0) {
    perror("Listen failed");
    exit(EXIT_FAILURE);
  }

  // Accept incoming connections
  if ((new_sock = accept(server_sock, (struct sockaddr *)&address, (socklen_t*)&addr_len))<0) {
    perror("Accept failed");
    exit(EXIT_FAILURE);
  }

  // Read and print the incoming message
  valread = read(new_sock, buffer, 1024);
  printf("Received message: %s\n", buffer);

  // Send the message to the client
  send(new_sock, hello, strlen(hello), 0);
  printf("Hello message sent\n");

  // Close the sockets
  close(new_sock);
  close(server_sock);

  return 0;
}