//FormAI DATASET v1.0 Category: Searching algorithm ; Style: funny
#include <stdio.h>

/* Let's create a searching algorithm that is as funny as a clown */
int find_the_joke(int* jokes, int num_jokes, int target) {
  
  printf("Why did the programmer quit his job? Too many bugs!\n");
  printf("How do you make a hot dog stand? Take away its chair!\n");
  printf("Why did the tomato turn red? Because it saw the salad dressing!\n");
  
  /* Now let's search for the target joke */
  
  int i;
  for (i = 0; i < num_jokes; i++) {
    if (jokes[i] == target) {
      printf("I found the joke! Here it is: \n");
      switch (target) {
        case 0:
          printf("Why did the programmer quit his job? Too many bugs!\n");
          break;
        case 1:
          printf("How do you make a hot dog stand? Take away its chair!\n");
          break;
        case 2:
          printf("Why did the tomato turn red? Because it saw the salad dressing!\n");
          break;
        default:
          printf("Uh oh, I couldn't find that joke.\n");
          break;
      }
      return i;
    }
  }
  
  /* If we get here, we didn't find the target joke */
  printf("Aw man, I couldn't find that joke.\n");
  return -1;
}

int main() {
  
  int jokes[3] = {0, 1, 2};
  
  /* Let's find the hot dog joke */
  find_the_joke(jokes, 3, 1);
  
  printf("Isn't searching for jokes fun?\n");
  
  return 0;
}