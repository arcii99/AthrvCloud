//FormAI DATASET v1.0 Category: Educational ; Style: Ken Thompson
#include <stdlib.h>
#include <stdio.h>

int main() {
  int myNumbers[5] = { 1, 2, 3, 4, 5 };
  int mySum = 0;
  for(int i = 0; i < 5; i++) {
    mySum += myNumbers[i];
  }
  printf("The sum of myNumbers is: %d\n", mySum);

  char myString[4] = {'F','u','n','\0'};
  printf("My favorite word is: %s\n", myString);

  char myGrade = 'A';
  if (myGrade == 'A') {
    printf("Great job!\n");
  } else {
    printf("Better luck next time.\n");
  }

  int myAge = 25;
  switch(myAge) {
    case 18:
      printf("You're an adult now!\n");
      break;
    case 21:
      printf("Drink responsibly!\n");
      break;
    case 25:
      printf("You're a quarter-century old now!\n");
      break;
    default:
      printf("Age is just a number.\n");
  }

  int myNum = 100;
  int* myNumPtr = &myNum;
  printf("The value of myNum is: %d\n", *myNumPtr);
  return 0;
}