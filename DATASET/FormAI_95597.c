//FormAI DATASET v1.0 Category: Simple Web Server ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <arpa/inet.h>

#define PORT 9000
#define MAXSIZE 1024

int main() {
  int sockfd, newsockfd, valread;
  struct sockaddr_in address;
  char buffer[MAXSIZE] = {0};
  int opt = 1;
  int addrlen = sizeof(address);

  // Creating Socket file descriptor
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed");
    exit(1);
  }
  
  // Forcefully attaching socket to the PORT  
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
    perror("setsockopt");
    exit(1);
  }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons( PORT );

  // Forcefully attaching socket to the PORT 
  if (bind(sockfd, (struct sockaddr *)&address, sizeof(address))<0) {
    perror("bind failed");
    exit(1);
  }
  
  if (listen(sockfd, 3) < 0) {
    perror("listen");
    exit(1);
  }

  while(1) {
    printf("\nWaiting for new connections!\n");
    if ((newsockfd = accept(sockfd, (struct sockaddr *)&address,(socklen_t*)&addrlen))<0) {
      perror("accept");
      exit(1);
    }
    
   // Check if request is GET or POST
   valread = read( newsockfd , buffer, MAXSIZE);
   if (strstr(buffer, "GET") == NULL) {
      printf("This is not a GET request!\n");
      return -1;
   } else {
      printf("This is a GET request!\n");
   }
   
    char *response = "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><h1>Welcome to my simple web server!</h1><p>Thank you for connecting!</p></html>";
    send(newsockfd , response , strlen(response) , 0 );
    printf("\nMessage sent to client!\n");
    close(newsockfd);  
  }
  return 0;
}