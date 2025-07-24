//FormAI DATASET v1.0 Category: Error handling ; Style: Donald Knuth
#include <stdio.h>

int main() {
  int num1, num2, result;

  printf("Enter two numbers:\n");
  scanf("%d%d", &num1, &num2);

  if(num2 == 0) { // Division by zero error handling
    printf("Error: Cannot divide by zero\n");
    return 1;
  }

  result = num1 / num2; // Safe division

  // Printing the result
  printf("%d / %d = %d\n", num1, num2, result);
  
  FILE *fp;

  fp = fopen("example.txt", "r");

  if(fp == NULL) { // File not found error handling
    printf("Error: File does not exist\n");
    return 1;
  }

  // Reading the contents of the file
  char ch;
  while((ch = fgetc(fp)) != EOF) {
    printf("%c", ch);
  }

  fclose(fp);

  return 0;
}