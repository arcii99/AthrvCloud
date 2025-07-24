//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
  int client_socket;
  struct sockaddr_in server_address;
  char buffer[MAX_BUFFER_SIZE] = {0};

  // Create client socket
  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1)
  {
    printf("Error: Could not create socket.\n");
    return EXIT_FAILURE;
  }

  // Set server address
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1"); // Replace with server IP address
  server_address.sin_port = htons(25);                      // SMTP uses port 25

  // Connect to server
  if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
  {
    printf("Error: Could not connect to server.\n");
    return EXIT_FAILURE;
  }

  // Receive server greeting
  recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
  printf("%s\n", buffer);

  // Send HELO message
  char helo_message[] = "HELO client.example.com\r\n";
  send(client_socket, helo_message, strlen(helo_message), 0);
  recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
  printf("%s\n", buffer);

  // Send MAIL FROM message
  char mail_from_message[] = "MAIL FROM:<user@example.com>\r\n";
  send(client_socket, mail_from_message, strlen(mail_from_message), 0);
  recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
  printf("%s\n", buffer);

  // Send RCPT TO message
  char rcpt_to_message[] = "RCPT TO:<recipient@example.com>\r\n";
  send(client_socket, rcpt_to_message, strlen(rcpt_to_message), 0);
  recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
  printf("%s\n", buffer);

  // Send DATA message
  char data_message[] = "DATA\r\n";
  send(client_socket, data_message, strlen(data_message), 0);
  recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
  printf("%s\n", buffer);

  // Send email message
  char email_message[] = "From: <user@example.com>\r\nTo: <recipient@example.com>\r\nSubject: Test Email\r\n\r\nThis is a test email.\r\n.\r\n";
  send(client_socket, email_message, strlen(email_message), 0);
  recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
  printf("%s\n", buffer);

  // Send QUIT message
  char quit_message[] = "QUIT\r\n";
  send(client_socket, quit_message, strlen(quit_message), 0);
  recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);
  printf("%s\n", buffer);

  // Close socket
  close(client_socket);

  return EXIT_SUCCESS;
}