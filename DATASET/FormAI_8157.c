//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num, reply;

  /* Set up the random number generator */
  srand(time(NULL));

  printf("Welcome to the Automated Fortune Teller!\n");
  printf("Please think of a number between 1 and 10\n");
  printf("When you are ready, enter any number to continue: ");
  scanf("%d", &num);

  /* Generate a random prediction */
  reply = rand() % 6;

  /* Assign a fortune based on the random number */
  switch(reply) {
    case 0:
      printf("I predict that good fortune will smile upon you today.\n");
      break;
    case 1:
      printf("Be cautious in your dealings with others, for someone you trust may betray you.\n");
      break;
    case 2:
      printf("You will soon receive an unexpected windfall of money.\n");
      break;
    case 3:
      printf("Your romantic life will take a turn for the better in the near future.\n");
      break;
    case 4:
      printf("Your hard work will pay off soon, but be patient.\n");
      break;
    case 5:
      printf("You will encounter a great challenge soon, but with perseverance you will overcome it.\n");
      break;
    default:
      printf("Sorry, I did not understand your request. Please try again.\n");
      return 1;
  }

  printf("Thank you for using the Automated Fortune Teller!\n");
  return 0;
}