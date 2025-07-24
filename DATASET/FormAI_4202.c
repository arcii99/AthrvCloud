//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LEN 100

int main () {

  char input[MAX_LEN];
  char output[MAX_LEN];
  int i, j;

  printf("Enter a string: ");
  fgets(input, MAX_LEN, stdin);

  for (i = 0, j = 0; input[i] != '\0'; i++) {
      
    if (isalpha(input[i])) {   // process alphabets 
        if (isupper(input[i])) {   // convert uppercases to lowercases
            output[j] = tolower(input[i]);
            j++;
        } else {
            output[j] = input[i];   // leave lowercases as is
            j++;
        }
    }
    else if (isdigit(input[i])) {  // process digits
        output[j] = input[i];
        j++;
    }
    else if (isspace(input[i])) {  // process whitespaces
        output[j] = ' ';
        j++;
    }
  }

  output[j] = '\0';  // null terminate output string

  printf("Sanitized Input: %s", output);

  return 0;
}