//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_ADDR "smtp.gmail.com"
#define SERVER_PORT 587

int main() {
  int sock;
  struct sockaddr_in server;
  char *msg = "My SMTP client program works!";

  // Create a socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    printf("Socket creation error.");
    exit(-1);
  }
  
  // Specify the server address and port number
  server.sin_addr.s_addr = inet_addr(SERVER_ADDR);
  server.sin_family = AF_INET;
  server.sin_port = htons(SERVER_PORT);

  // Connect to the server
  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    printf("Connection failed.");
    exit(-1);
  }

  // Send the test message to the server
  if (send(sock, msg, strlen(msg), 0) < 0) {
    printf("Message send error.");
    exit(-1);
  }

  // Close the socket
  close(sock);

  return 0;
}