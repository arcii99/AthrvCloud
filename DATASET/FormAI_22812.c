//FormAI DATASET v1.0 Category: Error handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void handle_error(int error_code) {
  switch(error_code) {
    case 1:
      printf("Error: cannot divide by zero!\n");
      exit(1);
    case 2:
      printf("Error: invalid input!\n");
      exit(1);
    case 3:
      printf("Error: file not found!\n");
      exit(1);
    default:
      printf("Unknown error!\n");
      exit(1);
  }
}

int divide(int a, int b) {
  if(b == 0) {
    handle_error(1);
  } else {
    return a / b;
  }
}

int get_index(int array[], int array_size, int target) {
  if(array_size <= 0) {
    handle_error(2);
  } else if(array[array_size - 1] == target) {
    return array_size - 1;
  } else {
    return get_index(array, array_size - 1, target);
  }
}

void read_file(char* filename) {
  FILE *fp;
  fp = fopen(filename, "r");

  if(fp == NULL) {
    handle_error(3);
  } else {
    printf("File opened successfully!\n");
    fclose(fp);
  }
}

int main() {
  int a = 10;
  int b = 0;
  int array[] = {1,2,3,4,5};
  int array_size = sizeof(array)/sizeof(array[0]);
  int target = 3;
  char* filename = "example.txt";

  printf("a/b = %d\n", divide(a, b));

  printf("Index of %d in array is %d\n", target, get_index(array, array_size, target));

  read_file(filename);

  printf("Program completed successfully!\n");

  return 0;
}