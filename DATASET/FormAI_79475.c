//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: light-weight
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define BUF_SIZE 8192

void handle_packet(const unsigned char*, int);

int main (int argc, char **argv) {
  uint8_t buffer[BUF_SIZE];
  int sock_raw = 0;
  int read_size = 0;
  int tcp_count = 0;

  struct sockaddr_in source, dest;
    
  sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);

  if(sock_raw < 0) {
    perror("socket");
    exit(1);
  }

  while(1) {
    memset(&buffer, 0, BUF_SIZE);
    read_size = recvfrom(sock_raw, buffer, BUF_SIZE, 0, NULL, NULL);

    if(read_size < 0) {
      perror("recvfrom");
      exit(1);
    }

    handle_packet(buffer, read_size);
  }

  return 0;
}

void handle_packet(const unsigned char* buffer, int size) {
  struct iphdr* ipheader = (struct iphdr*) buffer;
  struct tcphdr* tcpheader = (struct tcphdr*) (buffer + sizeof(struct iphdr));

  if(ipheader->protocol == IPPROTO_TCP) {
    printf("TCP Packet Received\n");
      
    printf("Source Address: %s\n", inet_ntoa(*(struct in_addr*) &ipheader->saddr));
    printf("Destination Address: %s\n", inet_ntoa(*(struct in_addr*) &ipheader->daddr));
    printf("Source Port: %d\n", ntohs(tcpheader->source));
    printf("Destination Port: %d\n", ntohs(tcpheader->dest));
    printf("Sequence Number: %u\n", ntohl(tcpheader->seq));
    printf("Acknowledgment Number: %u\n", ntohl(tcpheader->ack_seq));
      
    if(tcpheader->syn == 1) {
      printf("SYN Packet\n");
    }

    if(tcpheader->fin == 1) {
      printf("FIN Packet\n");
    }

    if(tcpheader->rst == 1) {
      printf("RST Packet\n");
    }

    if(tcpheader->ack == 1) {
      printf("ACK Packet\n");
    }
    printf("\n");
  }
}