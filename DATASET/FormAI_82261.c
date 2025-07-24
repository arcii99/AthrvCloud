//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: funny
#include <stdio.h>

int main() {
  printf("Hi there! I'm your personal C Disk space analyzer. Let's get started!\n");
  int total_size = 0;
  int used_size = 0;
  int free_size = 0;

  printf("Checking your C Disk...\n");

  // Simulate disk checking
  for (int i = 0; i < 10; i++) {
    printf("Scanning files on partition C... %d%%\n", i*10);
  }

  printf("Analysis complete!\n");

  // Simulate disk space
  total_size = 1000;
  used_size = 750;
  free_size = 250;

  printf("Here's the breakdown of your C Disk space:\n");
  printf("Total size: %d MB\n", total_size);
  printf("Used space: %d MB\n", used_size);
  printf("Free space: %d MB\n", free_size);

  printf("\n");

  // Check if disk is full
  if (used_size == total_size) {
    printf("Uh oh, looks like your C Disk is completely full. Time to do some cleaning up!\n");
  } else {
    printf("You still have %d MB of free space left. Hooray!\n", free_size);
  }

  return 0;
}