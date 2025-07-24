//FormAI DATASET v1.0 Category: Arithmetic ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
  int a, b, c, d, e, f;
  
  printf("Enter six numbers:\n");
  scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

  printf("Wow, you chose some really curious numbers.\n");

  int result = (((a + b * c) / d) % e) - f;

  printf("The result of your curious computation is: %d\n", result);

  printf("Did you know that if you add up all your numbers and divide by 6,\n"); 
  printf("you get the average of your numbers? Let's do that now!\n");

  float average = (float) (a + b + c + d + e + f) / 6;

  printf("The average of your numbers is: %f\n", average);

  printf("And here's something really curious. Let's see if the\n");
  printf("result we got is larger than the average of the numbers.\n");

  if (result > average) {
    printf("Wow! The result is larger than the average! How curious!\n");
  } else {
    printf("Hmmm, the result is not larger than the average.\n");
    printf("I guess the numbers you chose weren't curious enough.\n");
  }

  printf("Thanks for playing with me!\n");

  return 0;
}