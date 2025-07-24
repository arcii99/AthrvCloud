//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define MAXSIZE 1024

void error(const char *msg) {
   perror(msg);
   exit(1);
}

int main(int argc, char *argv[]) {
   int sockfd, portno, n;
   struct sockaddr_in server_addr;
   char username[50], password[50], buffer[MAXSIZE], command[MAXSIZE];
   portno = 110; // POP3 Port no
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0) {
      error("Error opening socket.");
   }

   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons(portno);
   server_addr.sin_addr.s_addr = inet_addr("POP3 Server IP Address");

   if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
      error("Connection Failed.");
   }

   printf("POP3 Server Connected.\n");

   printf("Enter Username: ");
   fgets(username, 50, stdin);
   printf("Enter Password: ");
   fgets(password, 50, stdin);

   sprintf(command, "USER %s\n", username);
   send(sockfd, command, strlen(command), 0);
   recv(sockfd, buffer, MAXSIZE, 0);
   memset(buffer, 0, MAXSIZE);

   sprintf(command, "PASS %s\n", password);
   send(sockfd, command, strlen(command), 0);
   recv(sockfd, buffer, MAXSIZE, 0);
   memset(buffer, 0, MAXSIZE);

   sprintf(command, "LIST\n");
   send(sockfd, command, strlen(command), 0);
   recv(sockfd, buffer, MAXSIZE, 0);
   printf("%s", buffer);
   memset(buffer, 0, MAXSIZE);

   sprintf(command, "QUIT\n");
   send(sockfd, command, strlen(command), 0);

   printf("Session Terminated.\n");
   close(sockfd);
   return 0;
}