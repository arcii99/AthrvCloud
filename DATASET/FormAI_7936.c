//FormAI DATASET v1.0 Category: Socket programming ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8888
#define BUF_SIZE 1024

int main(int argc, char const *argv[]) {
  int server_fd, client_fd, valread;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[BUF_SIZE] = {0};

  // Creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // Forcefully attaching socket to the port 8888
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // Forcefully attaching socket to the port 8888
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  if (listen(server_fd, 3) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  printf("Server is running on port %d\n", PORT);
  while (1) {
    if ((client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
      perror("accept");
      exit(EXIT_FAILURE);
    }

    char *client_ip = inet_ntoa(address.sin_addr);
    int client_port = ntohs(address.sin_port);
    printf("New client connection, addr=%s:%d\n", client_ip, client_port);

    int pid = fork();
    if (pid == -1) {
      perror("fork failed");
      exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
      // Child process
      close(server_fd);
      while (1) {
        valread = read(client_fd, buffer, BUF_SIZE);
        if (valread < 1) {
          printf("Client disconnected. Exiting child process...\n");
          break;
        }
        printf("Received message from %s:%d [%d bytes]: %s\n", client_ip, client_port, valread, buffer);

        char *response = "Got your message! Thanks!\n";
        send(client_fd, response, strlen(response), 0);
        memset(buffer, 0, BUF_SIZE);
      }
      close(client_fd);
      exit(0);
    }
    else {
      // Parent process
      close(client_fd);
    }
  }
  return 0;
}