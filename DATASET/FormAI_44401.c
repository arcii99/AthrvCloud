//FormAI DATASET v1.0 Category: Networking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
  int socket_fd, new_socket, val_read;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  char *greeting = "Welcome to Retro Networking Example\n";
  char buffer[1024] = {0};

  // Creating socket
  if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }

  // Attaching socket to the port
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("Error binding socket");
    exit(EXIT_FAILURE);
  }

  // Listening for incoming connections
  if (listen(socket_fd, 3) < 0) {
    perror("Error listening on socket");
    exit(EXIT_FAILURE);
  }

  printf("Retro Networking Example is now listening on port %d\n", PORT);

  // Accepting incoming connections
  if ((new_socket = accept(socket_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
    perror("Error accepting connection");
    exit(EXIT_FAILURE);
  }

  // Sending greeting message to the client
  send(new_socket, greeting, strlen(greeting), 0);

  // Receiving message from the client
  val_read = read(new_socket, buffer, 1024);
  printf("Received message from the client: %s\n", buffer);

  // Sending message back to the client
  char *response = "Thanks for using Retro Networking Example!\n";
  send(new_socket, response, strlen(response), 0);

  // Closing the connection
  close(new_socket);
  close(socket_fd);

  return 0;
}