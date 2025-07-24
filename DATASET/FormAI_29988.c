//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 1024

void error(char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char **argv){
  if (argc != 2) {
    printf("\nUsage: %s <IP address of IMAP server>\n", argv[0]); // prompt the user for input parameter of IMAP server IP
    exit(1);
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) error("Error opening socket"); // check for proper opening of socket

  struct sockaddr_in servAddr;

  memset(&servAddr, 0, sizeof(servAddr)); // set memory of struct to all 0s

  servAddr.sin_family = AF_INET; // set address family to IPv4
  servAddr.sin_port = htons(143); // set default IMAP port

  if (inet_pton(AF_INET, argv[1], &servAddr.sin_addr) <= 0) {
    error("inet_pton error"); // check for valid IP address
  }

  if (connect(sockfd, (struct sockaddr *)&servAddr, sizeof(servAddr)) == -1) {
    error("Error connecting to server"); // check for successful connection to server
  }

  printf("Connected to IMAP server. \n\nPlease enter your username: ");
  char username[MAXLINE];
  fgets(username, MAXLINE, stdin); // prompt user for username

  printf("Please enter your password: ");
  char password[MAXLINE];
  fgets(password, MAXLINE, stdin); // prompt user for password

  char login[MAXLINE + 10];
  sprintf(login, "01 LOGIN %s%s\r\n", username, password); // concatenate login command with username and password

  if (send(sockfd, login, strlen(login), 0) == -1) {
    error("Error sending login credentials"); // send login credentials to server
  }

  char response[MAXLINE];
  recv(sockfd, response, MAXLINE-1, 0); // receive response from server
  
  if (strncmp(response, "* OK", 4) != 0) {
    printf("Invalid credentials. Closing IMAP connection.\n");
    close(sockfd); // close connection if invalid credentials
    exit(1);
  }

  printf("Login successful.\n");

  return 0;
}