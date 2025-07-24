//FormAI DATASET v1.0 Category: Port Scanner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {// user needs to provide an argument
    printf("Usage: %s <host>\n", argv[0]);
    return -1;
  }

  char *host = argv[1];

  int sock;
  struct sockaddr_in target;

  for (int port = 1; port <= 65535; port++) {// scanning through all possible ports
    sock = socket(AF_INET, SOCK_STREAM, 0);

    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    target.sin_addr.s_addr = inet_addr(host);

    if (connect(sock, (struct sockaddr *)&target, sizeof target) == 0) {// connect to open ports
      printf("Port %d - OPEN\n", port);
      close(sock);
    } else {
      close(sock);
    }
  }

  printf("Scan complete\n");

  return 0;
}