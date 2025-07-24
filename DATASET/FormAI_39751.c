//FormAI DATASET v1.0 Category: Network Ping Test ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <fcntl.h>

#define PORT 8080
#define MAXLINE 1024

int main() {
  char ping[] = "ping";
  char pong[] = "pong";
  char buffer[MAXLINE];

  int listen_fd = 0, conn_fd = 0;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_len;

  // create TCP socket
  listen_fd = socket(AF_INET, SOCK_STREAM, 0);

  memset(&server_addr, '0', sizeof(server_addr));
  memset(buffer, '0', sizeof(buffer));

  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(PORT);

  bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));

  listen(listen_fd, 10);

  printf("Ping server ready.\n");

  while(1) {
    client_len = sizeof(client_addr);
    conn_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &client_len);

    while (recv(conn_fd, buffer, MAXLINE, 0) > 0) {
      if (strcmp(buffer, ping) == 0) {
        printf("Received ping from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        send(conn_fd, pong, strlen(pong), 0);
      } else {
        printf("Received unexpected message: %s\n", buffer);
      }

      memset(buffer, '0', sizeof(buffer));
      close(conn_fd);
      conn_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &client_len);
    }
  }
  return 0;
}