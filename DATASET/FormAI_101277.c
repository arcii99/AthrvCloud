//FormAI DATASET v1.0 Category: Networking ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>

int main() {
   int sockfd, new_sockfd, portno, clilen;
   char buffer[256];
   struct sockaddr_in serv_addr, cli_addr;
   int n;
   
   // Create a socket and get a file descriptor
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0) {
      perror("Error opening socket");
      exit(1);
   }
   
   // Zero-out the serv_addr memory space
   bzero((char *) &serv_addr, sizeof(serv_addr));
   
   // Define the port number
   portno = 5001;
   
   // Define the server socket attributes
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(portno);
   
   // Bind the socket file descriptor to the server socket attributes
   if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
      perror("Error binding socket");
      exit(1);
   }
   
   // Listen for incoming connections and queue up to 5
   listen(sockfd, 5);
   clilen = sizeof(cli_addr);
   
   // Accept a client connection and get a new file descriptor
   new_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
   if (new_sockfd < 0) {
      perror("Error accepting client connection");
      exit(1);
   }
   
   // Zero-out the buffer memory space
   bzero(buffer, 256);
   
   // Read from the new file descriptor into the buffer
   n = read(new_sockfd, buffer, 255);
   if (n < 0) {
      perror("Error reading from socket");
      exit(1);
   }
   
   // Print the message to the console
   printf("Message received: %s", buffer);
   
   // Close the file descriptors and exit
   close(new_sockfd);
   close(sockfd);
   return 0;
}