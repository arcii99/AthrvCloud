//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: network_topology_mapper <host>\n");
    exit(1);
  }

  char *host = argv[1];
  struct addrinfo hints, *res;
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  getaddrinfo(host, "http", &hints, &res);

  int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  connect(sockfd, res->ai_addr, res->ai_addrlen);

  char buffer[BUFFER_SIZE];
  memset(buffer, 0, BUFFER_SIZE);
  
  struct ifaddrs *ifaddr, *ifa;
  struct sockaddr_in *saddr;
  char ip[INET_ADDRSTRLEN];
  getifaddrs(&ifaddr);

  // Print the IP address and the associated interface name for each network interface
  for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
    if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
      saddr = (struct sockaddr_in *)ifa->ifa_addr;
      inet_ntop(AF_INET, &(saddr->sin_addr), ip, INET_ADDRSTRLEN);
      printf("Interface: %-8s IP: %-15s\n", ifa->ifa_name, ip);
    }
  }

  freeifaddrs(ifaddr);
  close(sockfd);

  return 0;
}