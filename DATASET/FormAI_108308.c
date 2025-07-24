//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char input[100];
  int len;

  printf("Please enter your input: ");
  scanf("%[^\n]%*c", input); //getting input from user using scanf

  len = strlen(input); //getting string length

  if (len > 50) {
    printf("Input too long. Maximum length is 50 characters.\n");
    exit(1); //exit program if input too long
  }

  for (int i = 0; i < len; i++) {
    if ((input[i] < 65 || input[i] > 90) && //checking for upper case letters
        (input[i] <97 || input[i] > 122) && //checking for lower case letters
        (input[i] <48 || input[i] > 57) && //checking for numbers
        (input[i] != 32)) { //checking for spaces
      input[i] = '_'; //replace invalid characters with underscores
    }
  }

  printf("Sanitized input: %s\n", input); //output sanitized input

  return 0;
}