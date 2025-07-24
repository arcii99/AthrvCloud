//FormAI DATASET v1.0 Category: Memory Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  printf("Welcome to the Memory Game!!!\n");
  printf("Are you ready to test your memory skills? Let's get started!\n");

  srand(time(0)); // setting seed for random number generator
  int arr[10]; // array to store random numbers
  for(int i=0; i<10; i++) {
    arr[i] = rand() % 100; // generating random numbers between 0 and 99
  }

  // displaying random numbers to the user for 5 seconds
  printf("\nMemorize these numbers:\n");
  for(int i=0; i<10; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  for(double i=0; i<5000000000; i++); // wait for 5 seconds

  // clearing the screen
  system("clear");

  // asking user to input the remembered numbers
  int guess[10];
  printf("\nEnter the 10 remembered numbers:\n");
  for(int i=0; i<10; i++) {
    printf("%d: ", i+1);
    scanf("%d", &guess[i]);
  }

  // comparing the guessed numbers with original numbers and displaying the score
  int score = 0;
  printf("\nResults:\n");
  for(int i=0; i<10; i++) {
    if(guess[i] == arr[i]) {
      printf("%d. Correct!\n", i+1);
      score++;
    }
    else {
      printf("%d. Incorrect! The correct number was %d\n", i+1, arr[i]);
    }
  }
  printf("\nFinal Score: %d out of 10", score);

  return 0; // program executed successfully
}