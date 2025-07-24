//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int wordCount = 0, correctCount = 0, errorCount = 0;
  double timeTaken = 0, typingSpeed = 0;
  char sentence[1000];
  time_t startTime, endTime;

  printf("Welcome to the Typing Speed Test!\n");
  printf("Type the sentence below as fast as you can and press enter:\n");

  strcpy(sentence, "The quick brown fox jumps over the lazy dog.");

  printf("%s\n", sentence);

  time(&startTime); // Start timer

  while (sentence[wordCount] != '\0') {
    char input;
    scanf("%c", &input);
    if (input == sentence[wordCount]) {
      correctCount++;
    } else {
      errorCount++;
    }
    wordCount++;
  }

  time(&endTime); // End timer

  timeTaken = difftime(endTime, startTime);
  typingSpeed = (double)correctCount / timeTaken * 60;

  printf("\n\nResults:\n");
  printf("Correct Words Typed: %d\n", correctCount);
  printf("Total Errors: %d\n", errorCount);
  printf("Time Taken: %.2lf seconds\n", timeTaken);
  printf("Typing Speed: %.2lf words per minute\n", typingSpeed);

  return 0;
}