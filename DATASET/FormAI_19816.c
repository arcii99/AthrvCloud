//FormAI DATASET v1.0 Category: Simple Web Server ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define PORT 8080

int main(int argc, char *argv[]) {
   int sockfd, newsockfd;
   socklen_t clilen;
   char buffer[1024];
   struct sockaddr_in serv_addr, cli_addr;
   int n;

   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0) {
      fprintf(stderr,"ERROR: Failed to open socket.\n");
      exit(1);
   }
   
   // Initialize server address struct
   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_addr.s_addr = INADDR_ANY;
   serv_addr.sin_port = htons(PORT);

   // Bind socket to address/port
   if (bind(sockfd, (struct sockaddr *) &serv_addr,
            sizeof(serv_addr)) < 0) {
      fprintf(stderr, "ERROR: Failed to bind the socket.\n");
      exit(1);
   }

   // Listen for connections
   listen(sockfd,5);
   clilen = sizeof(cli_addr);

   while (1) {
      // Accept incoming connections
      newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
      if (newsockfd < 0) {
         fprintf(stderr, "ERROR: Failed to accept connection.\n");
         exit(1);
      }
      
      // Generate a futuristic response
      bzero(buffer,1024);
      time_t current_time;
      char* c_time_string;
      current_time = time(NULL);
      c_time_string = ctime(&current_time);
      strcat(buffer,"HTTP/1.1 200 OK\n");
      strcat(buffer,"Content-type: text/html\n");
      strcat(buffer,"\n");
      strcat(buffer,"<html><body style=\"background-color: #1C1C1C;\"><h2 style=\"color: #00ff00;\">Welcome to the Future Web Server</h2>");
      strcat(buffer,"<p style=\"color: #ffffff;\">This is the response from the year 2175. The internet is now governed by one global AI called The Provider.</p>");
      strcat(buffer,"<p style=\"color: #ffffff;\">Today's date and time: ");
      strcat(buffer, c_time_string);
      strcat(buffer,"</p></body></html>");
      
      // Send response to client
      n = write(newsockfd,buffer,strlen(buffer));
      if (n < 0) {
         fprintf(stderr, "ERROR: Failed to send response.\n");
         exit(1);
      }
      
      // Close connection
      close(newsockfd);
   }

   close(sockfd);
   return 0;
}