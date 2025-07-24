//FormAI DATASET v1.0 Category: Memory management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

int main() {
  // The memory puzzle begins!
  int puzzling_num = 576;
  char puzzling_char = '5';
  float puzzling_float = 5.76;

  // Malloc the memory for the int
  int *puzzling_ptr_num = (int*)malloc(sizeof(int));
  *puzzling_ptr_num = puzzling_num;

  // Malloc the memory for the char
  char *puzzling_ptr_char = (char*)malloc(sizeof(char));
  *puzzling_ptr_char = puzzling_char;

  // Malloc the memory for the float
  float *puzzling_ptr_float = (float*)malloc(sizeof(float));
  *puzzling_ptr_float = puzzling_float;

  // Print out the results
  printf("The puzzling number is: %d\n", *puzzling_ptr_num);
  printf("The puzzling char is: %c\n", *puzzling_ptr_char);
  printf("The puzzling float is: %f\n", *puzzling_ptr_float);

  // Free the memory
  free(puzzling_ptr_num);
  free(puzzling_ptr_char);
  free(puzzling_ptr_float);

  // The puzzle is complete!
  return 0;
}