//FormAI DATASET v1.0 Category: Firewall ; Style: artistic
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(void) {
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int n;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    return 1;
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  portno = 4444;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    return 1;
  }

  listen(sockfd,5);
  clilen = sizeof(cli_addr);

  while(1) {
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if (newsockfd < 0) {
      perror("ERROR on accept");
      return 1;
    }

    bzero(buffer,256);
    n = read(newsockfd,buffer,255);

    if (n < 0) {
      perror("ERROR reading from socket");
      return 1;
    }

    printf("Here is the message: %s\n",buffer);
    n = write(newsockfd,"I got your message",18);

    if (n < 0) {
      perror("ERROR writing to socket");
      return 1;
    }

    close(newsockfd);
  }

  close(sockfd);
  return 0;
}