//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: multivariable
#include <stdio.h>
#include <string.h>

int main() {
  char input[] = "We love cats!";
  char output[50] = "";

  for(int i = 0; i < strlen(input); i++) {
    if(input[i] == 'c') {
      strcat(output, "meow");
    } else if(input[i] == 'C') {
      strcat(output, "MEOW");
    } else if(input[i] == 'A' || input[i] == 'a') {
      strcat(output, "purrr");
    } else if(input[i] == 'T' || input[i] == 't') {
        strcat(output, "hiss");
    } else {
      strcat(output, " ");
    }
  }

  printf("Input: %s\n", input);
  printf("Output: %s\n", output);
  return 0;
}