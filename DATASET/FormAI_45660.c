//FormAI DATASET v1.0 Category: Text processing ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

void main() {
  char input[50];
  int sum = 0;
  printf("Enter a mathematical expression: ");
  scanf("%s", input);

  for(int i = 0; input[i] != '\0'; i++) {
    if(input[i] == '+') {
      int num = atoi(&input[i+1]);
      sum += num;
    }
    else if(input[i] == '-') {
      int num = atoi(&input[i+1]);
      sum -= num;
    }
    else if(input[i] == '/') {
      int num = atoi(&input[i+1]);
      sum /= num;
    }
    else if(input[i] == '*') {
      int num = atoi(&input[i+1]);
      sum *= num;
    }
    else {
      continue;
    }
  }
  printf("Result: %d", sum);
}