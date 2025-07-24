//FormAI DATASET v1.0 Category: Socket programming ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888

int main(int argc, char const *argv[]) {
  int socket_fd, new_socket, valread;
  struct sockaddr_in server_addr, client_addr;
  char message[1024] = {0};

  if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Socket creation error");
    exit(EXIT_FAILURE);
  }

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Bind failed");
    exit(EXIT_FAILURE);
  }

  listen(socket_fd, 3);
  printf("Server listening on port %d \n", PORT);

  int addrlen = sizeof(client_addr);
  if ((new_socket = accept(socket_fd, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen)) < 0) {
    perror("Accept failed");
    exit(EXIT_FAILURE);
  }

  printf("Connection accepted from %s:%d \n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

  // client message loop
  while (1) {
    valread = read(new_socket, message, 1024);
    if (valread == 0) {
      printf("Client disconnected.\n");
      break;
    } else {
      printf("Client: %s", message);
    }

    memset(message, 0, sizeof(message));

    // server sending message to client
    printf("Server: ");
    fgets(message, sizeof(message), stdin);
    send(new_socket, message, strlen(message), 0);
    memset(message, 0, sizeof(message));
  }

  close(new_socket);
  close(socket_fd);

  return 0;
}