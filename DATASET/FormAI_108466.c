//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: lively
#include <stdio.h>
#include <time.h>

int main() {
  printf("Welcome to the Lively Typing Speed Test\n");
  printf("Type the following text as fast as you can:\n\n");
  
  char text[] = "The quick brown fox jumps over the lazy dog";
  printf("%s\n", text);
  
  char input[100];
  int score = 0;
  
  clock_t startTime, endTime;
  startTime = clock();
  
  fgets(input, 100, stdin);
  
  endTime = clock();
  double timeTaken = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;
  
  for (int i = 0; i < strlen(input); i++) {
    if (input[i] == text[i]) {
      score++;
    }
  }
  
  int accuracy = ((double)score / strlen(text)) * 100;
  double speed = ((double)strlen(text) / timeTaken) * 60;
  
  printf("\nYour typing accuracy is: %d%%\n", accuracy);
  printf("Your typing speed is: %.2f WPM\n", speed);
  
  return 0;
}