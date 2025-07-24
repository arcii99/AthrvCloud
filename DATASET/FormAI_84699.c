//FormAI DATASET v1.0 Category: Table Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int guess, score = 0, round = 1, num_rounds = 5;
  srand(time(NULL));
  
  printf("Welcome to the Guessing Game! You have %d rounds to score as many points as possible.\n", num_rounds);
  
  while (round <= num_rounds) {
    int rand_num = (rand() % 10) + 1;
    printf("\nROUND %d\n", round);
    printf("Guess a number between 1 and 10: ");
    scanf("%d", &guess);
    
    if (guess < 1 || guess > 10) {
      printf("Invalid input. Please enter a number between 1 and 10.\n");
      continue;
    }
    
    if (guess == rand_num) {
      printf("Congratulations! You guessed the right number! You gain 10 points!\n");
      score += 10;
    } else {
      printf("Sorry, the right number is %d. You lose 5 points.\n", rand_num);
      score -= 5;
    }
    
    printf("Your current score is %d.\n", score);
    round++;
  }
  
  printf("\nGAME OVER. Your final score is %d.\n", score);
  return 0;
}