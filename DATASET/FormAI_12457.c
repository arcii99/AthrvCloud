//FormAI DATASET v1.0 Category: Firewall ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_LIMIT 256

int main(int argc, char const *argv[]) {
  int opt = 1;
  int sockfd , connfd;
  struct sockaddr_in address, addr_cl;
  char buffer[MAX_LIMIT];
  int addrlen = sizeof(address);
  int cl_len = sizeof(addr_cl);
  
  // Creating socket file descriptor
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
      perror("Socket creation failed");
      exit(EXIT_FAILURE);
  }
  
  // Setting socket options
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
      perror("setsockopt failed");
      exit(EXIT_FAILURE);
  }
  
  // Setting socket address
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(8080);
  
  // Bind the socket the given IP and port
  if (bind(sockfd, (struct sockaddr *)&address, sizeof(address))<0) {
      perror("bind failed");
      exit(EXIT_FAILURE);
  }
  
  // Listen to the incoming requests on server
  if (listen(sockfd, 3) < 0) {
      perror("listen failed");
      exit(EXIT_FAILURE);
  }
  
  // Accept incoming connections
  connfd = accept(sockfd, (struct sockaddr *)&addr_cl, (socklen_t*)&cl_len);
  if (connfd<0) {
      perror("accept failed");
      exit(EXIT_FAILURE);
  }
  
  // Read incoming message
  read(connfd, buffer, MAX_LIMIT);
  printf("%s\n",buffer );
  
  // Checking for forbidden words in incoming message
  if ((strstr(buffer, "hack") != NULL) || (strstr(buffer, "attack") != NULL)) {
      char *msg = "Forbidden access\n";
      write(connfd, msg, strlen(msg));
  } 
  else {
      char *msg = "Access granted\n";
      write(connfd, msg, strlen(msg));
  }
  
  // Close the socket
  close(sockfd);
  return 0;
}