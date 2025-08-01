//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  char buffer[256];

  if (argc < 3) {
    printf("Usage: %s hostname port\n", argv[0]);
    exit(0);
  }

  portno = atoi(argv[2]);
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {
    printf("Error opening socket\n");
    exit(1);
  }

  server = gethostbyname(argv[1]);

  if (server == NULL) {
    printf("Error, no such host\n");
    exit(0);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;

  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

  serv_addr.sin_port = htons(portno);

  if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
    printf("Error connecting\n");
    exit(1);
  }

  printf("Connected to server\n");

  while(1) {
    bzero(buffer, 256);

    printf("Enter a message:\n");

    fgets(buffer, 255, stdin);

    n = write(sockfd,buffer,strlen(buffer));

    if (n < 0) {
      printf("Error writing to socket\n");
      exit(1);
    }

    bzero(buffer,256);

    n = read(sockfd,buffer,255);

    if (n < 0) {
      printf("Error reading from socket\n");
      exit(1);
    }

    printf("Server replied: %s\n",buffer);
  }

  return 0;
}