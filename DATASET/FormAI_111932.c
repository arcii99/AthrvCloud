//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_BUFFER_SIZE 4096

void print_error(const char *msg) {
  fprintf(stderr, "Error: %s\n", msg);
  exit(1);
}

void read_data(int sock) {
  char buffer[MAX_BUFFER_SIZE];
  while (recv(sock, buffer, sizeof(buffer), 0) > 0) {
    printf("%s", buffer);
    memset(buffer, 0, sizeof(buffer));  // clear buffer
  }
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    print_error("usage: pop3_client hostname port username");
  }
  
  char *hostname = argv[1];
  char *port = argv[2];
  char *username = argv[3];

  struct hostent *server = gethostbyname(hostname);
  if (server == NULL) {
    print_error("unable to resolve hostname");
  }

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    print_error("unable to create socket");
  }

  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  serv_addr.sin_port = htons(atoi(port));

  if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    print_error("unable to connect to server");
  }

  char buffer[MAX_BUFFER_SIZE];
  read_data(sock);

  sprintf(buffer, "USER %s\r\n", username);
  if (send(sock, buffer, strlen(buffer), 0) < 0) {
    print_error("unable to send USER command");
  }

  read_data(sock);

  sprintf(buffer, "PASS %s\r\n", getpass("Password:"));
  if (send(sock, buffer, strlen(buffer), 0) < 0) {
    print_error("unable to send PASS command");
  }

  read_data(sock);

  sprintf(buffer, "QUIT\r\n");
  if (send(sock, buffer, strlen(buffer), 0) < 0) {
    print_error("unable to send QUIT command");
  }

  read_data(sock);

  close(sock);
  return 0;
}