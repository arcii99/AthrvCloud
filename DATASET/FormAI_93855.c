//FormAI DATASET v1.0 Category: Simple Web Server ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char** argv) {

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if(sockfd < 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));

  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(8080);

  if(bind(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
    perror("Bind failed");
    exit(EXIT_FAILURE);
  }

  if(listen(sockfd, 5) < 0) {
    perror("Listen failed");
    exit(EXIT_FAILURE);
  }

  printf("Server is running at http://localhost:%d\n", ntohs(server_address.sin_port));

  while(1) {
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);

    int client_sock = accept(sockfd, (struct sockaddr*)&client_address, &client_address_len);

    if(client_sock < 0) {
      perror("Accept failed");
      exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE] = {0};
    read(client_sock, buffer, BUFFER_SIZE);

    printf("Request received: %s\n", buffer);

    char* response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Hello, World!</h1></body></html>\n";

    write(client_sock, response, strlen(response));
    close(client_sock);
  }

  close(sockfd);
  return 0;
}