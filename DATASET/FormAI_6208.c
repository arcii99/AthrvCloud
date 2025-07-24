//FormAI DATASET v1.0 Category: Random ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0)); // seeding the random number generator with time value
  
  printf("Let's play a game!\nI will generate a random number between 1 and 50.\nYou have to guess what it is.\n");
  
  int random_num = (rand() % 50) + 1; // generating a random number between 1 and 50
  
  int guess_count = 0;
  int guess;
  
  while (guess != random_num) {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    
    if (guess < random_num) {
      printf("Too low!\n");
      guess_count++;
    } else if (guess > random_num) {
      printf("Too high!\n");
      guess_count++;
    } else {
      printf("Congratulations! You guessed the number in %d tries!\n", guess_count);
    }
  }
  
  return 0;
}