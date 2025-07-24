//FormAI DATASET v1.0 Category: Random ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandom(int min, int max) {
  if(min == max) {
    return min;
  }
  else if(min > max) {
    return generateRandom(max, min);
  }
  else {
    return (rand() % (max - min + 1)) + min;
  }
}

int main() {
  srand(time(NULL));
  printf("The random numbers between 1 and 100 generated are:\n");
  for(int i = 0; i < 10; i++) {
    int randomNum = generateRandom(1, 100);
    printf("%d\n", randomNum);
  }
  return 0;
}