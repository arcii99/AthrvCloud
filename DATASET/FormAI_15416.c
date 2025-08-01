//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <arpa/inet.h>

// Function to print error messages
void error(const char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char **argv) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  // Check for correct usage
  if (argc < 4) {
    fprintf(stderr,"Usage: %s hostname portnum message\n", argv[0]);
    exit(1);
  }

  // Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) error("ERROR opening socket");

  // Set server info
  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr,"ERROR, no such host\n");
    exit(0);
  }
  portno = atoi(argv[2]);
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  // Connect to server
  if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
      error("ERROR connecting");

  // Send message to server
  n = write(sockfd, argv[3], strlen(argv[3]));
  if (n < 0) error("ERROR writing to socket");

  // Read response from server
  char buffer[256];
  bzero(buffer, 256);
  n = read(sockfd, buffer, 255);
  if (n < 0) error("ERROR reading from socket");
  printf("%s\n", buffer);

  // Close socket
  close(sockfd);

  return 0;
}