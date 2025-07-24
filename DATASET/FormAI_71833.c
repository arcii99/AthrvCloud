//FormAI DATASET v1.0 Category: Dice Roller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int rolls, sides, total = 0;
  srand(time(0));
  
  printf("How many dice would you like to roll? ");
  scanf("%d", &rolls);
  
  if (rolls <= 0) {
    printf("Invalid input.\n");
    return 0;
  }
  
  printf("How many sides should each die have? ");
  scanf("%d", &sides);
  
  if (sides <= 0) {
    printf("Invalid input.\n");
    return 0;
  }
  
  printf("Rolling %d %d-sided dice...\n", rolls, sides);
  
  for (int i = 0; i < rolls; i++) {
    int roll = rand() % sides + 1;
    printf("Die %d: %d\n", i + 1, roll);
    total += roll;
  }
  
  printf("Total: %d\n", total);
  
  return 0;
}