//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER "pop.example.com"
#define PORT 110

void error(char *msg) {
  perror(msg);
  exit(1);
}

int main()
{
  struct sockaddr_in server_addr;
  char buffer[1024], username[50], password[50], msg[1024];
  int sock, bytes_read;

  // create socket
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    error("Could not create socket");

  // configure server socket address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(SERVER);
  server_addr.sin_port = htons(PORT);

  // connect to server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    error("Failed to connect to server");

  // read server response
  if (read(sock, buffer, sizeof(buffer)) < 0)
    error("Failed to read from server");

  printf("Received from server: %s\n", buffer);

  // login to server
  printf("Enter your username: ");
  scanf("%s", username);
  sprintf(msg, "USER %s\r\n", username);
  send(sock, msg, strlen(msg), 0);
  if (read(sock, buffer, sizeof(buffer)) < 0)
    error("Failed to read from server");
  printf("Received from server: %s\n", buffer);

  printf("Enter your password: ");
  scanf("%s", password);
  sprintf(msg, "PASS %s\r\n", password);
  send(sock, msg, strlen(msg), 0);
  if (read(sock, buffer, sizeof(buffer)) < 0)
    error("Failed to read from server");
  printf("Received from server: %s\n", buffer);

  // retrieve email count
  sprintf(msg, "STAT\r\n");
  send(sock, msg, strlen(msg), 0);
  if (read(sock, buffer, sizeof(buffer)) < 0)
    error("Failed to read from server");
  printf("Received from server: %s\n", buffer);

  // retrieve email list
  sprintf(msg, "LIST\r\n");
  send(sock, msg, strlen(msg), 0);
  if (read(sock, buffer, sizeof(buffer)) < 0)
    error("Failed to read from server");
  printf("Received from server: %s\n", buffer);

  // retrieve first email
  sprintf(msg, "RETR 1\r\n");
  send(sock, msg, strlen(msg), 0);
  while ((bytes_read = read(sock, buffer, sizeof(buffer))) > 0)
    printf("%.*s", bytes_read, buffer);
  if (bytes_read < 0)
    error("Failed to read from server");

  // quit connection
  sprintf(msg, "QUIT\r\n");
  send(sock, msg, strlen(msg), 0);

  // close socket
  close(sock);

  return 0;
}