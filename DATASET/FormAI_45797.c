//FormAI DATASET v1.0 Category: Fractal Generation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// function to determine if a number is prime
int isPrime(int num) {
  if (num < 2) {
    return 0;
  }
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      return 0;
    }
  }
  return 1;
}

// function to generate fractal
void generateFractal(int limit) {
  int arr[limit][limit];
  int count = 0;

  // initialize array to -1
  for (int i = 0; i < limit; i++) {
    for (int j = 0; j < limit; j++) {
      arr[i][j] = -1;
    }
  }

  // randomly fill array with 0's and prime numbers
  for (int i = 0; i < limit; i++) {
    for (int j = 0; j < limit; j++) {
      if (rand() % 2 == 0) {
        arr[i][j] = 0;
        count++;
      }
      else {
        int num = rand() % (limit*limit);
        while (!isPrime(num)) {
          num = rand() % (limit*limit);
        }
        arr[i][j] = num;
      }
    }
  }

  // print out fractal
  for (int i = 0; i < limit; i++) {
    for (int j = 0; j < limit; j++) {
      if (arr[i][j] == 0) {
        printf(" ");
      }
      else {
        printf("%d", arr[i][j]);
      }
    }
    printf("\n");
  }

  // print out statistics
  printf("\nTotal number of 0's: %d\n", count);
  printf("Total number of prime numbers: %d\n", limit*limit - count);
}

int main() {
  srand(time(0)); // seed random number generator with current time
  int limit;
  printf("Enter limit (must be a perfect square): ");
  scanf("%d", &limit);
  generateFractal(limit);
  return 0;
}