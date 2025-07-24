//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: artistic
/* A painting in code */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
  int sockfd, new_sock, read_val;
  struct sockaddr_in serv_addr;
  char art[] = "\n         //\\ \n        //  \\ \n       //    \\ \n      //      \\ \n     //________\\ \n    //          \\ \n   //____________\\ \n  //       ||     \\ \n //        ||      \\ \n//_________||_______\\ \n";
  char *response;
  response = malloc(strlen(art) + 1);
  memset(response, 0, strlen(art) + 1);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);

  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Failed to bind socket");
    exit(EXIT_FAILURE);
  }

  if (listen(sockfd, 3) < 0) {
    perror("Failed to listen for incoming connections");
    exit(EXIT_FAILURE);
  }

  printf("Listening on port %d...\n", PORT);

  while(1) {
    new_sock = accept(sockfd, NULL, NULL);
    if (new_sock < 0) {
      perror("Failed to accept incoming connection");
      exit(EXIT_FAILURE);
    }

    read_val = read(new_sock, response, strlen(art));
    if (read_val < 0) {
      perror("Failed to read from socket");
      exit(EXIT_FAILURE);
    }

    printf("Received request for artwork\n");

    if (strlen(response) == 0) {
      printf("Sending artwork to client\n");
      write(new_sock, art, strlen(art));
    } else {
      printf("Discarding invalid request and closing connection\n");
    }

    close(new_sock);
  }

  free(response);

  return 0;
}