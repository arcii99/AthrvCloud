//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate random integers between 1 to 75 */
int generateRandomNumber(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

/* Function to check if a number already exists in the array */
int existsInArray(int num, int arr[], int size) {
  for(int i = 0; i < size; i++) {
    if(arr[i] == num) {
      return 1; // number exists in the array
    }
  }
  return 0; // number does not exist in the array
}

/* Recursive function to generate randomly unique numbers for each player */
void generatePlayerNumbers(int playerNums[], int size, int min, int max) {
  if(size < 1) {
    return;
  }
  int num = generateRandomNumber(min, max);
  if(existsInArray(num, playerNums, size)) {
    generatePlayerNumbers(playerNums, size, min, max); // recursively call the function until we get a unique number
  } else {
    playerNums[size-1] = num;
    generatePlayerNumbers(playerNums, size-1, min, max); // recursively call the function for the next number
  }
}

int main() {
  srand(time(NULL));
  
  printf("Welcome to the Bingo Simulator!\n");
  
  int player1[5], player2[5];
  
  printf("Player 1's numbers:\n");
  generatePlayerNumbers(player1, 5, 1, 75);
  for(int i = 0; i < 5; i++) {
    printf("%d ", player1[i]);
  }
  printf("\n");
  
  printf("Player 2's numbers:\n");
  generatePlayerNumbers(player2, 5, 1, 75);
  for(int i = 0; i < 5; i++) {
    printf("%d ", player2[i]);
  }
  printf("\n");
  
  return 0;
}