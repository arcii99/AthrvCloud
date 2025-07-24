//FormAI DATASET v1.0 Category: Funny ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Thank you for running this program! It's a pleasure to meet you.\n");
  printf("As a token of my gratitude, I have created a program that will show you how to convert");
  printf("celsius to fahrenheit using a while loop.\n");

  float celsius, fahrenheit;
  int lower = 0, upper = 100, step = 10;

  celsius = lower;

  while (celsius <= upper) {
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("%3.0f\t%6.1f\n", celsius, fahrenheit);
    celsius = celsius + step;
  }

  printf("\n\n");
  printf("I hope you found this program useful! Thank you for using it and have a wonderful day!\n");

  return 0;
}