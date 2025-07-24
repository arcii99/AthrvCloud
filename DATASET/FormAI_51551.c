//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(0)); // initialize random seed
  int totalNumOfBags = rand() % 1000 + 1;
  printf("Welcome to the Airport Baggage Handling Simulation! Today, we have %d bags to handle!\n", totalNumOfBags);
  
  // for loop to simulate the baggage handling process
  for(int i = 1; i <= totalNumOfBags; i++) {
    int checkInTime = rand() % 10 + 1;
    int securityTime = rand() % 15 + 1;
    int gateTime = rand() % 5 + 1;
    
    printf("\n Bag %d: Checking in... (%d seconds)", i, checkInTime);
    for(int j = 1; j <= checkInTime; j++) {
      printf(".");
      sleep(1);
    }
    printf("\n Bag %d: Going through security... (%d seconds)", i, securityTime);
    for(int j = 1; j <= securityTime; j++) {
      printf(".");
      sleep(1);
    }
    printf("\n Bag %d: Heading to Gate... (%d seconds)", i, gateTime);
    for(int j = 1; j <= gateTime; j++) {
      printf(".");
      sleep(1);
    }
    printf("\n Bag %d: Arrived at Gate! \n", i);
  }
  
  printf("\nAll bags have been successfully handled. Thank you for using our Baggage Handling service! \n");
  return 0;
}