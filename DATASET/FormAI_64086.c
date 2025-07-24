//FormAI DATASET v1.0 Category: Text processing ; Style: automated
#include <stdio.h>
#include <string.h>

int main() {
  char input_str[500];
  char output_str[500];
  
  printf("Enter a sentence: ");
  fgets(input_str, 500, stdin);

  int i, j = 0;
  for(i = 0; i < strlen(input_str); i++) {
    if(input_str[i] == 'a' || input_str[i] == 'e' ||input_str[i] == 'i' ||input_str[i] == 'o' || input_str[i] == 'u') {
      output_str[j++] = input_str[i];
      output_str[j++] = '-';
    } else if(input_str[i] == 'A' || input_str[i] == 'E' ||input_str[i] == 'I' || input_str[i] == 'O' || input_str[i] == 'U') {
      output_str[j++] = input_str[i];
      output_str[j++] = '-';
    } else if(input_str[i] == ' ') {
      output_str[j++] = ' ';
    } else {
      continue;
    }
  }
  output_str[j-1] = '\0';
  printf("The modified sentence is: %s\n", output_str);
  return 0;
}