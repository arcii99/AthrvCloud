//FormAI DATASET v1.0 Category: Chat server ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080

int sockfd;
struct sockaddr_in servaddr, cli;

void* serveClient(void* arg) {
  int clientSock = *(int*) arg;
  char buffer[1024];
  while (1) {
    int n = read(clientSock, buffer, 1024);
    if (n == 0) {
      close(clientSock);
      return NULL;
    }
    printf("Client: %s\n", buffer);
    write(clientSock, buffer, strlen(buffer));
    bzero(buffer, sizeof(buffer));
  }
}

int main() {
  int clientSock, len;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("Socket creation failed...\n");
    exit(0);
  }
  else printf("Socket created successfully!\n");

  bzero(&servaddr, sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(PORT);

  if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
    printf("Socket bind failed...\n");
    exit(0);
  }
  else printf("Socket binded successfully!\n");

  listen(sockfd, 5);
  printf("Listening...\n");

  while (1) {
    len = sizeof(cli);
    clientSock = accept(sockfd, (struct sockaddr*)&cli, &len);
    if (clientSock < 0) {
      printf("Server accept failed...\n");
      exit(0);
    }
    else printf("Server accepted the client request!\n");

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, serveClient, &clientSock);
    pthread_detach(thread_id);
  }

  close(sockfd);
  return 0;
}