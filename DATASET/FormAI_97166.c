//FormAI DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to the lazy system administrator!\n");

  int num_updates = 0;

  while (1) {
    printf("Have you updated your system yet? 1 = yes, 0 = no: ");
    int updated;
    scanf("%d", &updated);

    if (updated) {
      printf("Awesome, keep it up!\n");
    } else {
      printf("What are you waiting for? Updates don't install themselves!\n");
      printf("Let me guess, you're busy playing video games or something...\n");
      num_updates++;

      if (num_updates >= 3) {
        printf("You know what, I'm just going to update your system for you. You clearly can't be trusted.\n");
        printf("Done! Your system is updated. You're welcome.\n");
        break;
      }
    }
  }

  return 0;
}