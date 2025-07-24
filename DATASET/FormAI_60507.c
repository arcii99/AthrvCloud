//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
  int sockfd;
  struct sockaddr_in server_addr;
  char request[1024], response[4096];

  // create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    perror("Failed to create socket");
    return 1;
  }

  // initialize server address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  server_addr.sin_port = htons(80);

  // connect to server
  if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Failed to connect to server");
    return 1;
  }

  // send HTTP request
  sprintf(request, "GET /index.html HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n");
  if(send(sockfd, request, strlen(request), 0) < 0) {
    perror("Failed to send request");
    return 1;
  }

  // receive HTTP response
  memset(response, 0, sizeof(response));
  if(recv(sockfd, response, sizeof(response), 0) < 0) {
    perror("Failed to receive response");
    return 1;
  }

  printf("HTTP response:\n%s\n", response);

  // close socket
  close(sockfd);

  return 0;
}