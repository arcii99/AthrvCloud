//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  // Greeting message
  printf("Welcome to the Automated Fortune Teller!\n");

  // Ask for user's name
  char name[50];
  printf("What's your name?\n");
  scanf("%s", name);

  // Generate random number between 0 and 4
  int rand_num = rand() % 5;

  // Use the random number to predict the future
  switch (rand_num) {
    case 0:
      printf("Sorry, %s. I am not able to tell you your fortune right now.\n", name);
      break;
    case 1:
      printf("Good news, %s. You will receive unexpected money in the near future!\n", name);
      break;
    case 2:
      printf("Beware, %s. You will encounter a great challenge soon.\n", name);
      break;
    case 3:
      printf("Great things are coming your way, %s. Stay optimistic and keep pushing forward!\n", name);
      break;
    case 4:
      printf("Love is in the air, %s! You will meet someone special very soon.\n", name);
      break;
  }

  // Thank the user for using the program
  printf("Thank you for using the Automated Fortune Teller! Come back soon!\n");

  return 0;
}