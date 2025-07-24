//FormAI DATASET v1.0 Category: Error handling ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Welcome to this exciting C error handling example program!\n\n");

  int num1, num2, result;

  printf("Please enter two numbers to divide: ");
  scanf("%d %d", &num1, &num2);

  if (num2 == 0) {
    printf("Oops! You cannot divide by zero. Please try again.\n");
    exit(1); // we will exit the program with an error code of 1
  } else {
    result = num1 / num2;
    printf("%d divided by %d is %d\n", num1, num2, result);
  }

  char file_name[100];
  printf("\nEnter the name of the file you want to open: ");
  scanf("%s", file_name);

  FILE *fp = fopen(file_name, "r");
  if(fp == NULL) {
    printf("Sorry! Unable to open the file. Please check if the file name is correct and try again later.\n");
    exit(2); //we will exit the program with an error code of 2
  }

  printf("\nFile contents: \n");
  char ch = getc(fp);
  while (ch != EOF) {
    putchar(ch);
    ch = getc(fp);
  }

  fclose(fp);

  printf("\n\nThanks for using this awesome C error handling program. Hope you learned something new!\n");

  return 0;
}