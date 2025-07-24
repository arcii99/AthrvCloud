//FormAI DATASET v1.0 Category: Firewall ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct packet {
   char from_ip[20];
   char to_ip[20];
   int from_port;
   int to_port;
   char protocol[10];
   char data[1024];
};

struct firewall_rule {
   char source_ip_address[20];
   char dest_ip_address[20];
   int source_port;
   int dest_port;
   char protocol[10];
   int action; // 0 = block, 1 = allow
};

#define NUM_RULES 2

struct firewall_rule rule_table[NUM_RULES] = {
   { "192.168.1.100", "8.8.8.8", 0, 0, "UDP", 0 },
   { "192.168.1.101", "8.8.8.8", 0, 0, "UDP", 1 }
};

void apply_firewall_rule(struct packet *pkt) {
   int i;
   for (i = 0; i < NUM_RULES; i++) {
      if (strcmp(pkt->from_ip, rule_table[i].source_ip_address) == 0 &&
          strcmp(pkt->to_ip, rule_table[i].dest_ip_address) == 0 &&
          pkt->from_port == rule_table[i].source_port &&
          pkt->to_port == rule_table[i].dest_port &&
          strcmp(pkt->protocol, rule_table[i].protocol) == 0) {
         if (rule_table[i].action == 0) {
            printf("Packet blocked by firewall!\n");
            exit(1);
         }
         else {
            printf("Packet allowed by firewall.\n");
            return;
         }
      }
   }
   printf("No matching rule found. Packet allowed by default.\n");
}

int main() {
   struct packet pkt;
   
   strcpy(pkt.from_ip, "192.168.1.100");
   strcpy(pkt.to_ip, "8.8.8.8");
   pkt.from_port = 1234;
   pkt.to_port = 5678;
   strcpy(pkt.protocol, "UDP");
   strcpy(pkt.data, "Hello world!");

   apply_firewall_rule(&pkt);

   return 0;
}