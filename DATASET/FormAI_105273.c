//FormAI DATASET v1.0 Category: Client Server Application ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10

int main() {
  struct sockaddr_in server_addr, client_addr;
  int sock_fd, new_sock_fd, opt = 1;
  socklen_t client_addr_len;
  int clients[MAX_CLIENTS];
  fd_set read_fds;

  // create server socket
  if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // set socket options
  if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt failed");
    exit(EXIT_FAILURE);
  }

  // bind server socket to IP and port
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(PORT);

  if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // listen for incoming connections
  if (listen(sock_fd, MAX_CLIENTS) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  // initialize client list
  for (int i = 0; i < MAX_CLIENTS; i++) {
    clients[i] = 0;
  }

  printf("Server is listening on port %d\n", PORT);

  while (1) {
    FD_ZERO(&read_fds);
    FD_SET(sock_fd, &read_fds);
    int max_fd = sock_fd;

    // add active clients to the select set
    for (int i = 0; i < MAX_CLIENTS; i++) {
      int fd = clients[i];
      if (fd > 0) {
        FD_SET(fd, &read_fds);
        max_fd = (max_fd > fd) ? max_fd : fd;
      }
    }

    // wait for activity on any of our sockets
    select(max_fd + 1, &read_fds, NULL, NULL, NULL);

    // check for incoming connection
    if (FD_ISSET(sock_fd, &read_fds)) {
      if ((new_sock_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
      }

      printf("New client connected\n");

      // add new client to list
      for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i] == 0) {
          clients[i] = new_sock_fd;
          break;
        }
      }
    }

    // check for activity on existing connections
    for (int i = 0; i < MAX_CLIENTS; i++) {
      int fd = clients[i];
      if (fd > 0 && FD_ISSET(fd, &read_fds)) {
        char buffer[1024] = {0};
        int bytes_read = read(fd, buffer, 1024);

        if (bytes_read == 0) {
          // client disconnected
          printf("Client disconnected\n");
          close(fd);
          clients[i] = 0;
        } else {
          // echo message back to client
          printf("Received message: %s\n", buffer);
          write(fd, buffer, strlen(buffer));
        }
      }
    }
  }

  return 0;
}