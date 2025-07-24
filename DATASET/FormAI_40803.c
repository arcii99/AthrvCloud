//FormAI DATASET v1.0 Category: Client Server Application ; Style: standalone
// C Client Server Application Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 9000

int main () {
  int sockfd, newsockfd, n;
  socklen_t clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;

  // create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // setup server address
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);

  // bind socket to address
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }

  // listen on socket for incoming connections
  listen(sockfd,5);
  clilen = sizeof(cli_addr);

  // accept incoming connection
  newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
  if (newsockfd < 0) {
    perror("ERROR on accept");
    exit(1);
  }

  // read from socket
  bzero(buffer,256);
  n = read(newsockfd,buffer,255);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  printf("Here is the message: %s\n",buffer);

  // write to socket
  n = write(newsockfd,"I got your message",18);
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // close sockets
  close(newsockfd);
  close(sockfd);

  return 0;
}