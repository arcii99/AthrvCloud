//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PACKET_SIZE 65535

typedef struct Packet {
  char data[MAX_PACKET_SIZE];
  int size;
} Packet;

typedef struct IPHeader {
  char sourceIP[16];
  char destIP[16];
} IPHeader;

void parsePacket(Packet packet) {
  if (packet.size <= sizeof(IPHeader)) {
    printf("[INTRUSION DETECTED] Packet size too small\n");
    return;
  }

  IPHeader* header = (IPHeader*) packet.data;
  if (strcmp(header->destIP, "198.51.100.1") != 0) {
    printf("[INTRUSION DETECTED] Invalid destination IP address\n");
    return;
  }

  // Check for known malicious payload
  char* payload = packet.data + sizeof(IPHeader);
  if (strstr(payload, "malware") != NULL) {
    printf("[INTRUSION DETECTED] Malware payload detected\n");
    return;
  }

  printf("Valid packet received\n");
}

int main() {
  Packet packet1;
  packet1.size = sizeof(IPHeader) + 10;
  strcpy(packet1.data, "192.168.1.1\0\0\0\0\0\0\0\0198.51.100.1");
  parsePacket(packet1);

  Packet packet2;
  packet2.size = sizeof(IPHeader) + 10;
  strcpy(packet2.data, "192.168.1.1\0\0\0\0\0\0\0\0198.51.200.1");
  parsePacket(packet2);

  Packet packet3;
  packet3.size = sizeof(IPHeader) + 15;
  strcpy(packet3.data, "192.168.1.1\0\0\0\0\0\0\0\0198.51.100.1malware");
  parsePacket(packet3);

  return 0;
}