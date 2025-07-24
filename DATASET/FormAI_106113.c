//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: thriller
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ether.h>
#include <linux/tcp.h>
#include <linux/ip.h>

void monitor_network() {
  int s, length;
  char buffer[65536];
  struct sockaddr saddr;
  struct in_addr source_ip, dest_ip;
  struct ethhdr *eth;
  struct iphdr *ip_header;
  struct tcphdr *tcp_header;

  s = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));

  if (s < 0) {
    printf("Error. Could not open socket.\n");
  }

  while (1) {
    length = recvfrom(s, buffer, 65536, 0, &saddr, (socklen_t *) &saddr);
    
    if (length < 0) {
      printf("Error. Could not receive packet.\n");
    }

    eth = (struct ethhdr *) buffer;
    ip_header = (struct iphdr *) (buffer + sizeof(struct ethhdr));

    if (ntohs(eth->h_proto) == ETH_P_IP) {

      source_ip.s_addr = ip_header->saddr;
      dest_ip.s_addr = ip_header->daddr;

      if (ip_header->protocol == IPPROTO_TCP) {

        tcp_header = (struct tcphdr *) (buffer + sizeof(struct ethhdr) + sizeof(struct iphdr));

        printf("Incoming packet.\n");
        printf("Source IP: %s\n", inet_ntoa(source_ip));
        printf("Destination IP: %s\n", inet_ntoa(dest_ip));
        printf("Source Port: %d\n", ntohs(tcp_header->source));
        printf("Destination Port: %d\n", ntohs(tcp_header->dest));
        printf("\n");
      }
      
    }

  }

  close(s);

}

int main() {
  printf("Starting network packet monitoring...\n");
  monitor_network();
  return 0;
}