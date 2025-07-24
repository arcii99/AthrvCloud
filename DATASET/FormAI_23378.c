//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  time_t start, end;
  double time_taken;
  char typed_text[100], target_text[] = "The quick brown fox jumps over the lazy dog.";
  int i, correct_chars = 0;
  printf("Type the following text:\n%s\n", target_text);
  
  time(&start); // Start timing the user's typing speed
  fgets(typed_text, 100, stdin);
  time(&end); // Stop timing the user's typing speed
  
  // Compare the typed text with the target text
  for (i = 0; i < sizeof(target_text)-1 && typed_text[i] != '\n'; i++) {
    if (typed_text[i] == target_text[i]) {
      correct_chars++;
    }
  }
  
  time_taken = difftime(end, start); // Calculate the time taken to type the text in seconds
  printf("You typed %d correct characters in %.2f seconds.\n", correct_chars, time_taken);
  printf("Your typing speed is %.2f characters per second.\n", (double)correct_chars/time_taken);
  
  return 0;
}