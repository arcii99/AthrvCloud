//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_SIZE 2048

const char *IMAP_SERVER = "imap.gmail.com";
const int IMAP_PORT = 993;
const char *USER_EMAIL = "example@gmail.com";
const char *USER_PASSWORD = "password123";
const char *INBOX = "INBOX";

int main() {
  // Create a socket for communication
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Connect to the IMAP server
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr(IMAP_SERVER);
  server_address.sin_port = htons(IMAP_PORT);

  if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  // Authenticate the user with their email and password
  char auth_buffer[MAX_SIZE];
  sprintf(auth_buffer, "a001 LOGIN %s %s\r\n", USER_EMAIL, USER_PASSWORD);
  send(socket_fd, auth_buffer, strlen(auth_buffer), 0);

  char server_response[MAX_SIZE];
  recv(socket_fd, server_response, MAX_SIZE, 0);
  if (strstr(server_response, "OK") == NULL) {
    perror("Error with authentication");
    exit(1);
  }

  // Fetch messages from the inbox
  char fetch_buffer[MAX_SIZE];
  sprintf(fetch_buffer, "a002 SELECT %s\r\n", INBOX);
  send(socket_fd, fetch_buffer, strlen(fetch_buffer), 0);
  recv(socket_fd, server_response, MAX_SIZE, 0);

  sprintf(fetch_buffer, "a003 FETCH 1:* BODY[]\r\n");
  send(socket_fd, fetch_buffer, strlen(fetch_buffer), 0);

  bool message_started = false;
  char message_buffer[MAX_SIZE];
  memset(message_buffer, 0, MAX_SIZE);
  while (true) {
    recv(socket_fd, server_response, MAX_SIZE, 0);

    if (strstr(server_response, "FETCH") != NULL) {
      // Start of a new message
      message_started = true;
    } else if (strstr(server_response, "OK.") != NULL) {
      // End of message
      message_started = false;
      printf("%s\n", message_buffer);
      memset(message_buffer, 0, MAX_SIZE);
    }

    if (message_started) {
      strncat(message_buffer, server_response, strlen(server_response));
    }

    if (strstr(server_response, "OK FETCH") != NULL) {
      // All messages fetched, break out of loop
      break;
    }
  }

  // Close the connection
  sprintf(auth_buffer, "a004 LOGOUT\r\n");
  send(socket_fd, auth_buffer, strlen(auth_buffer), 0);

  close(socket_fd);
  return 0;
}