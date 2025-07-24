//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char *hostname = argv[1];
  struct hostent *host = NULL;
  struct in_addr **addr_list = NULL;
  int i;

  // get the IP address of the hostname
  host = gethostbyname(hostname);
  if (host == NULL) {
    perror("gethostbyname() failed");
    exit(EXIT_FAILURE);
  }

  // print the IP address(es) for the given hostname
  addr_list = (struct in_addr **)host->h_addr_list;
  for (i = 0; addr_list[i] != NULL; i++) {
    printf("%s\n", inet_ntoa(*addr_list[i]));
  }

  return 0;
}