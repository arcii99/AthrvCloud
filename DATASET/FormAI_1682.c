//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: creative
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  int client_socket;
  struct sockaddr_in server_addr;
  char buffer[1024];

  // Create socket
  if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("\nSocket creation error.\n");
    return -1;
  }

  // Set server address
  memset(&server_addr, '0', sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(25); // Default SMTP port
  if (inet_pton(AF_INET, "0.0.0.0", &server_addr.sin_addr) <= 0) {
    printf("\nInvalid address or address not supported.\n");
    return -1;
  }

  // Connect to server
  if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    printf("\nConnection failed.\n");
    return -1;
  }

  // Sending hello message
  sprintf(buffer, "HELO example.com\r\n");
  if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
    printf("\nMessage sending failed.\n");
    return -1;
  }

  // Receiving server response
  if (recv(client_socket, buffer, 1024, 0) < 0) {
    printf("\nResponse receiving failed.\n");
    return -1;
  }
  printf("Server says: %s", buffer);

  // Sending mail from address
  sprintf(buffer, "MAIL FROM: your_email@example.com\r\n");
  if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
    printf("\nMessage sending failed.\n");
    return -1;
  }

  // Receiving server response
  if (recv(client_socket, buffer, 1024, 0) < 0) {
    printf("\nResponse receiving failed.\n");
    return -1;
  }
  printf("Server says: %s", buffer);

  // Sending mail to address
  sprintf(buffer, "RCPT TO: recipient_email@example.com\r\n");
  if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
    printf("\nMessage sending failed.\n");
    return -1;
  }

  // Receiving server response
  if (recv(client_socket, buffer, 1024, 0) < 0) {
    printf("\nResponse receiving failed.\n");
    return -1;
  }
  printf("Server says: %s", buffer);

  // Sending message data
  sprintf(buffer, "DATA\r\n");
  if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
    printf("\nMessage sending failed.\n");
    return -1;
  }

  // Receiving server response
  if (recv(client_socket, buffer, 1024, 0) < 0) {
    printf("\nResponse receiving failed.\n");
    return -1;
  }
  printf("Server says: %s", buffer);

  // Sending message body
  sprintf(buffer, "From: your_email@example.com\r\n"
                  "To: recipient_email@example.com\r\n"
                  "Subject: Test message\r\n\r\n"
                  "This is a test message.\r\n.\r\n");
  if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
    printf("\nMessage sending failed.\n");
    return -1;
  }

  // Receiving server response
  if (recv(client_socket, buffer, 1024, 0) < 0) {
    printf("\nResponse receiving failed.\n");
    return -1;
  }
  printf("Server says: %s", buffer);

  // Sending QUIT command
  sprintf(buffer, "QUIT\r\n");
  if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
    printf("\nMessage sending failed.\n");
    return -1;
  }

  // Receiving server response
  if (recv(client_socket, buffer, 1024, 0) < 0) {
    printf("\nResponse receiving failed.\n");
    return -1;
  }
  printf("Server says: %s", buffer);

  // Close socket
  close(client_socket);

  return 0;
}