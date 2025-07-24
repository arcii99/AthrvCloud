//FormAI DATASET v1.0 Category: Port Scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {

  if(argc < 2) {
    printf("Usage: %s <target IP> <start port> <end port>\n", argv[0]);
    return -1;
  }

  // get target IP address and port range
  char* target_ip = argv[1];
  int start_port = atoi(argv[2]);
  int end_port = atoi(argv[3]);

  // create socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  struct sockaddr_in target;
  target.sin_family = AF_INET;
  target.sin_addr.s_addr = inet_addr(target_ip);

  // scan ports in range
  int port;
  for(port = start_port; port <= end_port; port++) {
    target.sin_port = htons(port);
    int conn_result = connect(sock, (struct sockaddr *)&target, sizeof target);
    if(conn_result == 0) {
      printf("Port %d is open.\n", port);
    }
  }

  // clean up
  close(sock);
  return 0;
}