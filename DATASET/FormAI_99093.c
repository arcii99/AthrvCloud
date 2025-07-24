//FormAI DATASET v1.0 Category: Syntax parsing ; Style: retro
#include<stdio.h>
#include<stdlib.h>

int main() {
  char input[100];
  int i = 0, flag = 0, brackets = 0;
  printf("Enter a C program:\n");
  scanf("%[^\n]s", input);
  while(input[i] != '\0') {
    if(input[i] == '(') {
      brackets++;
    }
    else if(input[i] == ')') {
      brackets--;
    }
    if(brackets < 0) {
      flag = 1;
      break;
    }
    if(input[i] == '{' || input[i] == '[' || input[i] == '(') {
      brackets++;
    }
    else if(input[i] == '}' || input[i] == ']' || input[i] == ')') {
      brackets--;
    }
    if(brackets < 0) {
      flag = 2;
      break;
    }
    i++;
  }
  if(flag == 1) {
    printf("\nERROR: Mismatched )");
  }
  else if(flag == 2) {
    printf("\nERROR: Mismatched %c", input[i-1]);
  }
  else if(brackets > 0) {
    printf("\nERROR: Mismatched (");
  }
  else {
    printf("\nSUCCESS: Syntax is correct");
  }
  return 0;
}