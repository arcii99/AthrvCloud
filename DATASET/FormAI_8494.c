//FormAI DATASET v1.0 Category: Simple Web Server ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

// Define the port number to listen on
#define PORT 8080

int main()
{
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error opening socket");
    exit(1);
  }

  // Set up the server address
  struct sockaddr_in serveraddr;
  memset(&serveraddr, 0, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(PORT);
  serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

  // Bind the socket to the address
  if (bind(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0) {
    perror("Error binding socket to address");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(sockfd, 10) < 0) {
    perror("Error listening for connections");
    exit(1);
  }

  printf("Exciting News! Your Web Server is now running on port %d\n", PORT);

  while (1) {
    // Accept a connection from a client
    struct sockaddr_in clientaddr;
    socklen_t clientaddrlen = sizeof(clientaddr);
    int clientsockfd = accept(sockfd, (struct sockaddr*)&clientaddr, &clientaddrlen);
    if (clientsockfd < 0) {
      perror("Error accepting connection");
      exit(1);
    }

    // Read the HTTP request sent by the client
    char request[1024];
    memset(request, 0, sizeof(request));
    if (read(clientsockfd, request, sizeof(request)-1) < 0) {
      perror("Error reading HTTP request");
      close(clientsockfd);
      exit(1);
    }

    // Send an HTTP response back to the client
    char response[1024];
    sprintf(response, "HTTP/1.1 200 OK\nContent-Length: %ld\nContent-Type: text/plain\n\nHello, World!\n", strlen("Hello, World!\n"));
    if (write(clientsockfd, response, strlen(response)) < 0) {
      perror("Error writing HTTP response");
      close(clientsockfd);
      exit(1);
    }

    // Close the connection to the client
    close(clientsockfd);
  }

  // Close the server socket
  close(sockfd);

  return 0;
}