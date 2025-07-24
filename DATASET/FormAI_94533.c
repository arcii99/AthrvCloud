//FormAI DATASET v1.0 Category: Firewall ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Packet {
  char srcIP[16];
  char dstIP[16];
  int srcPort;
  int dstPort;
  char protocol[4];
};

struct Rule {
  char srcIP[16];
  char dstIP[16];
  int srcPort;
  int dstPort;
  char protocol[4];
  char action[8];
};

int main() {
  srand(time(NULL));
  
  // Generate sample rules
  struct Rule rules[5];
  strncpy(rules[0].srcIP, "192.168.1.1", sizeof(rules[0].srcIP));
  strncpy(rules[0].dstIP, "192.168.2.2", sizeof(rules[0].dstIP));
  rules[0].srcPort = 1024 + rand() % 64511;
  rules[0].dstPort = 80;
  strncpy(rules[0].protocol, "TCP", sizeof(rules[0].protocol));
  strncpy(rules[0].action, "ALLOW", sizeof(rules[0].action));

  strncpy(rules[1].srcIP, "192.168.2.2", sizeof(rules[1].srcIP));
  strncpy(rules[1].dstIP, "192.168.1.1", sizeof(rules[1].dstIP));
  rules[1].srcPort = 80;
  rules[1].dstPort = 1024 + rand() % 64511;
  strncpy(rules[1].protocol, "TCP", sizeof(rules[1].protocol));
  strncpy(rules[1].action, "ALLOW", sizeof(rules[1].action));

  strncpy(rules[2].srcIP, "192.168.1.3", sizeof(rules[2].srcIP));
  strncpy(rules[2].dstIP, "192.168.2.2", sizeof(rules[2].dstIP));
  rules[2].srcPort = 1024 + rand() % 64511;
  rules[2].dstPort = 22;
  strncpy(rules[2].protocol, "TCP", sizeof(rules[2].protocol));
  strncpy(rules[2].action, "BLOCK", sizeof(rules[2].action));

  strncpy(rules[3].srcIP, "192.168.2.2", sizeof(rules[3].srcIP));
  strncpy(rules[3].dstIP, "192.168.1.3", sizeof(rules[3].dstIP));
  rules[3].srcPort = 22;
  rules[3].dstPort = 1024 + rand() % 64511;
  strncpy(rules[3].protocol, "TCP", sizeof(rules[3].protocol));
  strncpy(rules[3].action, "ALLOW", sizeof(rules[3].action));

  strncpy(rules[4].srcIP, "192.168.1.4", sizeof(rules[4].srcIP));
  strncpy(rules[4].dstIP, "192.168.2.2", sizeof(rules[4].dstIP));
  rules[4].srcPort = 1024 + rand() % 64511;
  rules[4].dstPort = 443;
  strncpy(rules[4].protocol, "TCP", sizeof(rules[4].protocol));
  strncpy(rules[4].action, "ALLOW", sizeof(rules[4].action));
  
  // Main loop
  while(1) {
    struct Packet pkt;
    printf("Enter source IP: ");
    scanf("%s", pkt.srcIP);
    printf("Enter destination IP: ");
    scanf("%s", pkt.dstIP);
    printf("Enter source port: ");
    scanf("%d", &pkt.srcPort);
    printf("Enter destination port: ");
    scanf("%d", &pkt.dstPort);
    printf("Enter protocol (TCP/UDP): ");
    scanf("%s", pkt.protocol);

    int allowed = 0;
    for(int i=0; i<5; i++) {
      if(strcmp(pkt.srcIP, rules[i].srcIP) == 0 && strcmp(pkt.dstIP, rules[i].dstIP) == 0 &&
         pkt.srcPort == rules[i].srcPort && pkt.dstPort == rules[i].dstPort &&
         strcmp(pkt.protocol, rules[i].protocol) == 0) {
        if(strcmp(rules[i].action, "ALLOW") == 0) {
          allowed = 1;
          break;
        } else {
          allowed = -1;
          break;
        }
      }
    }
    
    if(allowed == 1) {
      printf("Packet allowed!\n");
    } else {
      printf("Packet blocked!\n");
    }
  }

  return 0;
}