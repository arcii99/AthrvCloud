//FormAI DATASET v1.0 Category: Text processing ; Style: real-life
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  char output[100];
  int i, j, counter=0;

  printf("Enter some text: ");
  scanf("%[^\n]", input);  // input the whole line

  for(i=0; i<strlen(input); i++) {
    if(input[i]=='e' || input[i]=='E') {  // if it's an "e" or "E"
      counter++;
    }
    else {
      output[j]=input[i];  // else, add the character to the output string
      j++;
    }
  }

  output[j]='\0';  // add null character at the end

  printf("Your text without E's: %s\n", output);
  printf("The number of E's: %d\n", counter);

  return 0;
}