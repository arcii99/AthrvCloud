//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include <stdio.h>
#include <time.h>

int main() {

  printf("Welcome to the Donald Knuth Typing Speed Test!");
  printf("\n");

  printf("Type the following sentence as fast as you can:");
  printf("\n");

  const char sentence[] = "The quick brown fox jumps over the lazy dog.";
  printf("%s\n", sentence);

  char user_input[50]; // assuming maximum sentence length of 50
  clock_t start, end;
  double elapsed_time;

  start = clock();

  fgets(user_input, 50, stdin);

  end = clock();
  elapsed_time = ((double) (end - start)) / CLOCKS_PER_SEC;

  printf("Your time is: %f seconds.\n", elapsed_time);
  
  int i = 0;
  int errors = 0;
  while (sentence[i] != '\0' && user_input[i] != '\0') {
    if (sentence[i] != user_input[i]) {
      errors++;
    }
    i++;
  }

  printf("You made %d errors.\n", errors);

  return 0;
}