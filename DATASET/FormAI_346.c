//FormAI DATASET v1.0 Category: Socket programming ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 8080
#define MAX_CONNECTIONS 10
#define BUFSIZE 1024

void handle_client(int client_sockfd) {
  char buffer[BUFSIZE];
  while (1) {
    memset(buffer, 0, BUFSIZE);
    int nbytes = recv(client_sockfd, buffer, BUFSIZE, 0);
    if (nbytes < 0) {
      fprintf(stderr, "Error receiving data from client\n");
      return;
    }
    if (nbytes == 0) {
      break;
    }
    printf("Received message from client: %s", buffer);
    send(client_sockfd, buffer, nbytes, 0);
  }
  printf("Closed connection. \n");
  close(client_sockfd);
}

int main() {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "Error creating socket\n");
    exit(1);
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    fprintf(stderr, "Error binding socket\n");
    exit(1);
  }

  if (listen(sockfd, MAX_CONNECTIONS) < 0) {
    fprintf(stderr, "Error listening for connections\n");
    exit(1);
  }

  printf("Listening on port %d\n", PORT);

  while (1) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if (client_sockfd < 0) {
      fprintf(stderr, "Error accepting connection\n");
      continue;
    }
    printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    handle_client(client_sockfd);
  }

  return 0;
}