//FormAI DATASET v1.0 Category: Dice Roller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int diceRoll;
  
  srand(time(NULL));
  
  printf("\n\nWelcome to the Dice Roller!\n");
  
  printf("\nInstructions:\n");
  printf("- To roll the dice, press enter.\n");
  printf("- To quit, enter 'q'.\n\n");
  
  do {
    printf("Press enter to roll the dice.");
    getchar();
    
    diceRoll = rand() % 6 + 1;
    
    switch (diceRoll) {
      case 1:
        printf("\n\n*****\n*   *\n* O *\n*   *\n*****\n\n");
        break;
      case 2:
        printf("\n\n*****\n*   *\n*O O*\n*   *\n*****\n\n");
        break;
      case 3:
        printf("\n\n*****\n*O  *\n* O *\n*  O*\n*****\n\n");
        break;
      case 4:
        printf("\n\n*****\n*O O*\n*   *\n*O O*\n*****\n\n");
        break;
      case 5:
        printf("\n\n*****\n*O O*\n* O *\n*O O*\n*****\n\n");
        break;
      case 6:
        printf("\n\n*****\n*O O*\n*O O*\n*O O*\n*****\n\n");
        break;
    }
    
  } while (getchar() != 'q');
  
  printf("\nThank you for using the Dice Roller! Goodbye.\n");
  
  return 0;
}