//FormAI DATASET v1.0 Category: String manipulation ; Style: curious
#include <stdio.h>
#include <string.h>

int main() {

  char input[100];
  char output[100];

  printf("Welcome adventurer! Please tell me your name: ");
  fgets(input, sizeof(input), stdin);

  // Remove newline character from input 
  int len = strlen(input);
  if (input[len-1] == '\n') {
    input[len-1] = '\0';
  }

  printf("Greetings, %s! Let me scramble your name...\n", input);

  // Convert characters in input string to ASCII codes and add them up
  int sum = 0;
  for (int i = 0; i < strlen(input); i++) {
    sum += (int)input[i];
  }

  // Convert sum to string
  char sum_str[10];
  sprintf(sum_str, "%d", sum);

  // Reverse the characters in sum_str
  char rev_sum_str[10];
  int j = 0;
  for (int i = strlen(sum_str)-1; i >= 0; i--) {
    rev_sum_str[j] = sum_str[i];
    j++;
  }
  rev_sum_str[strlen(sum_str)] = '\0';

  // Add rev_sum_str to input string to get output string
  strcpy(output, input);
  strcat(output, rev_sum_str);

  printf("Your new name is: %s\n", output);

  return 0;
}