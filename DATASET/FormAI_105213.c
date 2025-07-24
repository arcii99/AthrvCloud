//FormAI DATASET v1.0 Category: Chat server ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  int sockfd, newsockfd, portno, clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int n;

  // create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // clear address structure
  bzero((char *) &serv_addr, sizeof(serv_addr));

  // set address family to internet
  serv_addr.sin_family = AF_INET;

  // bind to any available IP address on the local machine
  serv_addr.sin_addr.s_addr = INADDR_ANY;

  // set port number to use for communications
  portno = 5001;
  serv_addr.sin_port = htons(portno);

  // bind socket to IP address and port number
  if (bind(sockfd, (struct sockaddr *) &serv_addr,
           sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }

  // listen for incoming connections
  listen(sockfd, 5);
  clilen = sizeof(cli_addr);

  // accept incoming connection
  newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
  if (newsockfd < 0) {
    perror("ERROR on accept");
    exit(1);
  }

  // clear buffer
  bzero(buffer, 256);

  // read incoming message
  n = read(newsockfd, buffer, 255);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  // display message from client
  printf("Here is the message: %s\n", buffer);

  // send a response to the client
  n = write(newsockfd, "I got your message", 18);
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // close sockets and exit program
  close(newsockfd);
  close(sockfd);
  return 0;
}