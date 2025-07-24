//FormAI DATASET v1.0 Category: Networking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

void error(char *msg){
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[]){

  int sockfd, newsockfd, clientlen;
  char buffer[256];
  struct sockaddr_in serveraddr, clientaddr;
  
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) error("ERROR opening socket");

  memset(&serveraddr, '\0', sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_addr.s_addr = INADDR_ANY;
  serveraddr.sin_port = htons(PORT);

  if(bind(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0)
    error("ERROR on binding");

  listen(sockfd, 5);
  clientlen = sizeof(clientaddr);

  while(1){

    printf("Server waiting for connection...\n");
    newsockfd = accept(sockfd, (struct sockaddr *) &clientaddr, &clientlen);
    
    if(newsockfd < 0) error("ERROR on accept");

    printf("Server got connection from %s\n", inet_ntoa(clientaddr.sin_addr));

    memset(buffer, '\0', 256);
    int n = read(newsockfd, buffer, 255);
    if(n < 0) error("ERROR reading from socket");

    printf("Server received: '%s'\n", buffer);

    n = write(newsockfd, "I got your message", 18);
    if(n < 0) error("ERROR writing to socket");

    close(newsockfd);
  }

  close(sockfd);
  return 0;
}