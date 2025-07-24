//FormAI DATASET v1.0 Category: Smart home light control ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 9000
#define MAX_COMMAND_LENGTH 50

int main() {
  int sockfd, newsockfd;
  socklen_t clilen;
  char buffer[MAX_COMMAND_LENGTH];
  struct sockaddr_in serv_addr, cli_addr;
  
  // Create socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }
  
  // Initialize server address
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);
  
  // Bind socket to server address
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }
  
  // Listen for client connections
  listen(sockfd, 5);
  clilen = sizeof(cli_addr);
  
  // Accept client connection
  newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
  if (newsockfd < 0) {
    perror("ERROR on accept");
    exit(1);
  }
  
  // Read commands from client
  while (1) {
    bzero(buffer, MAX_COMMAND_LENGTH);
    read(newsockfd, buffer, MAX_COMMAND_LENGTH);
    
    // Process commands
    if (!strncmp(buffer, "turn on", 7)) {
      // Code to turn on lights
      printf("Turning on lights...\n");
    }
    else if (!strncmp(buffer, "turn off", 8)) {
      // Code to turn off lights
      printf("Turning off lights...\n");
    }
    else if (!strncmp(buffer, "exit", 4)) {
      break;
    }
    else {
      printf("Invalid command\n");
    }
  }
  
  // Close sockets
  close(newsockfd);
  close(sockfd);
  
  return 0;
}