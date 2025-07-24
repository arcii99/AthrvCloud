//FormAI DATASET v1.0 Category: Networking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
  int server_fd, client_socket, valread;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  char message[1024] = "Hello from the server side!";

  // Creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Attach socket to the port 8080
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);
  memset(address.sin_zero, '\0', sizeof address.sin_zero);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(server_fd, 3) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  printf("Server is now listening on port %d\n", PORT);

  // Accept incoming connection
  if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
    perror("accept failed");
    exit(EXIT_FAILURE);
  }

  printf("A new client has connected.\n");

  // Read message from client
  char buffer[1024] = {0};
  valread = read(client_socket, buffer, 1024);
  printf("Client said: %s\n", buffer);

  // Respond to client's message
  send(client_socket, message, strlen(message), 0);
  printf("Server has responded to the client.\n");

  close(server_fd);
  return 0;
}