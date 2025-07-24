//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  char letters[26] = "abcdefghijklmnopqrstuvwxyz"; // array of lower case letters
  printf("Type these characters as fast as you can:\n");
  for (int i = 0; i < 50; i++) { // prints 50 random letters
    printf("%c ", letters[rand() % 26]);
  }
  printf("\n");

  clock_t start, end; // tracks time it takes to type the letters
  double time_taken;
  char input;
  int correct_count = 0;
  start = clock(); // start the clock
  for (int i = 0; i < 50; i++) {
    scanf(" %c", &input); // reads in user input
    if (input == letters[i]) { // checks if input matches the original letter
      correct_count++;
    }
  }
  end = clock(); // stop the clock
  time_taken = ((double) (end - start)) / CLOCKS_PER_SEC; // calculate duration of test

  printf("\nYou typed %d out of 50 letters correctly.\n", correct_count);
  printf("It took you %.2f seconds to complete the test.\n", time_taken);
  printf("Your typing speed is %.2f characters/second.\n", 50/time_taken);

  return 0;
}