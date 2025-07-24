//FormAI DATASET v1.0 Category: Error handling ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  int r = rand() % 10;

  switch (r) {
    case 0:
      printf("Congratulations! You've won a 3-armed octopus!\n");
      break;
    case 1:
      printf("Well, this is awkward. The program is unable to run.\n");
      exit(1);
    case 2:
      printf("A fire-breathing dragon broke into your computer. Please evacuate immediately.\n");
      break;
    case 3:
      printf("Oh no, an army of rogue robots invaded your program. Run for your life!\n");
      exit(1);
    case 4:
      printf("Sorry, your program crashed and burned. But don't worry, there's always tomorrow.\n");
      exit(1);
    case 5:
      printf("You've crossed into the Twilight Zone. Your program has disappeared into another dimension.\n");
      break;
    case 6:
      printf("This is not a drill. The aliens have taken over your program. We repeat, this is not a drill. \n");
      exit(1);
    case 7:
      printf("Unexpected error! The code may or may not explode. Proceed with caution.\n");
      break;
    case 8:
      printf("Your program has been possessed by a malicious spirit. Time for an exorcism.\n");
      exit(1);
    default:
      printf("Your program is running perfectly fine. Don't worry, be happy!\n");
      break;
  }

  return 0;
}