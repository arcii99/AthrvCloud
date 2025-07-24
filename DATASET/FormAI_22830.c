//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

int main(int argc, char const *argv[]) {
  int sockfd;
  char buffer[MAXLINE];
  struct sockaddr_in servaddr;

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("Failed to create socket\n");
    exit(EXIT_FAILURE);
  }

  memset(&servaddr, 0, sizeof servaddr);

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);

  if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
    printf("Invalid address/ Address not supported\n");
    exit(EXIT_FAILURE);
  }

  if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
    printf("Connection Failed\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    printf("Message to server: ");
    fgets(buffer, MAXLINE, stdin);

    send(sockfd, buffer, strlen(buffer), 0);

    if (strcmp(buffer, "exit\n") == 0) {
      printf("Closing connection\n");
      break;
    }

    memset(buffer, 0, sizeof buffer);

    if (recv(sockfd, buffer, MAXLINE, 0) < 0) {
      printf("Error in receiving data\n");
      exit(EXIT_FAILURE);
    }

    printf("Message from server: %s\n", buffer);
  }

  close(sockfd);
  return 0;
}