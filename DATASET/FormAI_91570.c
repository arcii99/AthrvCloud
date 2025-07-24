//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
  int server_fd, new_socket, val_read, opt = 1;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  char buffer[BUFFER_SIZE] = {0};
  char *hello = "Hello from server";

  // Creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Attaching socket to the given port
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // Binding socket to specific IP address and port
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Listening for incoming connections
  if (listen(server_fd, 3) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  // Accepting incoming connection
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
    perror("accept");
    exit(EXIT_FAILURE);
  }

  // Communicating with client
  while(1) {
    memset(buffer, 0, BUFFER_SIZE);
    val_read = read(new_socket, buffer, BUFFER_SIZE);

    if (val_read == 0) {
      printf("Client disconnected\n");
      break;
    }

    if (strcmp(buffer, "end") == 0) {
      printf("Client requested to end communication\n");
      break;
    }

    printf("Client: %s", buffer);

    // Sending response
    send(new_socket, hello, strlen(hello), 0);
    printf("Server: Hello message sent\n");
  }

  // Closing sockets
  close(new_socket);
  close(server_fd);
  return 0;
}