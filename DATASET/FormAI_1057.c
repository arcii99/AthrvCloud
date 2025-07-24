//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

  /* 1. Establish the connection to the mail server */
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  struct hostent *he = gethostbyname("mail.server.com");
  struct sockaddr_in server_addr;
  bzero(&server_addr,sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(993);
  server_addr.sin_addr = *((struct in_addr *)he->h_addr);
  connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  /* 2. Authenticate with the mail server */
  char user_pass[] = "USER myemailaccount.com PASSWORD mypassword\n";
  send(sockfd, user_pass, strlen(user_pass), 0);

  /* 3. Retrieve the email messages */
  char list_msg[] = "LIST\n";
  send(sockfd, list_msg, strlen(list_msg), 0);
  char buffer[1024];
  int n = read(sockfd, buffer, 1024);
  printf("The server sent the data: %s\n", buffer);

  /* 4. Close the connection */
  close(sockfd);

  return 0;
}