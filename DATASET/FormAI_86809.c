//FormAI DATASET v1.0 Category: Recursive ; Style: happy
#include <stdio.h>

void happyRecursion(int num) {
  if (num < 1) {                                             // Base case
    printf("Happiness overload!\n");
  } else {
    printf("I am feeling happy!\n");                         // Feeling happy!
    happyRecursion(num - 1);                                 // Call happyRecursion with num - 1
  }
}

int main() {
  printf("Let's spread some happiness!\n");
  printf("How happy are you feeling? (Please enter a number): ");
  int num;
  scanf("%d", &num);
  printf("\n");

  happyRecursion(num);                                       // Call happyRecursion

  printf("Happiness is contagious! Let's make others happy too!\n");
  return 0;
}