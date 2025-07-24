//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: scalable
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  printf("Enter a Cat language sentence: ");
  fgets(input, 100, stdin); // read input from user

  char output[100];
  // loop through each character of the input
  for(int i=0; i<strlen(input); i++) {
    char c = input[i];
    if(c == 'c' || c == 'C') {
      strcat(output, "meow"); // convert "c" to "meow"
    } else {
      // append the original character to the output
      char temp[2] = {c};
      strcat(output, temp);
    }
  }

  printf("Cat language translated to English: %s", output);
  return 0;
}