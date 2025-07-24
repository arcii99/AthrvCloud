//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: optimized
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100
#define MAX_OUTPUT_LENGTH 200

char* translate(char input[MAX_INPUT_LENGTH]) {
  char alphabet[27] = "abcdefghijklmnopqrstuvwxyzz";
  char output[MAX_OUTPUT_LENGTH] = "";
  int length = strlen(input);

  for(int i = 0; i < length; i++) {
    if(input[i] == ' ') {
      strcat(output, " ");
    } else if(input[i] >= 'A' && input[i] <= 'Z') {
      strcat(output, "Meow");
      char c = alphabet[input[i] - 'A'];
      strncat(output, &c, 1);
    } else if(input[i] >= 'a' && input[i] <= 'z') {
      strcat(output, "meow");
      char c = alphabet[input[i] - 'a'];
      strncat(output, &c, 1);
    }
  }

  return output;
}

int main() {
  char input[MAX_INPUT_LENGTH] = "";
  printf("Enter a sentence to translate into C Cat Language: ");
  fgets(input, MAX_INPUT_LENGTH, stdin);
  printf("In C Cat Language, that sentence is: %s", translate(input));
  return 0;
}