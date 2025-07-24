//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25 // SMTP port

int main(int argc, char *argv[]) {

   if(argc != 4) {
      fprintf(stderr, "USAGE: %s hostname from_address to_address\n", argv[0]);
      return 1;
   }

   char *hostname = argv[1];
   char *from_address = argv[2];
   char *to_address = argv[3];

   // Create socket
   int sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if(sockfd < 0) {
      perror("socket");
      return 1;
   }

   // Set server address structure
   struct sockaddr_in server_addr;
   memset(&server_addr, 0, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons(PORT);
   if(inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
      fprintf(stderr, "Invalid hostname %s\n", hostname);
      return 1;
   }

   // Connect to server
   if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
      perror("connect");
      return 1;
   }

   // Receive greeting message from server
   char buffer[1024];
   int n = recv(sockfd, buffer, sizeof(buffer), 0);
   if(n < 0) {
      perror("recv");
      return 1;
   }
   printf("%s\n", buffer);

   // Send HELO command to server
   char helo_message[1024];
   sprintf(helo_message, "HELO %s\r\n", hostname);
   if(send(sockfd, helo_message, strlen(helo_message), 0) < 0) {
      perror("send");
      return 1;
   }

   // Receive greeting message from server
   n = recv(sockfd, buffer, sizeof(buffer), 0);
   if(n < 0) {
      perror("recv");
      return 1;
   }
   printf("%s\n", buffer);

   // Send MAIL command to server
   char mail_message[1024];
   sprintf(mail_message, "MAIL FROM:<%s>\r\n", from_address);
   if(send(sockfd, mail_message, strlen(mail_message), 0) < 0) {
      perror("send");
      return 1;
   }

   // Receive response message from server
   n = recv(sockfd, buffer, sizeof(buffer), 0);
   if(n < 0) {
      perror("recv");
      return 1;
   }
   printf("%s\n", buffer);

   // Send RCPT command to server
   char rcpt_message[1024];
   sprintf(rcpt_message, "RCPT TO:<%s>\r\n", to_address);
   if(send(sockfd, rcpt_message, strlen(rcpt_message), 0) < 0) {
      perror("send");
      return 1;
   }

   // Receive response message from server
   n = recv(sockfd, buffer, sizeof(buffer), 0);
   if(n < 0) {
      perror("recv");
      return 1;
   }
   printf("%s\n", buffer);

   // Send DATA command to server
   char data_message[1024];
   sprintf(data_message, "DATA\r\n");
   if(send(sockfd, data_message, strlen(data_message), 0) < 0) {
      perror("send");
      return 1;
   }

   // Receive response message from server
   n = recv(sockfd, buffer, sizeof(buffer), 0);
   if(n < 0) {
      perror("recv");
      return 1;
   }
   printf("%s\n", buffer);

   // Send email contents to server
   char email_message[1024];
   sprintf(email_message, "Subject: SMTP Client Test\r\nFrom: <%s>\r\nTo: <%s>\r\n\r\nThis is a test email sent by a SMTP client.\r\n", from_address, to_address);
   if(send(sockfd, email_message, strlen(email_message), 0) < 0) {
      perror("send");
      return 1;
   }

   // Send end of message character to server
   char eom_message[1024];
   sprintf(eom_message, "\r\n.\r\n");
   if(send(sockfd, eom_message, strlen(eom_message), 0) < 0) {
      perror("send");
      return 1;
   }

   // Receive response message from server
   n = recv(sockfd, buffer, sizeof(buffer), 0);
   if(n < 0) {
      perror("recv");
      return 1;
   }
   printf("%s\n", buffer);

   // Send QUIT command to server
   char quit_message[1024];
   sprintf(quit_message, "QUIT\r\n");
   if(send(sockfd, quit_message, strlen(quit_message), 0) < 0) {
      perror("send");
      return 1;
   }

   // Receive response message from server
   n = recv(sockfd, buffer, sizeof(buffer), 0);
   if(n < 0) {
      perror("recv");
      return 1;
   }
   printf("%s\n", buffer);

   // Close socket
   close(sockfd);

   return 0;
}