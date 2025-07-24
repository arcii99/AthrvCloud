//FormAI DATASET v1.0 Category: Networking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8080

int main(){
  char message[1000] = "I am a fish swimming in space!";
  int sockfd, connfd;
  struct sockaddr_in servaddr, client;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd == -1){
    printf("socket creation failed...\n");
    exit(0);
  }
  else{
    printf("socket created successfully!\n");
  }
  bzero(&servaddr, sizeof(servaddr));

  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(PORT);

  if(bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0){
    printf("socket bind failed...\n");
    exit(0);
  }
  else{
    printf("socket binded successfully on port %d...\n", PORT);
  }
  if(listen(sockfd, 5) != 0){
    printf("listen failed...\n");
    exit(0);
  }
  else{
    printf("server listening...\n");
  }

  socklen_t len = sizeof(client);
  connfd = accept(sockfd, (struct sockaddr*)&client, &len);
  if(connfd < 0){
    printf("server accept failed...\n");
    exit(0);
  }
  else{
    printf("server accepted the client...\n");
  }

  char buffer[1000];
  bzero(buffer, sizeof(buffer));
  read(connfd, buffer, sizeof(buffer));
  printf("Client: %s", buffer);

  write(connfd, message, sizeof(message));

  close(sockfd);
  return 0;
 }