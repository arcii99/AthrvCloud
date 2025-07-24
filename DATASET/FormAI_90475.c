//FormAI DATASET v1.0 Category: Random ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // Seed the random number generator

  printf("Let's generate some random numbers!\n");

  int num1 = rand() % 10 + 1; // Generate a random number between 1 and 10
  printf("First number: %d\n", num1);

  int num2 = rand() % 10 + 1; // Generate another random number between 1 and 10
  printf("Second number: %d\n", num2);

  if(num1 > num2) {
    printf("The first number is greater than the second!\n");
  } else if(num1 < num2) {
    printf("The second number is greater than the first!\n");
  } else {
    printf("The two numbers are equal!\n");
  }

  printf("Now let's generate a random letter:\n");

  char letter = 'A' + rand() % 26; // Generate a random uppercase letter
  printf("The letter is: %c\n", letter);

  printf("Finally, let's generate a random color:\n");

  char* colors[] = {"red", "green", "blue", "yellow", "orange", "purple"}; // Array of possible colors

  int index = rand() % 6; // Generate a random index between 0 and 5

  printf("The color is: %s\n", colors[index]);

  printf("Thanks for playing!\n");

  return 0;
}