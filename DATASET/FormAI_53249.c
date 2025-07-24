//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: cheerful
#include<stdio.h>

int main(){
  printf("Welcome to the cheerful Checksum Calculator!");
  printf("\nThis program calculates the C Checksum of any input string.\n");

  char input[100];
  int checksum = 0;

  printf("\nPlease enter the input string: ");
  gets(input);

  for(int i=0; input[i] != '\0'; i++){
    checksum += input[i];
  }

  checksum = ~(checksum) + 1;

  printf("\nThe C Checksum of the input string is: %d\n", checksum);

  printf("\nThank you for using the Checksum Calculator! Have a cheerful day!");

  return 0;
}