//FormAI DATASET v1.0 Category: Simple Web Server ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  
  printf("Hello, I am a web server in disguise!\n");

  /* initialize variables */
  int sockfd, newsockfd, portno, clilen;
  char buffer[1024];
  struct sockaddr_in serv_addr, cli_addr;
  int n;

  if (argc < 2) {
    fprintf(stderr, "Error: no port provided\n");
    return 1;
  }

  /* create socket */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "Error: unable to create socket\n");
    return 1;
  }

  /* initialize server address */
  bzero((char *) &serv_addr, sizeof(serv_addr));
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  /* bind socket to server address */
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "Error: unable to bind socket to server address\n");
    return 1;
  }

  /* listen for clients */
  listen(sockfd, 5);
  clilen = sizeof(cli_addr);

  while(1) {
    /* accept client connection */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
      fprintf(stderr, "Error: unable to accept client connection\n");
      return 1;
    }

    /* read client request */
    bzero(buffer, 1024);
    n = read(newsockfd, buffer, 1023);
    if (n < 0) {
      fprintf(stderr, "Error: unable to read client request\n");
      return 1;
    }

    /* print client request */
    printf("Client request: %s\n", buffer);

    /* send response back to client */
    char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, I am a web server in disguise!\r\n";
    n = write(newsockfd, response, strlen(response));
    if (n < 0) {
      fprintf(stderr, "Error: unable to send response back to client\n");
      return 1;
    }

    /* close client socket */
    close(newsockfd);
  }

  return 0;
}