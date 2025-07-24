//FormAI DATASET v1.0 Category: Random ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Greet the user
  printf("Welcome to my cheerful random number generator!\n");

  // Seed the random number generator with the current time
  srand(time(0));

  // Generate and print a random whole number between 1 and 100
  int num = rand() % 100 + 1;
  printf("Your random number is %d!\n", num);

  // Generate and print a random letter of the alphabet
  char letter = 'A' + rand() % 26;
  printf("Random letter of the alphabet: %c!\n", letter);

  // Generate and print a random color
  char* colors[] = {"red", "orange", "yellow", "green", "blue", "purple"};
  int index = rand() % 6;
  printf("Your random color is %s!\n", colors[index]);

  // Generate and print a random name from a list
  char* names[] = {"Alice", "Bob", "Charlie", "Diana", "Eric", "Fiona"};
  index = rand() % 6;
  printf("Random name: %s!\n", names[index]);

  // Spin a virtual roulette wheel and print the result
  printf("Time to spin the roulette wheel...\n");
  int roulette = rand() % 37;
  if (roulette == 0) {
    printf("Green 0!\n");
  } else if (roulette == 37) {
    printf("00!\n");
  } else if (roulette % 2 == 0) {
    printf("Red %d!\n", roulette);
  } else {
    printf("Black %d!\n", roulette);
  }

  // Sum two random floating point numbers and print the result
  float num1 = (float) rand() / RAND_MAX * 10.0;
  float num2 = (float) rand() / RAND_MAX * 10.0;
  float sum = num1 + num2;
  printf("The sum of %.2f and %.2f is %.2f!\n", num1, num2, sum);

  // Say goodbye to the user
  printf("Thanks for using my cheerful random number generator!\n");

  return 0;
}