//FormAI DATASET v1.0 Category: Cat Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  printf("Please enter the C Cat Language code to translate: ");
  fgets(input, 100, stdin);
  input[strcspn(input, "\n")] = 0;
  char output[100] = "";
  int len = strlen(input);
  for(int i=0; i<len; i++) {
    if(input[i] == 'M') {
      strcat(output, "int");
    } else if(input[i] == 'C') {
      strcat(output, "char");
    } else if(input[i] == 'P') {
      strcat(output, "*");
    } else if(input[i] == 'L') {
      strcat(output, "[");
    } else if(input[i] == 'R') {
      strcat(output, "]");
    } else if(input[i] == 'S') {
      strcat(output, " ");
    } else {
      strcat(output, "UNKNOWN_CHARACTER");
    }
  }
  printf("The translated code is: %s\n", output);
  return 0;
}