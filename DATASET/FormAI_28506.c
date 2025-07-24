//FormAI DATASET v1.0 Category: Dice Roller ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int sides, rolls, i;
  char again = 'y';
  
  srand(time(NULL));
  
  printf("Welcome to the Dice Roller!\n");
  
  while(again == 'y') {
  
    printf("\nHow many sides does your dice have?: ");
    scanf("%d", &sides);
    
    printf("# of rolls: ");
    scanf("%d", &rolls);
    
    printf("\n%d rolls of a %d-sided dice:\n", rolls, sides);
    
    for(i=0; i<rolls; i++) {
      printf("%d ", rand() % sides + 1);
    }
    
    printf("\nRoll again? (y/n): ");
    scanf(" %c", &again);
  }
  
  printf("\nThanks for using the Dice Roller!\n");
  
  return 0;
}