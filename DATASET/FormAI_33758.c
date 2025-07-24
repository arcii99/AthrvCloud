//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKETS 1000
#define MAX_PACKET_SIZE 1024

int blocked_ips[MAX_PACKETS];
int num_blocked_ips = 0;

int is_blocked_ip(char* ip_address) {
  int i;
  for (i = 0; i < num_blocked_ips; i++) {
    if (strcmp(blocked_ips[i], ip_address) == 0) {
      return 1;
    }
  }
  return 0;
}

void block_ip(char* ip_address) {
  if (!is_blocked_ip(ip_address)) {
    blocked_ips[num_blocked_ips++] = ip_address;
  }
}

int main() {
  char packets[MAX_PACKETS][MAX_PACKET_SIZE];

  // read in packets
  int num_packets = 0;
  while (fgets(packets[num_packets], MAX_PACKET_SIZE, stdin)) {
    // check for attacks
    if (strstr(packets[num_packets], "GET /root")) {
      char* ip_address_start = strstr(packets[num_packets], "X-Forwarded-For: ") + 17;
      char* ip_address_end = strchr(ip_address_start, '\n');
      char ip_address[MAX_PACKET_SIZE];
      strncpy(ip_address, ip_address_start, ip_address_end - ip_address_start);
      ip_address[ip_address_end - ip_address_start] = '\0';

      if (!is_blocked_ip(ip_address)) {
        printf("Attack detected from IP address %s\n", ip_address);
        block_ip(ip_address);
      }
    }

    // limit number of packets
    num_packets++;
    if (num_packets >= MAX_PACKETS) {
      break;
    }
  }

  printf("Blocked IP addresses:\n");
  int i;
  for (i = 0; i < num_blocked_ips; i++) {
    printf("%s\n", blocked_ips[i]);
  }

  return 0;
}