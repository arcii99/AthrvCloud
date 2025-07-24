//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int fortune_number = 0;
  char name[50];

  printf("Welcome to the Automated Fortune Teller Program. \n");
  
  printf("Please enter your name: ");
  scanf("%s", name);
  
  printf("Hello %s! Before we begin, please think of a question that you want to ask the fortune teller. \n\n", name);
  
  printf("Now, choose a number from 1 to 5: ");
  
  scanf("%d", &fortune_number);
  
  srand(time(NULL));

  switch (fortune_number) {
    case 1:
      printf("\nYour fortune is positive. You will soon receive good news that will make you very happy!\n");
      break;
    case 2:
      printf("\nYour fortune is neutral. You will experience steady progress towards your goals, but you will need to stay focused and work hard.\n");
      break;
    case 3:
      printf("\nYour fortune is negative. You will face some challenges in the near future, but don't worry - you are strong enough to overcome them.\n");
      break;
    case 4:
      printf("\nYour fortune is mysterious. You may find that some things in your life remain unclear, but trust that everything will become clear in due time.\n");
      break;
    case 5:
      printf("\nYour fortune is powerful. You will soon receive a sign that will lead you towards greatness and success. Trust your intuition!\n");
      break;
    default: 
      printf("\nOops, it seems that you didn't choose a number between 1 and 5. Please try again.\n");
      break;
  }
  
  printf("\nThank you for participating in the Automated Fortune Teller Program, %s. We hope you found your fortune to be insightful.\n", name);

  return 0;
}