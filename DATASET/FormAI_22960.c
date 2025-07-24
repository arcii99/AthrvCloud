//FormAI DATASET v1.0 Category: Math exercise ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL)); // seed random number generator
  
  // generate random numbers between 1 and 10
  int a = rand() % 10 + 1;
  int b = rand() % 10 + 1;
  
  // generate random operator (+, -, *)
  char op;
  int result;
  switch(rand() % 3) {
    case 0:
      op = '+';
      result = a + b;
      break;
    case 1:
      op = '-';
      result = a - b;
      break;
    case 2:
      op = '*';
      result = a * b;
      break;
  }
  
  // print exercise
  printf("Solve the following math exercise:\n");
  printf("%d %c %d = ?\n", a, op, b);
  
  // get user input
  int answer;
  printf("Your answer: ");
  scanf("%d", &answer);
  
  // check answer
  if(answer == result) {
    printf("Correct!\n");
  } else {
    printf("Incorrect, the correct answer is %d.\n", result);
  }
  
  return 0;
}