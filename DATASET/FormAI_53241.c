//FormAI DATASET v1.0 Category: Searching algorithm ; Style: enthusiastic
#include <stdio.h>

// Enthusiastic C Searching Algorithm Example Program!

int main() {
  int array[] = {2, 5, 7, 8, 10, 21, 23, 27, 31, 45, 50, 56, 63, 70, 87};
  int target = 27;
  int index = -1;

  printf("Let's do some searching!\n");

  for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
    if (target == array[i]) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("Sorry, %d is not in the array.\n", target);
  } else {
    printf("Wow, we found %d at index %d!\n", target, index);
  }

  return 0;
}