//FormAI DATASET v1.0 Category: Simple Web Server ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int n;

  // Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Set server address
  bzero((char *) &serv_addr, sizeof(serv_addr));
  portno = 8080;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  // Bind socket to address
  if (bind(sockfd, (struct sockaddr *) &serv_addr,
           sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }

  // Listen for connections
  listen(sockfd, 5);
  clilen = sizeof(cli_addr);

  printf("Server running on port %d\n", portno);

  // Serve clients
  while (1) {
    // Accept connection
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
      perror("ERROR on accept");
      exit(1);
    }

    // Read request
    bzero(buffer, 256);
    n = read(newsockfd, buffer, 255);
    if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
    }
    printf("Received request:\n%s\n", buffer);

    // Write response
    char* response = "HTTP/1.1 200 OK\r\nContent-Length: 12\r\n\r\nHello world!";
    n = write(newsockfd, response, strlen(response));
    if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
    }

    // Close connection
    close(newsockfd);
  }

  return 0;
}