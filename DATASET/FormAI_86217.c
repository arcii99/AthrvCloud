//FormAI DATASET v1.0 Category: Chat server ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int server_fd, new_socket, val_read;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[BUFFER_SIZE] = {0};
  char message[BUFFER_SIZE] = "Hello! Welcome to the Grateful Chat Server!\n";
  
  // Create socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    return EXIT_FAILURE;
  }
  
  // Forcefully attaching socket to the specified port
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt");
    return EXIT_FAILURE;
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);
  
  // Bind the socket to the specific port
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    return EXIT_FAILURE;
  }
  
  // Listen for incoming connections
  if (listen(server_fd, 3) < 0) {
    perror("listen failed");
    return EXIT_FAILURE;
  }
  
  printf("Grateful Chat Server listening on port %d...\n", PORT);

  while (1) {
    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
      perror("accept failed");
      return EXIT_FAILURE;
    }

    printf("New client connected from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

    // Send welcome message
    send(new_socket, message, strlen(message), 0);

    while ((val_read = read(new_socket, buffer, BUFFER_SIZE)) > 0) {
      printf("Client %s:%d says: %s", inet_ntoa(address.sin_addr), ntohs(address.sin_port), buffer);

      // Echo back message to the client
      send(new_socket, buffer, strlen(buffer), 0);
      memset(buffer, 0, BUFFER_SIZE);
    }

    if (val_read == 0) {
      printf("Client %s:%d disconnected\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
    } else {
      perror("read failed");
      return EXIT_FAILURE;
    }

    close(new_socket);
  }

  return EXIT_SUCCESS;
}