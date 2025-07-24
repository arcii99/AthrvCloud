//FormAI DATASET v1.0 Category: Firewall ; Style: recursive
#include <stdio.h>
#include <string.h>

void checkFirewall(char packet[], int index) {
  if (packet[index] == '\0') {
    printf("Packet allowed: %s\n", packet);
    return;
  }

  if (packet[index] == 'A' && index < 4) {
    printf("Checking rule %d: %c allowed\n", index + 1, packet[index]);
    checkFirewall(packet, index + 1);
  } else if (packet[index] == 'B' && index >= 4 && index < 8) {
    printf("Checking rule %d: %c allowed\n", index + 1, packet[index]);
    checkFirewall(packet, index + 1);
  } else {
    printf("Packet blocked: %s\n", packet);
    return;
  }
}

int main() {
  char packet1[] = "ABBBAA";
  char packet2[] = "BBBAAA";
  char packet3[] = "ABBBBBAAAA";
  
  checkFirewall(packet1, 0);
  checkFirewall(packet2, 0);
  checkFirewall(packet3, 0);

  return 0;
}