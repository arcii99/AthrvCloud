//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <net/ethernet.h>
#include <netinet/ip.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

void monitor_packets(){

  int sock_raw = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));

  if(sock_raw < 0){
    perror("Socket Error\n");
    exit(1);
  }

  while(1){

    unsigned char buffer[65536];
    memset(buffer, 0, sizeof(buffer));
    struct sockaddr saddr;
    int saddr_len = sizeof(saddr);
    int buflen = recvfrom(sock_raw, buffer, 65536, 0, &saddr, (socklen_t*)&saddr_len);

    if(buflen < 0){
      perror("Receiving Error\n");
      exit(1);
    }

    struct ethhdr *eth = (struct ethhdr*)(buffer);
    if(ntohs(eth->h_proto) != ETH_P_IP){
      continue;
    }

    struct iphdr *iph = (struct iphdr*)(buffer + sizeof(struct ethhdr));
    struct sockaddr_in source;
    source.sin_addr.s_addr = iph->saddr;
    struct sockaddr_in dest;
    dest.sin_addr.s_addr = iph->daddr;

    if(iph->protocol == IPPROTO_TCP){

      struct tcphdr *tcp = (struct tcphdr*)(buffer + sizeof(struct ethhdr) + sizeof(struct iphdr));
      printf("Source IP: %s\n", inet_ntoa(source.sin_addr));
      printf("Destination IP: %s\n", inet_ntoa(dest.sin_addr));
      printf("Source Port: %d\n", ntohs(tcp->source));
      printf("Destination Port: %d\n", ntohs(tcp->dest));
      printf("\n");

    }

  }

}

int main(){

  printf("Starting packet monitoring...\n\n");
  monitor_packets();

  return 0;

}