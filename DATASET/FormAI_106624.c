//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {

  int sock;
  char buffer[BUFSIZE];
  struct sockaddr_in server_addr;
  char *username = "your-username";
  char *password = "your-password";

  // Create socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("Failed to create socket");
    exit(EXIT_FAILURE);
  }

  // Configure server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(110);
  server_addr.sin_addr.s_addr = inet_addr("pop3.server.com");

  // Connect to server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Failed to connect to server");
    exit(EXIT_FAILURE);
  }

  // Receive greeting message from server
  recv(sock, buffer, BUFSIZE, 0);
  printf("%s\n", buffer);

  // Send username to server
  sprintf(buffer, "USER %s\r\n", username);
  send(sock, buffer, strlen(buffer), 0);
  memset(buffer, '\0', BUFSIZE);
  recv(sock, buffer, BUFSIZE, 0);
  printf("%s\n", buffer);

  // Send password to server
  sprintf(buffer, "PASS %s\r\n", password);
  send(sock, buffer, strlen(buffer), 0);
  memset(buffer, '\0', BUFSIZE);
  recv(sock, buffer, BUFSIZE, 0);
  printf("%s\n", buffer);

  // Request list of mail from server
  send(sock, "LIST\r\n", strlen("LIST\r\n"), 0);
  memset(buffer, '\0', BUFSIZE);
  recv(sock, buffer, BUFSIZE, 0);
  printf("%s\n", buffer);

  // Quit from server
  send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0);
  close(sock);
  return 0;
}