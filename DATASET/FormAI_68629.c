//FormAI DATASET v1.0 Category: System boot optimizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Ultimate C System Boot Optimizer!\n\n");
  printf("This program will optimize your computer's startup process and make it lightning-fast!\n");
  printf("Hold on to your hats, folks, because we're about to make your computer BLAZING fast!\n");

  srand(time(NULL)); // initialize random seed

  int numOptimizations, numReboots;
  printf("\nFirst, let's determine how many optimizations you'd like to perform:\n");
  scanf("%d", &numOptimizations);
  
  printf("\nNext, we need to determine how many times you'd like to reboot your computer during this process:\n");
  scanf("%d", &numReboots);
    
  printf("\nOptimizing your computer's startup process...\n\n");
  
  int i;
  for(i = 0; i < numOptimizations; i++) {
    int randomTime = rand() % 5 + 1; // random time between 1 and 5 seconds
    printf("Optimization %d complete! Waiting %d seconds to proceed...\n", i+1, randomTime);
    sleep(randomTime);
  }
  
  printf("\nYour computer has been optimized! Now it's time to reboot %d times to ensure maximum speed!\n", numReboots);
  
  for(i = 0; i < numReboots; i++) {
    printf("\nRebooting computer %d/%d...\n\n", i+1, numReboots);
    sleep(2);
    printf("Welcome back! Your computer is now lightning-fast!\n");
  }
  
  return 0;
}