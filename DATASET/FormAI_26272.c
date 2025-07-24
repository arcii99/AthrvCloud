//FormAI DATASET v1.0 Category: Client Server Application ; Style: calm
/* A Simple Chat Client-Server Application */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){

  int sockfd, connfd;
  struct sockaddr_in servaddr, cli;
  char buffer[256];
  int n;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Failed to create socket");
    exit(EXIT_FAILURE);
  }
  
  // Set the server address and port
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(8080);
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  
  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
    perror("Failed to connect with server");
    exit(EXIT_FAILURE);
  }
  
  // Communication
  while (1){
    printf("Client: ");
    fgets(buffer, 255, stdin);
    if (strlen(buffer) != 0){
      send(sockfd, buffer, strlen(buffer), 0);
    }
    else{
      printf("Exiting...\n");
      break;
    }
    memset(buffer, 0, sizeof(buffer));
    if ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0){
      printf("Server: %s", buffer);
    }
  }
  
  // Close the socket
  close(sockfd);
  
  return 0;
}