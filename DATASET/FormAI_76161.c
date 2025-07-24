//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// function to detect intrusion
void detect_intrusion() {
  printf("Intrusion detected! Sending notification to authorities...\n");
  printf("Calling the police...\n"); 
  printf("Oh wait, let's play a prank on them first!\n");
  
  // random number generator for selecting prank
  srand(time(NULL));
  int prank_num = rand() % 4;
  
  switch(prank_num) {
    case 0:
      printf("Sending authorities on a wild goose chase...who doesn't love a good scavenger hunt?\n");
      break;
    case 1:
      printf("Releasing some balloons to confuse the authorities...\n");
      break;
    case 2:
      printf("Changing all the door locks and watching authorities try to get in...\n");
      break;
    case 3:
      printf("Starting a game of hide-and-seek...winner gets to go home!\n");
      break;
    default:
      printf("Uh oh...looks like the prank generator is broken...abort mission!\n");
  }
}

int main() {
  printf("Starting intrusion detection system...\n");
  printf("Scanning for any suspicious activity...\n");
  printf("...");
  
  // random number generator for simulating intrusion
  srand(time(NULL));
  int detected = rand() % 2;
  
  if (detected) {
    detect_intrusion();
  } else {
    printf("No intrusion detected...guess we'll just sit here and wait for something to happen...\n");
  }
  
  return 0;
}