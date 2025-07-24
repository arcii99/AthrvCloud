//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 4096

int main(int argc, char *argv[]) {

  if (argc != 4) {
    printf("Usage: %s server_address username password\n", argv[0]);
    return 1;
  }

  char *server_address = argv[1];
  char *username = argv[2];
  char *password = argv[3];

  // connect to the POP3 server
  int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_fd < 0) {
    perror("socket");
    return 1;
  }

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(server_address);
  server.sin_port = htons(110); // the POP3 port
  if (connect(sock_fd, (struct sockaddr *) &server, sizeof(server)) < 0) {
    perror("connect");
    return 1;
  }

  // wait for the server greeting
  char response[BUFSIZE];
  memset(response, 0, BUFSIZE);
  if (recv(sock_fd, response, BUFSIZE, 0) < 0) {
    perror("recv");
    close(sock_fd);
    return 1;
  }

  printf("Server greeting: %s", response);

  // send the username and password
  char message[BUFSIZE];
  memset(message, 0, BUFSIZE);
  sprintf(message, "USER %s\r\n", username);
  if (send(sock_fd, message, strlen(message), 0) < 0) {
    perror("send");
    close(sock_fd);
    return 1;
  }

  memset(message, 0, BUFSIZE);
  sprintf(message, "PASS ________\r\n", password); // fill in the blank!
  if (send(sock_fd, message, strlen(message), 0) < 0) {
    perror("send");
    close(sock_fd);
    return 1;
  }

  // wait for the response
  memset(response, 0, BUFSIZE);
  if (recv(sock_fd, response, BUFSIZE, 0) < 0) {
    perror("recv");
    close(sock_fd);
    return 1;
  }

  printf("Authentication response: %s", response);

  // send the list command
  memset(message, 0, BUFSIZE);
  sprintf(message, "LIST\r\n");
  if (send(sock_fd, message, strlen(message), 0) < 0) {
    perror("send");
    close(sock_fd);
    return 1;
  }

  // wait for the response
  memset(response, 0, BUFSIZE);
  if (recv(sock_fd, response, BUFSIZE, 0) < 0) {
    perror("recv");
    close(sock_fd);
    return 1;
  }

  printf("Message list: %s", response);

  // quit
  memset(message, 0, BUFSIZE);
  sprintf(message, "QUIT\r\n");
  if (send(sock_fd, message, strlen(message), 0) < 0) {
    perror("send");
    close(sock_fd);
    return 1;
  }

  // wait for the response
  memset(response, 0, BUFSIZE);
  if (recv(sock_fd, response, BUFSIZE, 0) < 0) {
    perror("recv");
    close(sock_fd);
    return 1;
  }

  printf("Quit response: %s", response);

  close(sock_fd);
  return 0;
}