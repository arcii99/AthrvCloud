//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));

  printf("Welcome to the Surrealist Fortune Teller!\n");
  printf("-----------------------------------------\n");
  printf("\n");

  printf("Think of a question you want answered: ");
  char question[100];
  fgets(question, sizeof(question), stdin);
  printf("\n\n");

  int fortune = rand() % 7;

  switch(fortune) {
    case 0:
      printf("The clouds will rain tears of joy upon your soul.\n");
      break;
    case 1:
      printf("Your aura has a faint yet powerful glow. Beware of those who seek to dim it.\n");
      break;
    case 2:
      printf("The stars are aligning in your favor, but don't forget to chart your own course.\n");
      break;
    case 3:
      printf("You will stumble upon a lost treasure in the midst of chaos and confusion.\n");
      break;
    case 4:
      printf("Your heart will be torn in two, but each piece will grow into something beautiful.\n");
      break;
    case 5:
      printf("The universe is conspiring in your favor, but don't forget to take action.\n");
      break;
    case 6:
      printf("Embrace the unknown, for it holds the key to unlocking your deepest desires.\n");
      break;
  }

  return 0;
}