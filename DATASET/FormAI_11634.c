//FormAI DATASET v1.0 Category: Educational ; Style: happy
#include <stdio.h>

int main() {
  printf("Welcome to the Happy Code Learning Program!\n\n");
  printf("Today, we are going to learn about arrays and loops!\n\n");

  int myArray[5] = {1, 2, 3, 4, 5};

  printf("My array is:");
  for(int i=0; i<5; i++) {
    printf(" %d", myArray[i]);
  }
  printf("\n\n");
  printf("Now, let's double each element in the array using a loop!\n\n");

  for(int i=0; i<5; i++) {
    myArray[i] = myArray[i] * 2;
    printf("Element %d is now %d\n", i+1, myArray[i]);
  }

  printf("\n\n");
  printf("The final array is:");
  for(int i=0; i<5; i++) {
    printf(" %d", myArray[i]);
  }
  printf("\n\n");
  printf("Great job! You've learned how to use arrays and loops in C!\n");
  
  return 0;
}