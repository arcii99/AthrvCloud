//FormAI DATASET v1.0 Category: Simple Web Server ; Style: Cryptic
// Wandering through the green pastures of the internet,
// The server awakens to take on the requests of the land.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// A faithful servant of the internet, the web server listens
// to incoming requests from the vast landscapes of the World Wide Web.

int main() {

  // The server's socket awakens from its slumber,
  // ready to receive requests from incoming connections.

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket()");
    return EXIT_FAILURE;
  }

  // The server waits patiently for connections on the designated port.
  // A connection is a bond between the server and the client that spans
  // across the vast distances of the internet.

  struct sockaddr_in server;
  bzero(&server, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(8080);

  if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("bind()");
    return EXIT_FAILURE;
  }

  if (listen(sockfd, 10) < 0) {
    perror("listen()");
    return EXIT_FAILURE;
  }

  // The server listens for requests, expecting only the finest conversations
  // with requests that abide by the HTTP protocol.

  while (1) {
    struct sockaddr_in client;
    socklen_t client_len = sizeof(client);
    int clientfd = accept(sockfd, (struct sockaddr *)&client, &client_len);

    if (clientfd < 0) {
      perror("accept()");
      return EXIT_FAILURE;
    }

    // The server reads the client's requests,
    // discerning their intent with a keen insight.

    char buffer[1024] = {0};
    if (read(clientfd, buffer, sizeof(buffer)) < 0) {
      perror("read()");
      return EXIT_FAILURE;
    }

    printf("%s", buffer);

    // The server, driven to serve the client's requests, responds
    // to requests with offerings of its own.

    char response[1024] = {0};
    sprintf(response, "HTTP/1.1 200 OK\r\n\r\nHello, friend!");

    if (write(clientfd, response, strlen(response)) < 0) {
      perror("write()");
      return EXIT_FAILURE;
    }

    // The server gracefully concludes the connection with the client,
    // bidding them a farewell until they cross paths once again.

    close(clientfd);
  }

  // The server cannot stay awake forever,
  // and leaves the realm of the internet with a proud legacy.

  close(sockfd);
  return 0;
}