//FormAI DATASET v1.0 Category: Recursive ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

void recursive_function(int count) {
  if(count == 0) {
    printf("Woohoo, recursion is awesome!");
    return;
  }
  
  printf("%d more lines of code to go!\n", count);
  recursive_function(count-1);
}

int main() {
  int num_of_lines = 50;
  
  printf("*** Energetic Recursive Program ***\n");
  printf("Get ready for some recursive fun!\n");
  recursive_function(num_of_lines);
  printf("\nEnd of program.\n");
  
  return 0;
}