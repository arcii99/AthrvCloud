//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080

int main()
{
  int sockfd, newsockfd, clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int n;
  
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0){
    printf("Error opening socket\n");
    exit(1);
  }
  
  memset(&serv_addr, 0, sizeof(serv_addr));
  
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);
  
  if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0){
    printf("Error on binding\n");
    exit(1);
  }
  
  listen(sockfd, 5);
  printf("Listening for incoming connections...\n");
  
  clilen = sizeof(cli_addr);
  newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
  
  if(newsockfd < 0){
    printf("Error on accept\n");
    exit(1);
  }
  
  printf("Client connection accepted!\n");
  
  while(1){
    memset(buffer, 0, 256);
    n = read(newsockfd, buffer, 255);
    
    if(n < 0){
      printf("Error reading from socket\n");
      exit(1);
    }
    
    printf("Message received from client: %s", buffer);
    
    if(strcmp(buffer, "exit\n") == 0){
      break;
    }
    
    n = write(newsockfd, "I got your message", 18);
    
    if(n < 0){
      printf("Error writing to socket\n");
      exit(1);
    }
  }
  
  close(newsockfd);
  close(sockfd);
  
  return 0;
}