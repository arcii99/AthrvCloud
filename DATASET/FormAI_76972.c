//FormAI DATASET v1.0 Category: Networking ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
  int socket_fd, new_socket_fd;
  struct sockaddr_in server_address, client_address;
  int opt = 1;
  int address_length = sizeof(server_address);

  char *response = "Hello from the server!";
  char buffer[1024] = {0};

  // Create a socket
  if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Failed to create a socket");
    exit(EXIT_FAILURE);
  }

  // Set socket options
  if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                 sizeof(opt))) {
    perror("Failed to set socket options");
    exit(EXIT_FAILURE);
  }

  // Bind to address and port
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(PORT);
  if (bind(socket_fd, (struct sockaddr *)&server_address,
           sizeof(server_address)) < 0) {
    perror("Bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(socket_fd, 3) < 0) {
    perror("Listen failed");
    exit(EXIT_FAILURE);
  }

  printf("Server is listening on port %d\n", PORT);

  // Accept incoming connection
  if ((new_socket_fd = accept(socket_fd, (struct sockaddr *)&server_address,
                              (socklen_t *)&address_length)) < 0) {
    perror("Accept failed");
    exit(EXIT_FAILURE);
  }

  // Receive data from client
  int valread = read(new_socket_fd, buffer, 1024);
  printf("Received message from client: %s\n", buffer);

  // Send response to client
  send(new_socket_fd, response, strlen(response), 0);
  printf("Response sent to client\n");

  return 0;
}