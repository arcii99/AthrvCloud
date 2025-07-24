//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5555

int main() {
  int sockfd, client_sockfd;
  socklen_t sin_size;
  struct sockaddr_in server_addr, client_addr;

  memset(&server_addr, 0, sizeof(struct sockaddr_in));

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  server_addr.sin_addr.s_addr = INADDR_ANY;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd == -1) {
    perror("Error creating socket.");
    exit(EXIT_FAILURE);
  }

  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
    perror("Error binding socket.");
    exit(EXIT_FAILURE);
  }

  if (listen(sockfd, 10) == -1) {
    perror("Error listening on socket.");
    exit(EXIT_FAILURE);
  }

  printf("Server waiting for connections on port %d.\n", PORT);

  sin_size = sizeof(struct sockaddr_in);
  client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);

  if (client_sockfd == -1) {
    perror("Error accepting connection.");
    exit(EXIT_FAILURE);
  }

  printf("Client connected from %s:%d.\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

  close(client_sockfd);
  close(sockfd);

  return EXIT_SUCCESS;
}