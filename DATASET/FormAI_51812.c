//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>

#define MAX_ADDR_LENGTH 128

int main(int argc, char *argv[]) {

  struct ifaddrs *ifaddr, *ifa;
  int family, s, n;
  char host[MAX_ADDR_LENGTH];

  if (getifaddrs(&ifaddr) == -1) {
    perror("getifaddrs");
    exit(EXIT_FAILURE);
  }

  printf("Network Topology Mapper\n\n");

  for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
    if (ifa->ifa_addr == NULL) {
      continue;
    }

    family = ifa->ifa_addr->sa_family;

    if (family == AF_INET || family == AF_INET6) {
      s = getnameinfo(ifa->ifa_addr, (family == AF_INET) ? sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6), host, MAX_ADDR_LENGTH, NULL, 0, NI_NUMERICHOST);

      if (s != 0) {
        printf("getnameinfo() failed: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
      }

      printf("%s: %s\n", ifa->ifa_name, host);
    }
  }

  freeifaddrs(ifaddr);
  exit(EXIT_SUCCESS);
}