//FormAI DATASET v1.0 Category: Educational ; Style: energetic
#include <stdio.h>

int main() {
  printf("Let's play a game!\n");
  
  int answer = 5;
  int guess = 0;
  int attempts = 0;
  
  while (guess != answer) {
    printf("Enter your guess:\n");
    scanf("%d", &guess);
    
    if (guess < answer) {
      printf("Too low!\n");
      attempts++;
    }
    else if (guess > answer) {
      printf("Too high!\n");
      attempts++;
    }
    else {
      printf("You got it! The answer was %d.\n", answer);
      attempts++;
    }
  }
  
  printf("You win! It took you %d attempts.\n", attempts);
  
  return 0;
}