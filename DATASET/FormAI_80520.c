//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  int sockfd;
  char buffer[1024];
  struct sockaddr_in servaddr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(143);
  inet_pton(AF_INET, "imap.example.com", &servaddr.sin_addr);

  connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));

  recv(sockfd, buffer, 1024, 0);
  printf("%s", buffer);

  send(sockfd, "1 LOGIN username password\n", strlen("1 LOGIN username password\n"), 0);
  recv(sockfd, buffer, 1024, 0);
  printf("%s", buffer);

  send(sockfd, "2 SELECT INBOX\n", strlen("2 SELECT INBOX\n"), 0);
  recv(sockfd, buffer, 1024, 0);
  printf("%s", buffer);

  send(sockfd, "3 FETCH 1 BODY[]\n", strlen("3 FETCH 1 BODY[]\n"), 0);
  recv(sockfd, buffer, 1024, 0);
  printf("%s", buffer);

  send(sockfd, "4 LOGOUT\n", strlen("4 LOGOUT\n"), 0);
  recv(sockfd, buffer, 1024, 0);
  printf("%s", buffer);

  close(sockfd);

  return 0;
}