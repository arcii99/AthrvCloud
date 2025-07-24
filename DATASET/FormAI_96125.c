//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define MAX_LINE 4096

void error(char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char **argv) {
  int sockfd, n;
  char recvline[MAX_LINE + 1];
  struct sockaddr_in servaddr;
  char *user;
  char *pass;
  char *host;
  char *msg;
  char *tmp;

  if (argc != 4) {
    fprintf(stderr,"usage: %s <hostname> <username> <password>\n", argv[0]);
    exit(1);
  }

  host = argv[1];
  user = argv[2];
  pass = argv[3];

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    error("socket error");
  }

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(110);

  if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
    error("inet_pton error for hostname");
  }

  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    error("connect error");
  }

  /* Get server greeting */
  if((n = read(sockfd, recvline, MAX_LINE)) <= 0) {
    error("read error");
  }
  recvline[n] = 0;
  printf("%s\n", recvline);

  /* Send user */
  if(asprintf(&msg, "USER %s\r\n", user) == -1) {
    error("asprintf error");
  }
  if (write(sockfd, msg, strlen(msg)) < 0) {
    error("write error");
  }
  free(msg);

  /* Get server response */
  if((n = read(sockfd, recvline, MAX_LINE)) <= 0) {
    error("read error");
  }
  recvline[n] = 0;
  printf("%s\n", recvline);

  /* Send pass */
  if(asprintf(&msg, "PASS %s\r\n", pass) == -1) {
    error("asprintf error");
  }
  if (write(sockfd, msg, strlen(msg)) < 0) {
    error("write error");
  }
  free(msg);

  /* Get server response */
  if((n = read(sockfd, recvline, MAX_LINE)) <= 0) {
    error("read error");
  }
  recvline[n] = 0;
  printf("%s\n", recvline);

  /* Send STAT to get mailbox status */
  if ((n = write(sockfd, "STAT\r\n", 6)) < 0) {
    error("write error");
  }

  /* Get server response */
  if ((n = read(sockfd, recvline, MAX_LINE)) < 0) {
    error("read error");
  }
  recvline[n] = 0;
  printf("%s\n", recvline);

  /* Parse number of messages */
  tmp = strtok(recvline, " ");
  tmp = strtok(NULL, " ");
  printf("There are %s messages in the mailbox.\n", tmp);

  close(sockfd);
  exit(0);
}