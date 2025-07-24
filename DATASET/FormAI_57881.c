//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFF_SIZE 2048
#define PORT 8080
#define HOST "127.0.0.1"

int main(int argc, char *argv[]) {

  int server_fd, new_socket, valread;
  struct sockaddr_in address;
  int addrlen = sizeof(address);
  char buffer[BUFF_SIZE] = {0};

  // Create socket
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Socket failed");
    exit(EXIT_FAILURE);
  }

  // Set socket options
  int opt = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt failed");
    exit(EXIT_FAILURE);
  }

  // Bind socket to address and port
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = inet_addr(HOST);
  address.sin_port = htons(PORT);
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(server_fd, 3) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  while (1) {
    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
      perror("accept failed");
      exit(EXIT_FAILURE);
    }

    // Read request from the client
    valread = read(new_socket, buffer, BUFF_SIZE);
    printf("%s", buffer);

    // Create new socket to connect to the remote server
    int remote_socket;
    if ((remote_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
      perror("remote socket failed");
      exit(EXIT_FAILURE);
    }

    // Connect to remote server
    struct sockaddr_in remote_address;
    remote_address.sin_family = AF_INET;
    remote_address.sin_addr.s_addr = inet_addr(HOST);
    remote_address.sin_port = htons(PORT);
    if (connect(remote_socket, (struct sockaddr *)&remote_address, sizeof(remote_address)) < 0) {
      perror("remote connect failed");
      exit(EXIT_FAILURE);
    }

    // Forward request to remote server
    if (send(remote_socket, buffer, strlen(buffer), 0) < 0) {
      perror("send failed");
      exit(EXIT_FAILURE);
    }

    // Read response from remote server
    char remote_buffer[BUFF_SIZE] = {0};
    valread = read(remote_socket, remote_buffer, BUFF_SIZE);
    printf("%s\n", remote_buffer);

    // Forward response from remote server to client
    if (send(new_socket, remote_buffer, strlen(remote_buffer), 0) < 0) {
      perror("send failed");
      exit(EXIT_FAILURE);
    }

    // Close sockets
    close(new_socket);
    close(remote_socket);
  }

  return 0;
}