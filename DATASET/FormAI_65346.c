//FormAI DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, n, sum = 0;
  srand(time(NULL)); // seed random number generator with current time
  
  printf("Enter the number of dice you want to roll: ");
  scanf("%d", &n);
  
  printf("Rolling %d dice...\n\n", n); 
  for (i = 1; i <= n; i++) {
    int roll = rand() % 6 + 1;  // Generate random number between 1 and 6
    printf("Dice #%d: %d\n", i, roll);
    sum += roll;  // add each roll to the total sum
  }
  
  printf("\nTotal sum: %d", sum);
  
  return 0;
}