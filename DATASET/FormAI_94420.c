//FormAI DATASET v1.0 Category: Networking ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define PORT 1234
#define MAXLINE 1024

int main(int argc, char **argv) {
  int sockfd;
  ssize_t n;
  char recvline[MAXLINE + 1];
  struct sockaddr_in servaddr;

  if (argc != 2){
    printf("usage: ./zombie_apocalypse <IP address>\n");
    exit(EXIT_FAILURE);
  }

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    perror("socket error");
    exit(EXIT_FAILURE);
  }

  bzero(&servaddr, sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);

  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0){
    perror("inet_pton error");
    exit(EXIT_FAILURE);
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
    perror("connect error");
    exit(EXIT_FAILURE);
  }

  printf("Connected to the server!\n");

  while ((n = read(sockfd, recvline, MAXLINE)) > 0){
    recvline[n] = '\0';

    if (fputs(recvline, stdout) == EOF){
      perror("fputs error");
      exit(EXIT_FAILURE);
    }
  }

  if (n < 0){
    perror("read error");
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}