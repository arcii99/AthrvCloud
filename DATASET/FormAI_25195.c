//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int num_correct = 0;
  int num_incorrect = 0;
  char text[1000] = "The quick brown fox jumps over the lazy dog.";
  srand(time(NULL));

  printf("Welcome to the Typing Speed Test!\n\n");
  printf("You will be given a random sentence to type. Try to type it as quickly and accurately as possible.\n\n");
  printf("Press enter when you're ready to begin.\n");
  getchar();

  for (int i = 0; i < 5; i++) {
    system("clear"); // Clears the screen
    printf("Type the following sentence as quickly and accurately as possible:\n\n");
    printf("%s\n", text);

    time_t start_time = time(NULL); // Starting time
    char user_input[1000];
    fgets(user_input, 1000, stdin); // User input

    time_t end_time = time(NULL);  // Ending time
    double elapsed_time = difftime(end_time, start_time); // Calculates elapsed time

    // Compares user input with the original sentence
    if (strcmp(user_input, text) == 0) {
      printf("\nCongratulations! You typed the sentence correctly!\n");
      printf("Time elapsed: %.2lf seconds\n\n", elapsed_time);
      num_correct++;
    } else {
      printf("\nSorry, you typed the sentence incorrectly.\n");
      printf("Time elapsed: %.2lf seconds\n\n", elapsed_time);
      num_incorrect++;
    }

    printf("Press enter to continue.");
    getchar();
  }

  printf("You completed the Typing Speed Test!\n");
  printf("Number of correct sentences: %d\n", num_correct);
  printf("Number of incorrect sentences: %d\n", num_incorrect);

  if (num_correct == 5) {
    printf("Wow, you typed all the sentences correctly! Great job!\n");
  } else {
    printf("Keep practicing and you'll improve your typing speed!\n");
  }

  return 0;
}