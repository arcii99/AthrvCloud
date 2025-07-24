//FormAI DATASET v1.0 Category: Firewall ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// Define a struct for storing packet information
struct Packet {
  char source[50];
  char destination[50];
  int port;
  bool allowed;
};

int main() {

  // Initialize array of allowed ports
  int allowed_ports[] = {22, 80, 443};
  int num_allowed_ports = 3;

  // Initialize array of allowed IPs
  char allowed_ips[][50] = {"192.168.1.1", "10.10.10.10"};
  int num_allowed_ips = 2;

  // Initialize array of blocked IPs
  char blocked_ips[][50] = {"192.168.1.100", "10.0.0.1"};
  int num_blocked_ips = 2;

  // Simulate receiving packets
  struct Packet packet1 = {"192.168.1.2", "8.8.8.8", 22, false};
  struct Packet packet2 = {"10.10.10.10", "192.168.1.3", 80, false};
  struct Packet packet3 = {"192.168.1.100", "10.10.10.10", 443, false};
  struct Packet packet4 = {"10.10.10.10", "192.168.1.100", 4000, false};
  
  struct Packet packets[] = {packet1, packet2, packet3, packet4};
  int num_packets = 4;

  // Loop through packets and check if they are allowed
  for (int i = 0; i < num_packets; i++) {

    struct Packet packet = packets[i];

    // Check if source IP is allowed
    bool source_is_allowed = false;
    for (int j = 0; j < num_allowed_ips; j++) {
      if (strcmp(packet.source, allowed_ips[j]) == 0) {
        source_is_allowed = true;
        break;
      }
    }

    // Check if source IP is blocked
    bool source_is_blocked = false;
    for (int j = 0; j < num_blocked_ips; j++) {
      if (strcmp(packet.source, blocked_ips[j]) == 0) {
        source_is_blocked = true;
        break;
      }
    }

    // Make decision based on source IP and port
    if (source_is_blocked) {
      packet.allowed = false;
    } else if (source_is_allowed && packet.port < 1024) {
      packet.allowed = true;
    } else {
      bool port_is_allowed = false;
      for (int j = 0; j < num_allowed_ports; j++) {
        if (packet.port == allowed_ports[j]) {
          port_is_allowed = true;
          break;
        }
      }
      packet.allowed = port_is_allowed;
    }

    // Print out packet information
    printf("Packet from %s to %s, port %d: ", packet.source, packet.destination, packet.port);
    if (packet.allowed) {
      printf("allowed\n");
    } else {
      printf("blocked\n");
    }

  }

  return 0;
}