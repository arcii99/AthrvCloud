//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  int seconds = 30; // Timer duration
  int i, c, score = 0;
  time_t start, end;
  char rand_text[] = "The quick brown fox jumps over the lazy dog";
  
  printf("You have %d seconds to type the following text:\n%s\n\n", seconds, rand_text);
  
  time(&start); // Start timer
  
  for (i = 0; rand_text[i] != '\0'; i++) {
    c = getchar(); // Get user input character by character
    
    if (c == rand_text[i]) {
      score++; // If the typed character is correct, increase score by 1
    }
    
    if (score == i && c != '\n') {
      printf("\r"); // Move cursor back to the beginning of the line
    } else {
      printf("\r%s", rand_text); // Print the random text again
      for (int j = 0; j < i; j++) printf("\033[32m%c\033[0m", rand_text[j]); // Print correct characters in green
      if (c != '\n') printf("\033[31m%c\033[0m", c); // Print incorrect character in red
    }
  }
  
  time(&end); // End timer
  
  double elapsed_time = difftime(end, start); // Calculate elapsed time
  
  printf("\n\nTyped in %.2fs\n", elapsed_time);
  
  int typing_speed = (int) (score / (elapsed_time / 60)); // Calculate typing speed in words per minute
  
  printf("Your typing speed is %d WPM\n", typing_speed);
  
  return 0;
}