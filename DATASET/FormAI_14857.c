//FormAI DATASET v1.0 Category: Networking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
  printf("Welcome to my happy networking program!\n");

  int sockfd, connfd;
  struct sockaddr_in address;
  char buffer[BUFFER_SIZE] = {0};

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    printf("Oh no! Socket creation failed...\n");
    return -1;
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(sockfd, (struct sockaddr *)&address, sizeof(address))<0) {
    printf("Oops! Binding failed...\n");
    return -1;
  }

  if (listen(sockfd, 3) < 0) {
    printf("Hmm, listen failed...\n");
    return -1;
  }

  printf("Waiting for a happy client to connect...\n");
  
  if ((connfd = accept(sockfd, (struct sockaddr *)&address, (socklen_t*)&address)) < 0) {
    printf("Aww, failed to accept connection...\n");
    return -1;
  }
  
  printf("Hooray! A connection has been established!\n");

  int valread;
  while ((valread = read(connfd, buffer, BUFFER_SIZE)) > 0) {
    printf("Happy message from client: %s\n", buffer);
    send(connfd, buffer, strlen(buffer), 0);
    bzero(buffer, BUFFER_SIZE);
  }

  printf("Oh no! Connection closed!\n");

  return 0;
}