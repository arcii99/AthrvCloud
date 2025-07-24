//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DEFAULT_PORT 9000

int main(int argc, char const *argv[]) {
  // Declare variables
  int listenfd, connfd, n;
  struct sockaddr_in servaddr, cliaddr;
  socklen_t len;
  char buf[1024];

  // Create socket
  listenfd = socket(AF_INET, SOCK_STREAM, 0);

  // Prepare server address
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(DEFAULT_PORT);

  // Bind socket to server address
  bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

  // Start listening for connections
  listen(listenfd, 10);
  printf("[INFO] Waiting for incoming connections...\n");

  while(1) {
    // Accept connection
    len = sizeof(cliaddr);
    connfd = accept(listenfd, (struct sockaddr *)&cliaddr, &len);
    printf("[INFO] Accepted connection from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

    // Receive data from client
    n = recv(connfd, buf, 1024, 0);

    // Print received data
    printf("[INFO] Received %d bytes: %s\n", n, buf);

    // Close connection
    close(connfd);
    printf("[INFO] Closed connection from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));
  }

  return 0;
}