//FormAI DATASET v1.0 Category: Email Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER "mail.yourdomain.com"
#define PORT 25

int main(int argc, char *argv[]) {

  char *email_from = "youremail@yourdomain.com";
  char *email_to = "recipient@recipientdomain.com";
  char *smtp_server = SERVER;
  int smtp_port = PORT;
  char *subject = "Test email from C";
  char *body = "This is a sample email sent from a C program";

  // Connect to SMTP server
  int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in server;
  server.sin_addr.s_addr = inet_addr(smtp_server);
  server.sin_family = AF_INET;
  server.sin_port = htons(smtp_port);

  if (connect(socket_desc, (struct sockaddr*) &server, sizeof(server)) < 0) {
    printf("Error: could not connect to server %s:%d\n", smtp_server, smtp_port);
    return -1;
  }

  char buffer[1024];
  recv(socket_desc, buffer, 1024, 0);
  printf("%s\n", buffer);

  // Send HELO command
  sprintf(buffer, "HELO %s\r\n", smtp_server);
  send(socket_desc, buffer, strlen(buffer), 0);
  recv(socket_desc, buffer, 1024, 0);
  printf("%s\n", buffer);

  // Send MAIL FROM command
  sprintf(buffer, "MAIL FROM:<%s>\r\n", email_from);
  send(socket_desc, buffer, strlen(buffer), 0);
  recv(socket_desc, buffer, 1024, 0);
  printf("%s\n", buffer);

  // Send RCPT TO command
  sprintf(buffer, "RCPT TO:<%s>\r\n", email_to);
  send(socket_desc, buffer, strlen(buffer), 0);
  recv(socket_desc, buffer, 1024, 0);
  printf("%s\n", buffer);

  // Send DATA command
  sprintf(buffer, "DATA\r\n");
  send(socket_desc, buffer, strlen(buffer), 0);
  recv(socket_desc, buffer, 1024, 0);
  printf("%s\n", buffer);

  // Send email headers and body
  sprintf(buffer, "From: %s\r\n", email_from);
  send(socket_desc, buffer, strlen(buffer), 0);

  sprintf(buffer, "To: %s\r\n", email_to);
  send(socket_desc, buffer, strlen(buffer), 0);

  sprintf(buffer, "Subject: %s\r\n", subject);
  send(socket_desc, buffer, strlen(buffer), 0);

  sprintf(buffer, "\r\n%s\n.\r\n", body);
  send(socket_desc, buffer, strlen(buffer), 0);
  recv(socket_desc, buffer, 1024, 0);
  printf("%s\n", buffer);

  // Send QUIT command
  sprintf(buffer, "QUIT\r\n");
  send(socket_desc, buffer, strlen(buffer), 0);
  recv(socket_desc, buffer, 1024, 0);
  printf("%s\n", buffer);

  close(socket_desc);

  return 0;
}