//FormAI DATASET v1.0 Category: Dice Roller ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int dice, roll, total=0;
  char choice;
  
  srand(time(NULL));
  
  printf("Welcome to the Dice Roller Program!\n");
  printf("Press any key to begin rolling!\n");
  getchar();
  
  do {
    printf("\nHow many dice would you like to roll? (1-5): ");
    scanf("%d", &dice);
    
    if (dice < 1 || dice > 5) {
      printf("Invalid input.\n");
      continue;
    }
    
    printf("\nRolling %d dice...\n", dice);
    
    for (int i=0; i<dice; i++) {
      roll = rand() % 6 + 1;
      total += roll;
      printf("Dice %d: %d\n", i+1, roll);
    }
    
    printf("\nTotal: %d\n", total);
    total = 0;
    
    printf("\nWould you like to roll again? (Y/N): ");
    scanf(" %c", &choice);
  } while (choice == 'Y' || choice == 'y');
  
  printf("\nThank you for using the Dice Roller Program!\n");
  return 0;
}