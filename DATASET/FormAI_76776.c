//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char packet[30];
  int packet_len;
  
  printf("O detectors, what creations you do weave,\n");
  printf("In this fair network, where we lay our scene!\n");
  printf("From ancient grudge, break to new mutiny,\n");
  printf("Where intrusion makes civil rules obsolete.\n\n");

  // Intrusion detection system starts here
  while (1) {
    printf("Enter packet data (max 29 characters): ");
    fgets(packet, 30, stdin);
    packet_len = strlen(packet) - 1;
    packet[packet_len] = '\0';

    if (packet_len == 0) {
      printf("Good night, good night! Parting is such sweet sorrow,\n");
      printf("That I shall say good night till it be morrow.\n");
      break;
    }

    if (strstr(packet, "password") != NULL) {
      printf("A plague on both your networks! Intrusion detected.\n");
      printf("This packet contains sensitive information.\n");
    }
    else if (packet_len > 10) {
      printf("What light through yonder network breaks?\n");
      printf("It is the packet, and it is too large!\n");
    }
    else {
      printf("Oh happy dagger, that network code should break!\n");
      printf("This packet is safe to pass through the network.\n");
    }
  }

  return 0;
}