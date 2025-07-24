//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i, correct = 0, incorrect = 0;
  char ch; // for input character
  clock_t start, end;
  double time_spent;
  srand(time(0));

  // sample text to be typed
  char text[] = "The quick brown fox jumps over the lazy dog.";
  printf("Type the following text as quickly and accurately as possible:\n\n%s\n\n", text);

  // delay of 3 seconds to prepare user
  printf("The test will begin in 3 seconds...\n");
  sleep(3);

  start = clock(); // start time
  for (i = 0; text[i] != '\0'; i++) {
    printf("%c", text[i]);
    ch = getchar(); // take input from user
    if (ch == text[i])
      correct++;
    else
      incorrect++;
  }
  end = clock(); // end time

  // calculate time taken to complete the test and typing speed
  time_spent = (double)(end - start) / CLOCKS_PER_SEC;
  double speed = (double)correct / time_spent * 60;

  // print results
  printf("\n\nTest complete!\n");
  printf("Total time taken: %.2f seconds\n", time_spent);
  printf("Total correct characters: %d\n", correct);
  printf("Total incorrect characters: %d\n", incorrect);
  printf("Typing speed: %.2f characters per minute\n", speed);

  return 0;
}