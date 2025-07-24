//FormAI DATASET v1.0 Category: Math exercise ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  srand(time(NULL)); // initialize random seed
  
  int num1 = rand() % 101; // generate a random number between 0 and 100
  int num2 = rand() % 101;
  
  printf("What is the sum of %d and %d?\n", num1, num2);
  
  int answer;
  scanf("%d", &answer);
  
  if (answer == num1 + num2) {
    printf("Congratulations, you got the correct answer!\n");
  }
  else {
    printf("Sorry, the correct answer is %d.\n", num1 + num2);
  }
  
  return 0;
}