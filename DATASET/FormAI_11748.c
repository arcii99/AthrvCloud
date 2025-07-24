//FormAI DATASET v1.0 Category: Client Server Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 3000
#define BUFFER_SIZE 1024

int main() {
  int server_fd, client_fd;
  struct sockaddr_in server_addr, client_addr;
  char buffer[BUFFER_SIZE] = {0};
  char *success_message = "Message received successfully!\n";

  // Creating socket file descriptor for server
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Socket failed");
    exit(EXIT_FAILURE);
  }

  // Setting server address information
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  // Binding socket to server address
  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Bind failed");
    exit(EXIT_FAILURE);
  }

  // Listening for incoming connections
  if (listen(server_fd, 3) < 0) {
    perror("Listen failed");
    exit(EXIT_FAILURE);
  }

  printf("Listening for incoming connections on port %d...\n", PORT);

  // Accepting client connection
  int client_size = sizeof(client_addr);
  if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t *)&client_size)) < 0) {
    perror("Accept failed");
    exit(EXIT_FAILURE);
  }

  printf("Connected to client %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

  while (1) {
    memset(buffer, 0, BUFFER_SIZE);

    // Reading client message
    if (read(client_fd, buffer, BUFFER_SIZE) < 0) {
      perror("Read failed");
      exit(EXIT_FAILURE);
    }

    printf("Received message from client: %s", buffer);

    // Sending success message to client
    if (write(client_fd, success_message, strlen(success_message)) < 0) {
      perror("Write failed");
      exit(EXIT_FAILURE);
    }
  }

  // Closing socket file descriptors
  close(client_fd);
  close(server_fd);

  return 0;
}