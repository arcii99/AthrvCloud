//FormAI DATASET v1.0 Category: Pattern printing ; Style: excited
#include <stdio.h>

int main() {
  // Welcome message
  printf("Hey there, let's create a unique C pattern!\n\n");

  // Let's declare some variables
  int n = 6;
  int i, j, k;

  // Outputting the pattern
  for (i = 0; i < n; i++) {
    for (j = n; j > i; j--) {
      printf(" ");
    }
    for (k = 0; k <= i; k++) {
      printf("* ");
    }
    printf("\n");
  }

  // Wait, that's not all, let's make it more exciting!
  printf("\n\nWOW, wasn't that amazing? Let's go further!\n\n");

  // Redefining variables to make the pattern bigger
  n = 10;

  // Outputting the bigger pattern
  for (i = 0; i < n; i++) {
    for (j = n; j > i; j--) {
      printf(" ");
    }
    for (k = 0; k <= i; k++) {
      if(k % 2 == 0) {
        printf("* ");
      } else {
        printf("! ");
      }
    }
    printf("\n");
  }

  // That's not enough, let's make it even more exciting!
  printf("\n\nIncredible right? But we're not done yet!\n\n");

  // Redefining variables to make the pattern even bigger
  n = 16;

  // Outputting the even bigger pattern
  for (i = 0; i < n; i++) {
    for (j = n; j > i; j--) {
      printf(" ");
    }
    for (k = 0; k <= i; k++) {
      if(k % 3 == 0) {
        printf("* ");
      } else if(k % 3 == 1) {
        printf("! ");
      } else {
        printf("# ");
      }
    }
    printf("\n");
  }

  // Last but not least, a message of completion!
  printf("\n\nWOW, we did it! That was a unique and exciting C pattern! :D");

  return 0;
}