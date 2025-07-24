//FormAI DATASET v1.0 Category: Random ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This is a C program that generates a random number and prints it out
// The program is dedicated to all the programmers who love playing with random numbers!
int main() {
  srand(time(NULL));
  // initialize the random number generator with the current time (in seconds) as the seed

  int num = rand() % 100 + 1; 
  // generate a random number between 1 and 100 (inclusive)

  printf("Welcome to the world of randomness!\n");
  printf("I have generated a number between 1 and 100, can you guess what it is?\n");

  int guess, count = 0;
  do {
    printf("Enter your guess (between 1 and 100): ");
    scanf("%d", &guess);
    count++;

    if (guess > num) {
      printf("Too high!\n");
    } else if (guess < num) {
      printf("Too low!\n");
    } 
  } while (guess != num);

  printf("Congratulations! You guessed the number %d in %d attempts.\n", num, count);

  return 0;
}