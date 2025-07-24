//FormAI DATASET v1.0 Category: Syntax parsing ; Style: artistic
// An Artistic C Syntax Parsing Example Program
// by Chatbot

#include <stdio.h>

// define a custom function that takes an array as an argument
void parse(int arr[]) {
  int i;
  // loop through the array and print each element
  for (i = 0; i < sizeof(arr)/sizeof(int); i++) {
    printf("%d ", arr[i]);
  }
}

int main() {
  printf("Welcome to my artistic C syntax parsing example program!\n");

  // declare and initialize an array
  int myArr[] = {1, 2, 3, 4, 5};

  printf("Before parsing: ");
  parse(myArr); // call the parse function on myArr

  // modify the array by increasing each element by 1
  int i;
  for (i = 0; i < sizeof(myArr)/sizeof(int); i++) {
    myArr[i]++;
  }

  printf("\nAfter parsing: ");
  parse(myArr); // call the parse function again on myArr

  return 0;
}