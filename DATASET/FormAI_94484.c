//FormAI DATASET v1.0 Category: Client Server Application ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

int main() {
   int sockfd;
   char buffer[MAXLINE];
   struct sockaddr_in servaddr;

   // Creating socket file descriptor
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0) {
      perror("Socket creation failed");
      return EXIT_FAILURE;
   }
   
   memset(&servaddr, 0, sizeof(servaddr));

   // Filling server information
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
   servaddr.sin_port = htons(PORT);

   // Connect the client socket to server socket
   if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
      perror("Connection failed");
      return EXIT_FAILURE;
   }

   while (1) {
      printf("Enter a message to send to server: \n");
      fgets(buffer, MAXLINE, stdin);
      send(sockfd, buffer, strlen(buffer), 0);

      if (strncmp("exit", buffer, 4) == 0) {
         printf("Client Exit...\n");
         break;
      }

      memset(buffer, 0, MAXLINE);
      recv(sockfd, buffer, MAXLINE, 0);
      printf("Response from server: %s", buffer);
   }

   // Close the socket
   close(sockfd);

   return EXIT_SUCCESS;
}