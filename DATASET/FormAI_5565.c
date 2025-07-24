//FormAI DATASET v1.0 Category: Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // Prompt the user to choose rock, paper, or scissors
  printf("Choose rock (R), paper (P), or scissors (S): ");
  char choice;
  scanf("%c", &choice);
  getchar();

  // Ensure the user's input is valid
  while (choice != 'R' && choice != 'P' && choice != 'S') {
    printf("Invalid input. Choose rock (R), paper (P), or scissors (S): ");
    scanf("%c", &choice);
    getchar();
  }

  // Generate a random choice for the computer
  srand(time(NULL));
  char computer = rand() % 3;
  switch (computer) {
    case 0:
      computer = 'R';
      break;
    case 1:
      computer = 'P';
      break;
    case 2:
      computer = 'S';
      break;
  }

  // Print the computer's choice
  printf("Computer chooses %c\n", computer);

  // Determine the winner
  if (choice == computer) {
    printf("Tie!\n");
  } else if ((choice == 'R' && computer == 'S') || (choice == 'P' && computer == 'R') || (choice == 'S' && computer == 'P')) {
    printf("You win!\n");
  } else {
    printf("Computer wins!\n");
  }
  
  return 0;
}