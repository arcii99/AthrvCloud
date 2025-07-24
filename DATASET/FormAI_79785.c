//FormAI DATASET v1.0 Category: Simple Web Server ; Style: optimized
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void error(const char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char **argv) {
  const int port = 8000;

  int sockfd, newsockfd;
  socklen_t clilen;
  char buffer[1024];
  struct sockaddr_in serv_addr, cli_addr;
  int n;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
    error("ERROR opening socket");

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(port);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    error("ERROR on binding");

  listen(sockfd, 5);
  printf("Web server started on port %d\n", port);

  clilen = sizeof(cli_addr);
  while (1) {
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0)
      error("ERROR on accept");

    memset(buffer, 0, 1024);
    n = read(newsockfd, buffer, 1023);
    if (n < 0)
      error("ERROR reading from socket");

    printf("Received request:\n%s\n", buffer);

    const char *response =
      "HTTP/1.1 200 OK\n"
      "Content-Type: text/plain\n"
      "\n"
      "Hello, World!\n";

    n = write(newsockfd, response, strlen(response));
    if (n < 0)
      error("ERROR writing to socket");

    close(newsockfd);
  }

  close(sockfd);

  return 0;
}