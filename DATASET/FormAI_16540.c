//FormAI DATASET v1.0 Category: Arithmetic ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  int a = rand() % 1000;
  int b = rand() % 1000;
  int c = rand() % 1000;
  if (a == b && b == c && c == a) {
    printf("The probability of this happening is almost zero!\n");
    return 1;
  }
  printf("Let's do some surrealist arithmetic!\n");
  printf("We will take the sum of three random numbers and multiply it with the fourth number.\n");
  printf("The sum of our numbers is %d.\n", a + b + c);
  printf("Choose a fourth number: ");
  int d;
  scanf("%d", &d);
  printf("Now multiplying the sum by your number... ");
  int result = (a + b + c) * d;
  printf("The result is %d.\n", result);
  printf("\nBut wait, there's more!\n");
  printf("We are going to subtract the sum of the first two numbers from the product.\n");
  printf("(a + b) is %d.\n", a + b);
  result -= a + b;
  printf("The new result is %d!\n", result);
  printf("\nThe surrealist arithmetic is not done yet.\n");
  printf("Now we will multiply the new result by a random number between 1 and 10.\n");
  int e = rand() % 10 + 1;
  printf("The random number is %d.\n", e);
  result *= e;
  printf("The final result is %d.\n", result);
  printf("\nCongratulations! You have just performed some truly surreal arithmetic.\n");
  return 0;
}