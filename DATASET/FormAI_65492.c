//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 80

int main(int argc, char *argv[]) {
   int sockfd, n;
   struct sockaddr_in serv_addr;
   struct hostent *server;

   char buffer[256];
   if(argc < 2) {
      fprintf(stderr, "Usage %s hostname\n", argv[0]);
      exit(0);
   }
   
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   
   if(sockfd < 0) {
      perror("Error opening socket");
      exit(0);
   }
   
   server = gethostbyname(argv[1]);
   
   if(server == NULL) {
      fprintf(stderr, "Error: No such host exists\n");
      exit(0);
   }

   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
   
   serv_addr.sin_port = htons(PORT);

   if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
      perror("Error connecting");
      exit(0);
   }

   printf("Enter request message\n");
   bzero(buffer,256);
   fgets(buffer,255,stdin);
   
   n = write(sockfd, buffer, strlen(buffer));

   if(n < 0) {
      perror("Error writing to socket");
      exit(0);
   }
   
   bzero(buffer,256);
   n = read(sockfd, buffer, 255);
   
   if(n < 0) {
      perror("Error reading from socket");
      exit(0);
   }
   
   printf("%s\n",buffer);
   
   close(sockfd);
   
   return 0;
}