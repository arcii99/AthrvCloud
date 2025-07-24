//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFF_SIZE 4096

int main(int argc, char *argv[]) {
  int sockfd;
  int port = 143;
  char *server_addr = "mail.example.com";
  struct sockaddr_in server;

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket error");
    exit(1);
  }

  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  if (inet_pton(AF_INET, server_addr, &server.sin_addr) <= 0) {
    perror("inet_pton error");
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("connect error");
    exit(1);
  }

  char buff[BUFF_SIZE];
  int n;
  if ((n = read(sockfd, buff, sizeof(buff))) < 0) {
    perror("read error");
    exit(1);
  }

  printf("Server response:\n%s\n", buff);

  if (write(sockfd, "a001 LOGIN johndoe secretpassword\r\n", 34) < 0) {
    perror("write error");
    exit(1);
  }

  if ((n = read(sockfd, buff, sizeof(buff))) < 0) {
    perror("read error");
    exit(1);
  }

  printf("Server response:\n%s\n", buff);

  if (write(sockfd, "a002 LIST \"\" *\r\n", 17) < 0) {
    perror("write error");
    exit(1);
  }

  if ((n = read(sockfd, buff, sizeof(buff))) < 0) {
    perror("read error");
    exit(1);
  }

  printf("Server response:\n%s\n", buff);

  if (write(sockfd, "a003 SELECT INBOX\r\n", 19) < 0) {
    perror("write error");
    exit(1);
  }

  if ((n = read(sockfd, buff, sizeof(buff))) < 0) {
    perror("read error");
    exit(1);
  }

  printf("Server response:\n%s\n", buff);

  if (write(sockfd, "a004 FETCH 1:10 (BODY.PEEK[HEADER.FIELDS (SUBJECT FROM DATE)])\r\n", 60) < 0) {
    perror("write error");
    exit(1);
  }

  if ((n = read(sockfd, buff, sizeof(buff))) < 0) {
    perror("read error");
    exit(1);
  }

  printf("Server response:\n%s\n", buff);

  if (write(sockfd, "a005 LOGOUT\r\n", 13) < 0) {
    perror("write error");
    exit(1);
  }

  if ((n = read(sockfd, buff, sizeof(buff))) < 0) {
    perror("read error");
    exit(1);
  }

  printf("Server response:\n%s\n", buff);

  close(sockfd);

  return 0;
}