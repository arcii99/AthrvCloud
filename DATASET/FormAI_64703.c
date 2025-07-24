//FormAI DATASET v1.0 Category: Firewall ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PACKETS 1000
#define THRESHOLD 500

int main() {
  int packets;
  int count = 0;
  int i;
  srand(time(NULL)); // Initializing the random number generator with time
  printf("Welcome to the Firewall Protection Program\n");
  printf("Enter the number of packets you want to process: ");
  scanf("%d", &packets);

  // Allocate memory for an array that will contain the packet information
  int* packetInfo = (int*)malloc(sizeof(int) * packets);

  // Fill the array with random numbers
  for (i = 0; i < packets; i++) {
    packetInfo[i] = rand() % 1000;
    printf("Packet %d: %d\n", i + 1, packetInfo[i]);
  }

  // Check if the number of packets exceeds the given threshold
  for (i = 0; i < packets; i++) {
    if (packetInfo[i] > THRESHOLD) {
      count++;
    }
  }

  // If the number of packets exceeds the threshold, alarm!
  if (count > MAX_PACKETS) {
    printf("\nALARM! Firewall Protection Breached!! %d suspect packets found\n", count);
  } else {
    printf("\nFirewall protection is working perfectly!! No suspect packets found.\n");
  }

  // Free the dynamically allocated memory
  free(packetInfo);
  packetInfo = NULL;

  return 0;
}