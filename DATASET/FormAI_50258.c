//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 65535

int main(int argc, char *argv[]) {
  int sockfd;
  ssize_t n;
  char buffer[MAX_PACKET_SIZE];
  struct sockaddr_in servaddr, cliaddr;

  if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
    perror("socket() error");
    exit(EXIT_FAILURE);
  }

  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(8080);

  if(bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind() error");
    exit(EXIT_FAILURE);
  }

  printf("Listening for packets...\n");

  while(1) {
    socklen_t len = sizeof(cliaddr);
    n = recvfrom(sockfd, buffer, MAX_PACKET_SIZE, 0, (struct sockaddr *)&cliaddr, &len);

    if(n < 0) {
      perror("recvfrom() error");
      exit(EXIT_FAILURE);
    } else {
      char src_addr[INET_ADDRSTRLEN];
      char dst_addr[INET_ADDRSTRLEN];
      inet_ntop(AF_INET, &(cliaddr.sin_addr), src_addr, INET_ADDRSTRLEN);
      inet_ntop(AF_INET, &(servaddr.sin_addr), dst_addr, INET_ADDRSTRLEN);
      printf("Packet from %s:%d to %s:%d size %ld bytes\n", src_addr, ntohs(cliaddr.sin_port), dst_addr, ntohs(servaddr.sin_port), n);
    }
  }
  return 0;
}