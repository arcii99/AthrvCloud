//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Set seed for random number generator
  srand(time(NULL));

  printf("Welcome to the Automated Fortune Teller!\n\n");

  // Get user's name
  printf("Please enter your name: ");
  char name[50];
  scanf("%s", name);
  printf("\n");

  // Display greeting
  printf("Welcome, %s! I will now tell you your fortune.\n\n", name);

  // Generate random number between 1 and 5
  int fortune = rand() % 5 + 1;

  // Display fortune based on random number
  switch (fortune) {
    case 1:
      printf("Your future is looking bright!\n");
      break;
    case 2:
      printf("Be cautious in your financial decisions.\n");
      break;
    case 3:
      printf("Love is in your future.\n");
      break;
    case 4:
      printf("A life-changing opportunity is coming your way.\n");
      break;
    case 5:
      printf("You will face a difficult decision in the near future.\n");
      break;
  }

  printf("\nThank you for using the Automated Fortune Teller!");

  // Pause program before exiting
  getchar();

  return 0;
}