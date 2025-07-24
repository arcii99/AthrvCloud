//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 143

int main(int argc, char *argv[]) {

  int sockfd;
  struct sockaddr_in servaddr;

  if (argc < 2) {
    fprintf(stderr, "usage: %s <hostname>\n", argv[0]);
    exit(1);
  }

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket error");
    exit(1);
  }

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(SERVER_PORT);
  
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    fprintf(stderr, "inet_pton error for %s\n", argv[1]);
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
    perror("connect error");
    exit(1);
  }

  printf("Connected to server!\n");

  char * login_command = "a001 LOGIN testuser testpass\n";
  char * inbox_command = "a002 SELECT INBOX\n";
  char * logout_command = "a003 LOGOUT\n";

  char buffer[1024];
  char * command;

  size_t nbytes = 0;

  // login
  command = login_command;
  nbytes = strlen(login_command);
  write(sockfd, command, nbytes);

  memset(buffer, 0, sizeof(buffer));
  nbytes = read(sockfd, buffer, sizeof(buffer)-1);
  printf("%s", buffer);


  // select inbox
  command = inbox_command;
  nbytes = strlen(inbox_command);
  write(sockfd, command, nbytes);

  memset(buffer, 0, sizeof(buffer));
  nbytes = read(sockfd, buffer, sizeof(buffer)-1);
  printf("%s", buffer);

  // logout
  command = logout_command;
  nbytes = strlen(logout_command);
  write(sockfd, command, nbytes);

  memset(buffer, 0, sizeof(buffer));
  nbytes = read(sockfd, buffer, sizeof(buffer)-1);
  printf("%s", buffer);

  close(sockfd);
  return 0;
}