//FormAI DATASET v1.0 Category: Networking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
  int sockfd, connfd;
  struct sockaddr_in serverAddr, clientAddr;
  char buffer[1024];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("Error: Socket creation failed.\n");
    exit(0);
  }

  memset(&serverAddr, 0, sizeof(serverAddr));
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
  serverAddr.sin_port = htons(PORT);

  if (bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) != 0) {
    printf("Error: Socket bind failed.\n");
    exit(0);
  }

  if (listen(sockfd, 5) != 0) {
    printf("Error: Socket listen failed.\n");
    exit(0);
  }

  printf("Server started on port %d...\n", PORT);

  while (1) {
    socklen_t len = sizeof(clientAddr);
    connfd = accept(sockfd, (struct sockaddr*)&clientAddr, &len);
    if (connfd < 0) {
      printf("Error: Socket accept failed.\n");
      exit(0);
    }

    printf("New client connected from %s:%d\n",
           inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

    while (1) {
      memset(buffer, 0, sizeof(buffer));
      int bytes = read(connfd, buffer, sizeof(buffer));
      if (bytes <= 0) {
        printf("Connection closed with client from %s:%d\n",
               inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
        break;
      }

      printf("Client said: %s\n", buffer);

      char response[1024];
      sprintf(response, "Server received: %s", buffer);
      write(connfd, response, strlen(response));
    }
  }

  close(sockfd);

  return 0;
}