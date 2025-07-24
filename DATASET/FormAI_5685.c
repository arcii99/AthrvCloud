//FormAI DATASET v1.0 Category: Math exercise ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));

  int num1 = rand() % 100;
  int num2 = rand() % 50;
  int num3 = rand() % 25;
  
  printf("Your three random numbers are: %d, %d, and %d\n", num1, num2, num3);

  int sum = num1 + num2 + num3;
  float average = (float)sum / 3;

  printf("Do you hear that? That's the sound of math happening. Let's proceed:\n");

  printf("%d + %d + %d = %d\n", num1, num2, num3, sum);
  printf("%d divided by %d is %f\n", sum, 3, average);

  int difference = num1 - num2 - num3;

  printf("Woah, hold on to your hats, folks. Things just got complicated:\n");

  printf("%d minus %d minus %d equals %d\n", num1, num2, num3, difference);
  printf("%d times %d is %d\n", difference, num3, difference * num3);

  printf("Mind. Blown. I hope you enjoyed this math exercise!\n");

  return 0;
}