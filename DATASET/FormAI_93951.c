//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // Generate a random number
  srand(time(NULL));
  int num = rand() % 5;

  // Shape shift the output based on the random number
  switch (num) {
    case 0:
      printf("Your future is bright! You will achieve great success in your career.\n");
      break;
    case 1:
      printf("You will face some challenges in the near future. It is important to stay positive and keep pushing forward.\n");
      break;
    case 2:
      printf("Love is in the air! You will find happiness in a new relationship.\n");
      break;
    case 3:
      printf("Be careful with your finances in the coming weeks. It is important to stick to a budget and avoid unnecessary expenses.\n");
      break;
    case 4:
      printf("Your health will be a top priority in the coming months. Take care of yourself and make sure to get plenty of rest.\n");
      break;
    default:
      printf("I'm sorry, something went wrong with the fortune telling.\n");
      break;
  }
  
  return 0;
}