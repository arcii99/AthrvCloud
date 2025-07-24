//FormAI DATASET v1.0 Category: Pattern printing ; Style: funny
#include <stdio.h>

int main() {
  printf("Welcome to the wacky world of C pattern printing!\n");

  int i, j, k, l;

  printf("Here's a pattern that will make your head spin:\n");

  for (i = 1; i <= 5; i++) {
    for (j = 1; j <= i; j++) {
      printf("%d ", j);
    }
    printf("\n");
  }
  
  printf("Did that make your head spin? Well, buckle up for round 2:\n");

  for (i = 5; i >= 1; i--) {
    for (j = 1; j <= i; j++) {
      printf("%d ", j);
    }
    printf("\n");
  }

  printf("Hope you're not dizzy yet! Let's move on to something a little more complex:\n");

  for (i = 1; i <= 5; i++) {
    for (j = i; j < 5; j++) {
      printf(" ");
    }
    for (k = 1; k <= i; k++) {
      printf("%d", k);
    }
    for (l = i - 1; l >= 1; l--) {
      printf("%d", l);
    }
    printf("\n");
  }

  printf("Phew, that was intense. Let's move on to a fun one:\n");

  for (i = 1; i <= 5; i++) {
    for (j = 1; j <= i; j++) {
      printf("%d ", i);
    }
    printf("\n");
  }

  printf("That one was easy, let's kick it up a notch:\n");

  for (i = 1; i <= 5; i++) {
    for (j = 5; j > i; j--) {
      printf(" ");
    }
    for (k = 1; k <= i; k++) {
      printf("%d ", i);
    }
    printf("\n");
  }

  printf("Now that's what I call a pattern! Hope you had fun! :)\n");

  return 0;
}