//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main() {
  char words[10][20] = { // list of 10 random words
    "fantastic",
    "harmony",
    "paradise",
    "celebrity",
    "integrity",
    "renaissance",
    "magnificent",
    "graceful",
    "enchanted",
    "victorious"
  };
  char input[20]; // user input
  int num_words = sizeof(words) / sizeof(words[0]); // length of the words array
  srand(time(NULL)); // set random seed based on current time
  int correct_count = 0; // keep count of correct words
  clock_t start = clock(); // start timer

  printf("Welcome to the Typing Speed Test!\n");
  printf("Type the words as fast and accurately as you can:\n");

  for (int i = 0; i < num_words; i++) {
    printf("%s ", words[i]); // print current word
    fgets(input, 20, stdin); // get user input
    input[strcspn(input, "\n")] = 0; // remove trailing newline character
    
    if (strcmp(input, words[i]) == 0) { // if input matches current word
      printf("Correct!\n");
      correct_count++;
    } else {
      printf("Incorrect. The correct word is '%s'\n", words[i]);
    }
  }

  clock_t end = clock(); // end timer
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

  printf("\n\nResults:\n");
  printf("Number of correct words: %d\n", correct_count);
  printf("Typing speed: %.2f words per minute\n", num_words / (time_taken / 60));
  
  return 0;
}