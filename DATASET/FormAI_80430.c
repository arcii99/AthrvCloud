//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  char name[20];
  time_t t;
  srand((unsigned) time(&t));

  printf("Welcome to the Automated Fortune Teller!\n");
  printf("Enter your name: ");
  scanf("%s", name);

  printf("\nHello %s, I will now predict your future...\n", name);

  int fortune_num = rand() % 6;

  switch(fortune_num) {
    case 0:
      printf("\nYou will find great success in all your endeavors!\n");
      break;
    case 1:
      printf("\nYour luck is about to change for the better!\n");
      break;
    case 2:
      printf("\nYou will meet someone special in the near future!\n");
      break;
    case 3:
      printf("\nA great opportunity is on its way to you!\n");
      break;
    case 4:
      printf("\nYou will face some challenges, but you will overcome them!\n");
      break;
    default:
      printf("\nYou will have a day filled with both good and bad moments!\n");
      break;
  }

  return 0;
}