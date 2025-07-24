//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Romeo and Juliet
#include <stdio.h>

int main() {
  int day = 1;
  int steps = 0;
  int targetSteps = 10000;
  char name[20];
  printf("Enter thy name, fair user: ");
  scanf("%s", name);

  printf("Ah, lovely %s! Welcome to thy fitness tracker!\n", name);

  while (day <= 7) {
    printf("\nDay %d:\n", day);
    printf("How many steps did thou take today? ");
    scanf("%d", &steps);

    if (steps < targetSteps) {
      printf("Alas, thou hast not met thy goal. Thou art a lazy loon!\n");
    } else {
      printf("Huzzah, thou hast met thy goal! Thou art a fit and active %s!\n", name);
    }
    day++;
  }

  printf("\nCongratulations, %s! Thou hast completed the week!\n", name);

  return 0;
}