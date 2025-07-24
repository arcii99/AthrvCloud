//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc < 4) {
    fprintf(stderr, "Usage: %s [recipient] [subject] [body]\n", argv[0]);
    return 1;
  }

  char *recipient = argv[1];
  char *subject = argv[2];
  char *body = argv[3];

  char buf[BUF_SIZE];
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(25);
  if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
    perror("inet_pton");
    return 1;
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return 1;
  }

  if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s\n", buf);

  sprintf(buf, "EHLO client\r\n");
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }
  if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s\n", buf);

  sprintf(buf, "MAIL FROM: <client@example.com>\r\n");
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }
  if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s\n", buf);

  sprintf(buf, "RCPT TO: <%s>\r\n", recipient);
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }
  if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s\n", buf);

  sprintf(buf, "DATA\r\n");
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }
  if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s\n", buf);

  sprintf(buf, "From: client@example.com\r\n");
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }
  sprintf(buf, "To: <%s>\r\n", recipient);
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }
  sprintf(buf, "Subject: %s\r\n", subject);
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }
  sprintf(buf, "\r\n%s\r\n.\r\n", body);
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }
  if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s\n", buf);

  sprintf(buf, "QUIT\r\n");
  if (send(sockfd, buf, strlen(buf), 0) < 0) {
    perror("send");
    return 1;
  }
  if (recv(sockfd, buf, BUF_SIZE, 0) < 0) {
    perror("recv");
    return 1;
  }
  printf("%s\n", buf);

  close(sockfd);
  return 0;
}