//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int rows = 5; // number of rows
  int cols = 5; // number of columns
  int arr[rows][cols]; // array to hold all the numbers
  int called[rows*cols]; // array to hold called numbers
  int numCalled = 0; // number of called numbers
  int numToCall = rows*cols; // total number of balls to call

  // initialize arrays
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      arr[i][j] = i*cols + j + 1; // fill array with numbers
    }
  }

  // shuffle the numbers
  srand(time(NULL)); // seed the random number generator
  for (int i = 0; i < rows*cols - 1; i++) {
    int j = rand() % (rows*cols - i) + i; // randomly select a number to swap with
    int temp = arr[i/cols][i%cols];
    arr[i/cols][i%cols] = arr[j/cols][j%cols];
    arr[j/cols][j%cols] = temp; // swap the numbers
  }

  // game loop
  int gameOver = 0;
  while (!gameOver) {
    // print the current board
    printf("  ");
    for (int i = 1; i <= cols; i++) {
      printf("%2d ", i);
    }
    printf("\n");
    for (int i = 0; i < rows; i++) {
      printf("%2d ", i+1);
      for (int j = 0; j < cols; j++) {
        if (arr[i][j] == 0) {
          printf("   ");
        } else {
          printf("%2d ", arr[i][j]);
        }
      }
      printf("\n");
    }
    printf("\n");

    // get user input
    char input[3];
    printf("Enter the number (or 'q' to quit): ");
    scanf("%s", input);

    // check if the user wants to quit
    if (input[0] == 'q') {
      gameOver = 1;
      continue;
    }

    // convert the input to an int
    int num = atoi(input);

    // check if the number is valid
    if (num < 1 || num > rows*cols) {
      printf("Invalid input!\n\n");
      continue;
    }

    // check if the number has already been called
    int alreadyCalled = 0;
    for (int i = 0; i < numCalled; i++) {
      if (called[i] == num) {
        alreadyCalled = 1;
        break;
      }
    }
    if (alreadyCalled) {
      printf("Number %d has already been called!\n\n", num);
      continue;
    }

    // mark the number as called and add it to the list
    called[numCalled++] = num;

    // check if the number is on the board
    int found = 0;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        if (arr[i][j] == num) {
          arr[i][j] = 0; // mark the number as found
          found = 1;
          break;
        }
      }
      if (found) {
        break;
      }
    }

    // check if the game is over
    if (numCalled == numToCall) {
      gameOver = 1;
      printf("GAME OVER! You won!\n\n");
    }
  }

  // print the list of called numbers
  printf("Called numbers:\n");
  for (int i = 0; i < numCalled; i++) {
    printf("%d ", called[i]);
  }
  printf("\n");

  return 0;
}