//FormAI DATASET v1.0 Category: Error handling ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

void error_handler(int errcode) {
  switch(errcode) {
    case 1:
      printf("Error: Invalid input!\n");
      break;
    case 2:
      printf("Error: Memory allocation failed!\n");
      break;
    case 3:
      printf("Error: File not found!\n");
      break;
    default:
      printf("Unknown error occurred!\n");
      break;
  }
  exit(1);
}

int main() {
  int num;
  printf("Enter a number between 1 and 10: ");
  scanf("%d", &num);
  if(num < 1 || num > 10)
    error_handler(1);

  int *arr = malloc(num * sizeof(int));
  if(!arr)
    error_handler(2);

  FILE *fp = fopen("data.txt", "r");
  if(!fp)
    error_handler(3);

  // Other code goes here

  return 0;
}