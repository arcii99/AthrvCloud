//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  char buffer[BUFSIZE];

  if (argc < 3) {
    fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0)
    perror("ERROR opening socket");

  server = gethostbyname(argv[1]);

  if (server == NULL) {
    fprintf(stderr,"ERROR, no such host\n");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
    perror("ERROR connecting");

  printf("Please enter the HTTP request: ");
  bzero(buffer,BUFSIZE);
  fgets(buffer,BUFSIZE-1,stdin);

  n = write(sockfd,buffer,strlen(buffer));

  if (n < 0)
    perror("ERROR writing to socket");

  bzero(buffer,BUFSIZE);
  n = read(sockfd,buffer,BUFSIZE-1);

  if (n < 0)
    perror("ERROR reading from socket");

  printf("%s\n",buffer);

  close(sockfd);

  return 0;
}