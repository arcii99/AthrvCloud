//FormAI DATASET v1.0 Category: Data validation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
  char str[50]; //we will accept strings of up to 50 characters
  int num;
  
  printf("Please enter a string: ");
  fgets(str, 50, stdin); //accept user input
  
  printf("Please enter a number between 1 and 50: ");
  if(scanf("%d", &num) != 1 || num < 1 || num > 50) { //validate user input
    printf("Invalid input!\n");
    exit(1); //exit program with error message
  }
  
  printf("You entered: %s\n", str); //print user input
  printf("You entered: %d\n", num); //print user input
  
  int i;
  for(i = 0; str[i] != '\0'; i++) { //loop through each character of the string
    if(!isalpha(str[i])) { //if the character is not a letter
      printf("Invalid input!\n");
      exit(1); //exit program with error message
    }
  }
  
  printf("String input is valid!\n");
  printf("Number input is valid!\n");
  
  return 0;
}