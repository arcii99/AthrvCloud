//FormAI DATASET v1.0 Category: Client Server Application ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 8080

int main() {
  int sockfd, connfd, len;
  struct sockaddr_in servaddr, cli;
  char buff[1024];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("socket creation failed...");
    exit(0);
  } else {
    printf("socket created successfully...\n");
  }

  bzero(&servaddr, sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(PORT);

  if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
    printf("socket binding failed...\n");
    exit(0);
  } else {
    printf("socket binding successful...\n");
  }

  if ((listen(sockfd, 5)) != 0) {
    printf("Listen failed...\n");
    exit(0);
  } else {
    printf("Server listening...\n");
  }

  len = sizeof(cli);

  connfd = accept(sockfd, (struct sockaddr*)&cli, &len);
  if (connfd < 0) {
    printf("server accept failed...\n");
    exit(0);
  } else {
    printf("server accept the client...\n");
  }

  while (1) {
    bzero(buff, sizeof(buff));
    read(connfd, buff, sizeof(buff));
    if (strncmp("exit", buff, 4) == 0) {
      printf("server exit...\n");
      break;
    }
    printf("From client: %s\n", buff);
    bzero(buff, sizeof(buff));
    printf("Enter the string: ");
    fflush(stdout);

    int n = 0;
    while ((buff[n++] = getchar()) != '\n')
      ;

    write(connfd, buff, sizeof(buff));
    printf("To client: %s\n", buff);
  }

  close(sockfd);

  return 0;
}