//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed the random number generator with the current time
  int fortune_num = rand() % 20; // generate a random number between 0 and 19
  
  printf("Welcome to the Automated Fortune Teller!\n");

  switch(fortune_num) {
    case 0:
      printf("Your future looks bright!\n");
      break;
    case 1:
      printf("Beware of making hasty decisions.\n");
      break;
    case 2:
      printf("Good news is on the way!\n");
      break;
    case 3:
      printf("Your hard work will pay off.\n");
      break;
    case 4:
      printf("Be kind to yourself and others.\n");
      break;
    case 5:
      printf("You will face a challenge soon, but you can overcome it.\n");
      break;
    case 6:
      printf("Your creativity will lead you to success.\n");
      break;
    case 7:
      printf("Don't be afraid to take a risk.\n");
      break;
    case 8:
      printf("Your financial situation will improve.\n");
      break;
    case 9:
      printf("Take a break and focus on self-care.\n");
      break;
    case 10:
      printf("Your love life will flourish.\n");
      break;
    case 11:
      printf("Be wary of those who try to bring you down.\n");
      break;
    case 12:
      printf("Your dreams will come true if you work hard enough.\n");
      break;
    case 13:
      printf("You will make a new friend soon.\n");
      break;
    case 14:
      printf("Everything happens for a reason.\n");
      break;
    case 15:
      printf("You will receive a gift or bonus soon.\n");
      break;
    case 16:
      printf("Learn from your mistakes and move forward.\n");
      break;
    case 17:
      printf("Believe in yourself and your abilities.\n");
      break;
    case 18:
      printf("You will have a chance to travel soon.\n");
      break;
    case 19:
      printf("Make sure to take care of your health.\n");
      break;
    default:
      printf("Oops, something went wrong! Please try again later.\n");
      break;
  }

  return 0;
}