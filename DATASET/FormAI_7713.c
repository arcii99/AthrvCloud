//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: statistical
// Welcome to the SMTP Client Example Program in C
// This program will help you understand how to send a SMTP email in C using sockets
// Let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#define SERVER "smtp.server.com" // Server's IP Address or Hostname
#define PORT 25 // SMTP Port Number

int main() {

  // Step 1: Create a Socket Connection
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    printf("Error: Failed to create a socket.\n");
    exit(1);
  }

  // Step 2: Specify the server address and port
  struct sockaddr_in serverAddr;
  memset(&serverAddr, 0, sizeof(serverAddr));
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_addr.s_addr = inet_addr(SERVER);
  serverAddr.sin_port = htons(PORT);

  // Step 3: Connect the socket to the server
  if(connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
    printf("Error: Failed to connect to the server.\n");
    exit(1);
  }

  // Step 4: Receive a message from the server
  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));
  read(sockfd, buffer, sizeof(buffer) - 1);
  printf("%s", buffer);

  // Step 5: Send a HELO Command to the server
  char* helo = "HELO smtp.client.com\r\n";
  write(sockfd, helo, strlen(helo));
  memset(buffer, 0, sizeof(buffer));
  read(sockfd, buffer, sizeof(buffer) - 1);
  printf("%s", buffer);

  // Step 6: Send a MAIL FROM Command to the server
  char* mailFrom = "MAIL FROM: <sender@gmail.com>\r\n";
  write(sockfd, mailFrom, strlen(mailFrom));
  memset(buffer, 0, sizeof(buffer));
  read(sockfd, buffer, sizeof(buffer) - 1);
  printf("%s", buffer);

  // Step 7: Send a RCPT TO Command to the server
  char* rcptTo = "RCPT TO: <recipient@gmail.com>\r\n";
  write(sockfd, rcptTo, strlen(rcptTo));
  memset(buffer, 0, sizeof(buffer));
  read(sockfd, buffer, sizeof(buffer) - 1);
  printf("%s", buffer);

  // Step 8: Send a DATA Command to the server
  char* data = "DATA\r\n";
  write(sockfd, data, strlen(data));
  memset(buffer, 0, sizeof(buffer));
  read(sockfd, buffer, sizeof(buffer) - 1);
  printf("%s", buffer);

  // Step 9: Send the Email Content to the server
  char* emailContent = "Subject: SMTP email example\r\nFrom: sender@gmail.com\r\nTo: recipient@gmail.com\r\nContent-Type: text/plain\r\n\r\nHello, this is a test email from the SMTP client.\r\n.\r\n";
  write(sockfd, emailContent, strlen(emailContent));
  memset(buffer, 0, sizeof(buffer));
  read(sockfd, buffer, sizeof(buffer) - 1);
  printf("%s", buffer);

  // Step 10: Send a QUIT Command to the server
  char* quit = "QUIT\r\n";
  write(sockfd, quit, strlen(quit));
  close(sockfd);
  
  printf("Email Sent Successfully!\n");

  return 0;
}