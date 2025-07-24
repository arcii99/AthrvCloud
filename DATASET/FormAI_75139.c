//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/in.h>
#include <netinet/if_ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

int main (){
  int sockfd = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
  if (sockfd < 0){
    printf("Failed to create socket!\n");
    return 1;
  }
  printf("Packet Monitoring started...\n");

  unsigned char buffer[65536];
  socklen_t sock_len;
  struct sockaddr ll;
  
  while(1){
    int data_size = recvfrom(sockfd, buffer, 65536, 0, &ll, &sock_len);
    if (data_size < 0){
      printf("Failed to recvfrom()!\n");
      return 1;
    }
    printf("Packet received!\n");
    struct ethhdr *eth = (struct ethhdr*) buffer;
    if (ntohs(eth->h_proto) == ETH_P_IP) {
      struct iphdr *ip = (struct iphdr*) (buffer + sizeof(struct ethhdr));
      switch (ip->protocol) {
        case IPPROTO_TCP:
          printf("Protocol: TCP\n");
          struct tcphdr *tcp = (struct tcphdr*) (buffer + sizeof(struct iphdr) + sizeof(struct ethhdr));
          printf("Source Port: %d\t Destination Port: %d\n", ntohs(tcp->source), ntohs(tcp->dest));
          break;
        case IPPROTO_UDP:
          printf("Protocol: UDP\n");
          struct udphdr *udp = (struct udphdr*) (buffer + sizeof(struct iphdr) + sizeof(struct ethhdr));
          printf("Source Port: %d\t Destination Port: %d\n", ntohs(udp->source), ntohs(udp->dest));
          break;
        default:
          printf("Protocol: OTHER\n");
          break;
      }
    }
    printf("\n");
  }
  
  return 0;
}