//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
  
  char prompt[] = "The quick brown fox jumps over the lazy dog.";
  char input[100];
  
  int i, j, accuracy, num_chars = 44;
  float typing_speed;
  
  time_t start, end;
  
  printf("Welcome to the Typing Speed Test.\n\nYour prompt is:\n\n%s\n\nType the above prompt as quickly and accurately as possible.\nPress enter when you are ready to start.", prompt);
  
  getchar(); // wait for user to press enter
  
  time(&start); // mark the start time
  
  fgets(input, 100, stdin); // take user input
  
  time(&end); // mark the end time
  
  for(i = 0, j = 0; i < num_chars; i++, j++) {
    if(prompt[i] != input[j]) {
      accuracy++; // calculate number of inaccuracies
    }
  }
  
  typing_speed = (float)num_chars / difftime(end, start) * 60; // calculate typing speed
  
  printf("The length of the prompt was %d characters.\n", num_chars);
  printf("You made %d mistake(s).\n", accuracy);
  printf("Your typing speed was %.2f WPM.\n", typing_speed);
  
  return 0;
}