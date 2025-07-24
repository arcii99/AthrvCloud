//FormAI DATASET v1.0 Category: Network Ping Test ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <signal.h>

#define PACKET_SIZE 4096
#define PORT_NO 0
#define PING_SLEEP_RATE 1000000
#define RECV_TIMEOUT 1

uint16_t pack_seq = 0;

unsigned short checksum(void* b, int len) {
  unsigned short* buf = b;
  unsigned int sum = 0;
   unsigned short result;
  for (sum = 0; len > 1; len -= 2) {
    sum += *buf++;
  }
  if (len == 1) {
    sum += *(unsigned char*)buf;
  }
  sum = (sum >> 16) + (sum & 0xFFFF);
  sum += (sum >> 16);
  result = ~sum;
  return result;
}

void intHandler(int sig) {
  printf("\nCTRL-C signal received! Exiting program...\n");
  exit(0);
}

void ping(struct sockaddr* addr, char* target_hostname) {
  int sock, flag = 1, pid;
  struct sockaddr_in* addr_in = (struct sockaddr_in*)addr;
  struct timeval tv_out = { RECV_TIMEOUT, 0 };
  struct icmp* icmp_hdr;
  char sendpacket[PACKET_SIZE];
  char recvpacket[PACKET_SIZE];
  int ping_len, msg_count = 0, msg_received_count = 0, i, recv_msg_len;
  socklen_t addr_len = sizeof(struct sockaddr_in);
  pid = getpid();
  memset(recvpacket, 0, sizeof(recvpacket));
  sock = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP);
  if (sock < 0) {
    printf("Socket Error! Exiting program...\n");
    exit(0);
  }
  setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv_out, sizeof(tv_out));
  icmp_hdr = (struct icmp*)sendpacket;
  icmp_hdr->icmp_type = ICMP_ECHO;  // Requesting an ICMP ECHO
  icmp_hdr->icmp_code = 0;
  icmp_hdr->icmp_seq = pack_seq++;
  icmp_hdr->icmp_id = pid;
  ping_len = 8 + 56;  // Header is 8 bytes, body is 56 bytes
  while (flag) {
    if (msg_received_count == 4) {
      printf("%s is AVAILABLE!\n", target_hostname);
      flag = 0;
      break;
    }
    bzero(recvpacket, sizeof(recvpacket));
    msg_count++;
    usleep(PING_SLEEP_RATE);
    icmp_hdr->icmp_seq = pack_seq++;
    icmp_hdr->icmp_cksum = 0;
    icmp_hdr->icmp_cksum = checksum((unsigned short*)icmp_hdr, ping_len);
    if (sendto(sock, sendpacket, ping_len, 0, (struct sockaddr*)addr_in, addr_len) < 0) {
      printf("Packet Sending Failed! Exiting program...\n");
      exit(0);
    }
    if ((recv_msg_len = recvfrom(sock, recvpacket, sizeof(recvpacket), 0, (struct sockaddr*)addr_in, &addr_len)) < 0) {
      // Request Timed Out
      printf("REQUEST TIMED OUT!\n");
    }
    else {
      msg_received_count++;
      printf("PING RESPONSE RECEIVED!\n");
    }
  }
  close(sock);
}

int main(int argc, char* argv[]) {
  struct sigaction sa;
  sa.sa_handler = intHandler;
  sa.sa_flags = 0;
  sigemptyset(&sa.sa_mask);
  if (sigaction(SIGINT, &sa, NULL) == -1) {
    printf("Signal Error! Exiting program...\n");
    exit(0);
  }
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  char* target = argv[1];
  char target_hostname[50];
  sprintf(target_hostname, "%s.com", target);
  printf("Pinging %s...\n", target_hostname);
  if (inet_aton(target, &(addr.sin_addr)) == 0) {
    printf("Invalid IP! Exiting program...\n");
    exit(0);
  }
  ping((struct sockaddr*)&addr, target_hostname);
  return 0;
}