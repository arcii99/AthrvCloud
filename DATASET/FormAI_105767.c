//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main() {
  int sock;
  struct sockaddr_in server;
  char *message, server_reply[BUFFER_SIZE];

  // create socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("Socket creation failed. Error");
    exit(EXIT_FAILURE);
  }
  printf("Socket created.\n");

  // set up server address and port
  server.sin_addr.s_addr = inet_addr("127.0.0.1");
  server.sin_family = AF_INET;
  server.sin_port = htons(25);

  // connect to server
  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("Connection failed. Error");
    exit(EXIT_FAILURE);
  }
  printf("Connected to server.\n");

  // receive server greeting
  if (recv(sock, server_reply, BUFFER_SIZE, 0) < 0) {
    perror("Server reply receive failed. Error");
    exit(EXIT_FAILURE);
  }
  printf("Server greeting: %s\n", server_reply);

  // send email data
  message = "MAIL FROM:<sender@example.com>\r\n"
            "RCPT TO:<recipient@example.com>\r\n"
            "DATA\r\n"
            "Subject: Test Email\r\n"
            "Hello, World!\r\n"
            ".\r\n";
  if (send(sock, message, strlen(message), 0) < 0) {
    perror("Sending message failed. Error");
    exit(EXIT_FAILURE);
  }
  printf("Email sent.\n");

  // receive server response to email
  if (recv(sock, server_reply, BUFFER_SIZE, 0) < 0) {
    perror("Server reply receive failed. Error");
    exit(EXIT_FAILURE);
  }
  printf("Server response: %s\n", server_reply);

  // quit session and close socket
  message = "QUIT\r\n";
  if (send(sock, message, strlen(message), 0) < 0) {
    perror("Sending QUIT failed. Error");
    exit(EXIT_FAILURE);
  }
  printf("Session closed.\n");
  close(sock);

  return 0;
}