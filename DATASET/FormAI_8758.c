//FormAI DATASET v1.0 Category: Port Scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
  int i, sockfd, start_port, end_port, err;
  struct hostent *host;
  struct sockaddr_in sa;

  if (argc < 4) {
    fprintf(stderr, "Usage: %s <hostname> <start port> <end port>\n", argv[0]);
    exit(1);
  }

  host = gethostbyname(argv[1]);
  if (!host) {
    fprintf(stderr, "Error: Unable to resolve hostname '%s'\n", argv[1]);
    exit(1);
  }

  start_port = atoi(argv[2]);
  end_port = atoi(argv[3]);

  memset(&sa, 0, sizeof(sa));
  sa.sin_family = AF_INET;
  sa.sin_addr.s_addr = *(in_addr_t*)host->h_addr;

  for (i=start_port; i<=end_port; i++) {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
      perror("socket");
      continue;
    }
    sa.sin_port = htons(i);
    err = connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));
    if (err == 0) {
      printf("Port %d is open\n", i);
    }
    close(sockfd);
  }

  printf("Scan completed\n");
  return 0;
}