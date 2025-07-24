//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to the Network Packet Monitoring program!\n");
  printf("Please make sure you're wearing your packet sniffing hat.\n");

  printf("Initializing monitoring system...\n");
  printf("Please wait, this may take a few moments.\n");

  int packets_monitored = 0;
  int packets_caught = 0;

  while(packets_monitored < 100) {
    printf("Monitoring packet number %d...\n", packets_monitored);
    printf("Packet contents: [NETWORK NOISE]\n");
    packets_monitored++;

    // Randomly catch packets
    int packet_caught = rand() % 2;
    if(packet_caught) {
      printf("Packet number %d has been caught!\n", packets_monitored);
      packets_caught++;
    }
  }

  printf("\nMonitoring complete.\n");
  printf("Packets monitored: %d\n", packets_monitored);
  printf("Packets caught: %d\n", packets_caught);

  if(packets_caught > 50) {
    printf("Looks like we've got a hacker on our hands!\n");
  } else {
    printf("No hackers detected. Time to go home and take a nap.\n");
  }

  return 0;
}