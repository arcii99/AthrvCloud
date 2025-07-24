//FormAI DATASET v1.0 Category: Dice Roller ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int x; // Declare variable x
  char decision; // Declare variable decision

  srand(time(NULL)); // Seed the random number generator with current time

  printf("===== C Dice Roller =====\n"); // Welcome message 

  do {
    printf("\nPress enter to roll the dice...");
    getchar(); // Wait for user to press ENTER

    x = rand() % 6 + 1; // Generate a random number between 1 and 6 (inclusive)

    switch (x) {
      case 1:
        printf("\n _______\n|       |\n|   O   |\n|_______|\n"); // Draw dice face
        break;
      case 2:
        printf("\n _______\n|       |\n| O   O |\n|_______|\n"); // Draw dice face
        break;
      case 3:
        printf("\n _______\n| O     |\n|   O   |\n|_____O_|\n"); // Draw dice face
        break;
      case 4:
        printf("\n _______\n| O   O |\n|       |\n|_O___O_|\n"); // Draw dice face
        break;
      case 5:
        printf("\n _______\n| O   O |\n|   O   |\n|_O___O_|\n"); // Draw dice face
        break;
      case 6:
        printf("\n _______\n| O   O |\n| O   O |\n|_O___O_|\n"); // Draw dice face
        break;
      default:
        break;
    }

    printf("\nRoll again? (y/n): ");
    scanf(" %c", &decision); // Read user input
  } while (decision == 'y' || decision == 'Y'); // Continue rolling if user inputs 'y' or 'Y'

  printf("\nThanks for playing! Goodbye.");
  return 0;
}