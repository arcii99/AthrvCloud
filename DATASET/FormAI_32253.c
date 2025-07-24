//FormAI DATASET v1.0 Category: Email Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_SIZE 1024

char* recv_buffer[MAX_SIZE];
char* send_buffer[MAX_SIZE];

int create_socket(char* server, int port) {
  int sock;
  struct sockaddr_in server_addr;
  struct hostent* hp;

  sock = socket(AF_INET, SOCK_STREAM, 0);
  
  if(sock < 0) {
    printf("Failed to create socket\n");
    exit(1);
  }
  
  hp = gethostbyname(server);
  
  if(hp == NULL) {
    printf("No such host\n");
    exit(1);
  }

  memset((char*)&server_addr, 0, sizeof(server_addr));

  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr = *((struct in_addr*)hp->h_addr);
  
  if(connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    printf("Failed to connect\n");
    exit(1);
  }

  return sock;
}

int send_message(int sock, char* message) {
  sprintf(send_buffer, "%s\r\n", message);

  if(send(sock, send_buffer, strlen(send_buffer), 0) < 0) {      
    printf("Failed to send message\n");
    return -1;
  }

  return 0;
}

char* recv_message(int sock) {
  memset(recv_buffer, 0, MAX_SIZE);

  if(recv(sock, recv_buffer, MAX_SIZE, 0) < 0) {
    printf("Failed to receive message\n");
    return NULL;
  }

  return recv_buffer;
}

void send_email(char* server, int port, char* sender, char* recipient, char* subject, char* body) {
  int sock = create_socket(server, port);
  
  recv_message(sock);
  send_message(sock, "EHLO example.com");

  do {
    char* response = recv_message(sock);
  } while(strncmp(recv_buffer, "250 ", 4) != 0);

  sprintf(send_buffer, "MAIL FROM:<%s>", sender);
  send_message(sock, send_buffer);

  do {
    char* response = recv_message(sock);
  } while(strncmp(recv_buffer, "250 ", 4) != 0);

  sprintf(send_buffer, "RCPT TO:<%s>", recipient);
  send_message(sock, send_buffer);

  do {
    char* response = recv_message(sock);
  } while(strncmp(recv_buffer, "250 ", 4) != 0);

  send_message(sock, "DATA");

  do {
    char* response = recv_message(sock);
  } while(strncmp(recv_buffer, "354 ", 4) != 0);

  sprintf(send_buffer, "Subject: %s\n%s\n.", subject, body);
  send_message(sock, send_buffer);

  do {
    char* response = recv_message(sock);
  } while(strncmp(recv_buffer, "250 ", 4) != 0);

  send_message(sock, "QUIT");

  do {
    char* response = recv_message(sock);
  } while(strncmp(recv_buffer, "221 ", 4) != 0);

  close(sock);
}

int main() {
  send_email("smtp.gmail.com", 587, "example@gmail.com", "recipient@example.com", "Test Email Subject", "This is a test email body");
  return 0;
}