//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: ephemeral
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>

#define PORT 993

int main(){
  /* Create socket endpoint */
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if(sock < 0){
    printf("Could not create socket\n");
    return 1;
  }

  /* Server Connection setup */
  struct sockaddr_in server;
  server.sin_addr.s_addr = inet_addr("imap.gmail.com");
  server.sin_family = AF_INET;
  server.sin_port = htons(PORT);
  
  /* Connect to the server */
  if(connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0){
    printf("Could not connect to server\n");
    return 1;
  }

  /* Login to account */
  char login_cmd[100];
  sprintf(login_cmd, "LOGIN username password\n");
  send(sock, login_cmd, strlen(login_cmd), 0);

  /* Get response from server */
  char buffer[1000];
  recv(sock, buffer, 1000, 0);

  /* Successful Login */
  if(strstr(buffer, "OK") != NULL){
    printf("Login successful!\n");

    /* List all mailboxes in the account */
    char list_cmd[100];
    sprintf(list_cmd, "LIST \"\" *\n");
    send(sock, list_cmd, strlen(list_cmd), 0);

    /* Get mailbox list from server */
    recv(sock, buffer, 1000, 0);
    printf("Mailboxes in your account: %s\n", buffer);

    /* Select a mailbox */
    char select_cmd[100];
    sprintf(select_cmd, "SELECT INBOX\n");
    send(sock, select_cmd, strlen(select_cmd), 0);

    /* Get selected mailbox response from server */
    recv(sock, buffer, 1000, 0);

    /* Count number of mails in selected mailbox */
    char count_cmd[100];
    sprintf(count_cmd, "SEARCH 1:*\n");
    send(sock, count_cmd, strlen(count_cmd), 0);

    /* Get mail count response from server */
    recv(sock, buffer, 1000, 0);

    /* Print mail count to user */
    printf("Number of mails in INBOX: %s\n", buffer);

    /* Logout from account */
    char logout_cmd[100];
    sprintf(logout_cmd, "LOGOUT\n");
    send(sock, logout_cmd, strlen(logout_cmd), 0);

    /* Get logout response from server */
    recv(sock, buffer, 1000, 0);
    printf("Logged out successfully\n");
  } 
  /* Login failed */
  else{
    printf("Could not login to account\n");
  }

  /* Close socket */
  close(sock);

  return 0;
}