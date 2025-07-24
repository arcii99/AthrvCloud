//FormAI DATASET v1.0 Category: Networking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main () {

   int sockfd;
   struct sockaddr_in servaddr, cliaddr;

   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd == -1) {
      printf("Could not create socket");
      return 0;
   }
   
   printf("Socket created successfully!\n");
   
   memset(&servaddr, 0, sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr = INADDR_ANY;
   servaddr.sin_port = htons(8080);

   if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
      printf("Could not bind socket");
      return 0;
   }

   printf("Socket bind successful!\n");

   if (listen(sockfd, 5) < 0) {
      printf("Could not listen on socket");
      return 0;
   }

   printf("Socket now listening!\n");

   socklen_t len_cli = sizeof(cliaddr);
   int newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len_cli);
   
   if (newsockfd < 0) {
      printf("Could not accept the connection");
      return 0;
   }

   printf("New connection accepted!\n");

   char buffer[1024];
   memset(buffer, 0, sizeof(buffer));

   printf("Waiting for client message ...\n");
   int n = recv(newsockfd, buffer, sizeof(buffer), 0);
   if (n < 0) {
      printf("Could not receive message");
      return 0;
   }

   printf("Message received from client: %s", buffer);

   char *msg = "Hello from server!";
   n = send(newsockfd, msg, strlen(msg), 0); 

   if (n < 0) {
      printf("Could not send message");
      return 0;
   }   
     
   close(sockfd);
   return 0;
}