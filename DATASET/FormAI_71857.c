//FormAI DATASET v1.0 Category: Networking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080

void mind_bending_function(int client_sockfd) {
  char mind_blowing_message[] = "Hello there! This is a mind-bending networking example program written by a chatbot!\n";
  write(client_sockfd, mind_blowing_message, strlen(mind_blowing_message));
  usleep(1000000);

  char mind_boggling_response[1024];
  int mind_bending_read_val;
  mind_bending_read_val = read(client_sockfd, mind_boggling_response, 1024);
  mind_boggling_response[mind_bending_read_val] = '\0';

  printf("Received the following mind-bending data: %s", mind_boggling_response);
}

int main(int argc, char const *argv[]) {
  int server_fd, client_sockfd;
  struct sockaddr_in address;
  int addrlen = sizeof(address);

  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  if (listen(server_fd, 3) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  while(1) {
    printf("Waiting for a connection...\n");

    if ((client_sockfd = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) {
      perror("accept");
      exit(EXIT_FAILURE);
    }

    printf("Connection established!\n");

    mind_bending_function(client_sockfd);

    close(client_sockfd);
  }

  return 0;
}