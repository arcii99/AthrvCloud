//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  char *sentence = "The quick brown fox jumps over the lazy dog";
  int len = strlen(sentence), pos = 0, mistakes = 0, streak = 0;
  clock_t start_time, end_time;
  double time_taken, chars_per_sec, wpm;
  srand(time(NULL));
  
  printf("Welcome to the Typing Speed Test!\n\n");
  printf("Type the following sentence as fast and accurately as possible:\n\n");
  printf("%s\n\n", sentence);
  
  start_time = clock();
  
  while (pos < len) {
    char c = getchar();
    if (c == sentence[pos]) {
      printf("%c", c);
      pos++;
      streak++;
    } else if (c == 8 && pos > 0) {
      printf("\b \b");
      pos--;
      mistakes--;
      if (streak > 0) streak--;
    } else if (c == 27) {
      printf("\n\nExiting program...\n");
      return 0;
    } else {
      printf("%c", 7); // beep sound for incorrect input
      mistakes++;
      streak = 0;
    }
  }
  
  end_time = clock();
  
  time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  chars_per_sec = (double)len / time_taken;
  wpm = chars_per_sec * 60 / 5;
  
  printf("\n\nYou finished the sentence in %.2f seconds!\n", time_taken);
  printf("You made %d mistake(s).\n", mistakes);
  printf("Your Typing Speed: %.2f characters per second.\n", chars_per_sec);
  printf("Your Typing Speed: %.2f words per minute.\n", wpm);
  
  printf("\nWant to try again? Press enter to continue or esc to exit...\n");
  
  while (1) {
    char c = getchar();
    if (c == 10) { // enter key
      system("clear"); // for Linux/Mac
      main();
    } else if (c == 27) {
      printf("\n\nExiting program...\n");
      break;
    }
  }
  
  return 0;
}