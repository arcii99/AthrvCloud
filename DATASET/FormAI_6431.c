//FormAI DATASET v1.0 Category: Dice Roller ; Style: immersive
#include <stdio.h> // Standard Input-Output Library
#include <stdlib.h> // Standard Library
#include <time.h> // Time Library for RNG

int main() {
  // Declare Variables
  int sides, roll, total = 0;
  char choice;
  
  // Seed RNG with current time
  srand(time(0));
  
  // Welcome Message
  printf("Welcome to the Dice Roller!\n");
  printf("Enter the number of sides for your die: ");
  scanf("%d", &sides);
  
  // Roll the Dice
  do {
    // Generate Random Number between 1 and the number of sides
    roll = rand() % sides + 1;
    total += roll; // Add roll to total sum
    
    // Output Roll Result and Current Total
    printf("\nYou rolled a %d!\n", roll);
    printf("Current Total: %d\n", total);
    
    // Ask to Roll Again
    printf("\nRoll Again? (Y/N): ");
    scanf(" %c", &choice); // Space before %c to consume whitespace
    
  } while (choice == 'Y' || choice == 'y'); // Keep Rolling Until User Says No
  
  // Goodbye Message and Total Score
  printf("\nThanks for Playing!\n");
  printf("Your Total Score: %d\n", total);
  
  return 0; // Exit Program
}