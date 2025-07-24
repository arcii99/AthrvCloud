//FormAI DATASET v1.0 Category: Dice Roller ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int sides;
  int rolls;
  int i;
  int sum = 0;
  
  printf("How many sides does the dice have?: ");
  scanf("%d", &sides);
  
  printf("How many times do you want to roll?: ");
  scanf("%d", &rolls);
  
  printf("Rolling the dice %d times...\n", rolls);
  
  srand(time(0)); // seed the random generator with current time
  
  for(i = 1; i <= rolls; i++) {
    int result = rand() % sides + 1; // generate random number between 1 and sides
    sum += result; // keep track of the sum of all rolls
    printf("Roll %d: %d\n", i, result);
  }
  
  printf("The total sum of the rolls is %d.\n", sum);
  
  return 0;
}