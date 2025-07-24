//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
  int sockfd, n;
  struct sockaddr_in serv_addr;
  char buffer[256];
  
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  serv_addr.sin_port = htons(8080);
  
  connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
  
  sprintf(buffer, "The surreal cat jumped over the purple fence\n");
  
  n = write(sockfd, buffer, strlen(buffer));
  
  if (n < 0) {
    printf("Error writing to socket\n");
    exit(1);
  }
  
  bzero(buffer, 256);
  
  n = read(sockfd, buffer, 255);
  
  if (n < 0) {
    printf("Error reading from socket\n");
    exit(1);
  }
  
  printf("%s\n", buffer);
  
  close(sockfd);
  
  return 0;
}