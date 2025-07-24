//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PACKET_SIZE 65536

int main(void) {
  char *buffer = (char*)malloc(MAX_PACKET_SIZE);
  int packet_size, packet_count=0, detected_intrusion=0;

  while (1) {
    packet_count++;
    printf("Enter packet: ");
    fgets(buffer, MAX_PACKET_SIZE, stdin);

    packet_size = strlen(buffer);
    buffer[packet_size-1] = '\0';

    printf("Packet %d: %s\n", packet_count, buffer);

    //	Check for intrusion
    if (strstr(buffer, "hack") != NULL || strstr(buffer, "attack") != NULL) {
      printf("INTRUSION DETECTED!\n");
      detected_intrusion = 1;
    }

    if (packet_count >= 4) {
      printf("\nAnalyzing packets...\n");
      if (detected_intrusion == 1) {
        printf("Intrusion detected in packets %d-%d.\n", packet_count-3, packet_count);
      } else {
        printf("No intrusion detected.\n");
      }
      detected_intrusion = 0;
      packet_count = 0;
      printf("\n");
    }
  }

  free(buffer);
  return 0;
}