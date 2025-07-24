//FormAI DATASET v1.0 Category: Chat server ; Style: automated
// Chat server example program in C

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10

int main(int argc, char const *argv[]) {
  // initializing socket file descriptor
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == 0) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in address;
  memset(&address, 0, sizeof(address));

  // assign IP and port
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // bind the socket to given IP and port
  if (bind(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // listen to connections
  if (listen(sockfd, MAX_CLIENTS) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  // waiting to accept connection
  int addrlen = sizeof(address);
  int new_socket = accept(sockfd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
  if (new_socket < 0) {
    perror("accept");
    exit(EXIT_FAILURE);
  }

  while (1) {
    char buffer[1024] = {0};
    int valread = read(new_socket, buffer, 1024);
    printf("Client : %s\n", buffer);

    if (strncmp(buffer, "bye", 3) == 0) {
      char message[] = "Goodbye!";
      send(new_socket, message, strlen(message), 0);
      break;
    }

    char response[1024] = {0};
    sprintf(response, "Server response : %s", buffer);
    send(new_socket, response, strlen(response), 0);
  }

  close(sockfd);
  return 0;
}