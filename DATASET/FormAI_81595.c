//FormAI DATASET v1.0 Category: Chat server ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_NAME "/tmp/chat_server.sock" // name of the socket file

int main() {
  int server_fd,ret;
  struct sockaddr_un local_addr, remote_addr;

  // create a socket in the Unix domain (AF_UNIX) for communication
  server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
  if (server_fd == -1) {
    perror("Socket creation error");
    exit(EXIT_FAILURE);
  }

  // setup the local address structure
  memset(&local_addr, 0, sizeof(struct sockaddr_un));
  local_addr.sun_family = AF_UNIX;
  strncpy(local_addr.sun_path, SOCKET_NAME, sizeof(local_addr.sun_path) - 1);

  // unlink the socket file if it already exists
  unlink(SOCKET_NAME);

  // bind the socket to the local address
  ret = bind(server_fd, (const struct sockaddr *)&local_addr, sizeof(struct sockaddr_un));
  if (ret == -1) {
    perror("Socket bind error");
    exit(EXIT_FAILURE);
  }

  // listen for incoming connections
  ret = listen(server_fd, 5);
  if (ret == -1) {
    perror("Socket listen error");
    exit(EXIT_FAILURE);
  }

  printf("Server started. Listening for incoming connections...\n");

  while (1) {
    // accept an incoming connection
    socklen_t len = sizeof(struct sockaddr_un);
    int client_fd = accept(server_fd, (struct sockaddr *)&remote_addr, &len);
    if (client_fd == -1) {
      perror("Socket accept error");
      exit(EXIT_FAILURE);
    }

    // create a child process to handle the client
    int pid = fork();
    if (pid == -1) {
      perror("Fork error");
      exit(EXIT_FAILURE);
    }

    if (pid == 0) {
      // child process: handle the client
      close(server_fd); // close the parent socket

      printf("Client connected: %s\n", remote_addr.sun_path);

      // send a welcome message to the client
      const char *welcome_message = "Welcome to the chat server!\n";
      send(client_fd, welcome_message, strlen(welcome_message), 0);

      // keep reading messages from the client and broadcast them to all connected clients
      while (1) {
        char buffer[1024];
        int ret = recv(client_fd, buffer, sizeof(buffer), 0);
        if (ret == -1) {
          perror("Socket receive error");
          exit(EXIT_FAILURE);
        }
        if (ret == 0) {
          // connection closed by client
          break;
        }
        buffer[ret] = '\0';
        printf("Message received from %s: %s", remote_addr.sun_path, buffer);

        // broadcast the message to all connected clients (except the sender)
        for (int i = 3; i < getdtablesize(); i++) {
          if (i != server_fd && i != client_fd) {
            send(i, buffer, strlen(buffer), 0);
          }
        }
      }

      printf("Client disconnected: %s\n", remote_addr.sun_path);
      close(client_fd); // close client socket
      exit(EXIT_SUCCESS);
    }

    close(client_fd); // parent process: close client socket
  }

  // cleanup (should not be executed)
  close(server_fd);
  unlink(SOCKET_NAME);
  
  return 0;
}