//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num;
  
  srand(time(NULL));
  
  printf("Welcome to the Automated Fortune Teller! Choose a number between 1 and 10\n");
  scanf("%d", &num);
  
  switch(num) {
    case 1:
      printf("You will soon encounter a talking dog wearing a bow tie. Don't be afraid, he's friendly.\n");
      break;
    case 2:
      printf("Your future will be filled with many bizarre and peculiar events. Embrace them.\n");
      break;
    case 3:
      printf("Beware of the black cat you will cross paths with tonight. He's a trickster.\n");
      break;
    case 4:
      printf("Your destiny lies on a distant planet in outer space. Start packing your bags.\n");
      break;
    case 5:
      printf("Your love life is about to get messy. Prepare for some dramatic twists and turns.\n");
      break;
    case 6:
      printf("You will encounter a time traveler from the past. Help them find their way back home.\n");
      break;
    case 7:
      printf("You will stumble upon a magical land hidden deep in the woods. Don't resist its call.\n");
      break;
    case 8:
      printf("The future looks bright for you. Expect great success in all your endeavors.\n");
      break;
    case 9:
      printf("You will soon have a brush with death, but don't worry, you will survive.\n");
      break;
    case 10:
      printf("Your greatest fear will accompany you wherever you go, but don't let it control you.\n");
      break;
    default:
      printf("I'm sorry, I didn't understand that. Please enter a number between 1 and 10.\n");
  }
  
  return 0;
}