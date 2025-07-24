//FormAI DATASET v1.0 Category: String manipulation ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR_LEN 50

int main() {

  char input_str[MAX_STR_LEN + 1];
  char output_str[MAX_STR_LEN + 1];
  int length = 0;
  int num_upper = 0;
  int num_lower = 0;
  int num_digits = 0;
  int num_special = 0;
  int paranoid_score = 0;
  int i;

  printf("Enter a string (max length %d): ", MAX_STR_LEN);
  fgets(input_str, MAX_STR_LEN+1, stdin);
  length = strlen(input_str);

  // Copy input string to output string
  strcpy(output_str, input_str);

  // Calculate number of uppercase, lowercase characters, digits, and special characters
  for(i = 0; i < length; i++) {
    if(isupper(input_str[i])) {
      num_upper++;
    }
    else if(islower(input_str[i])) {
      num_lower++;
    }
    else if(isdigit(input_str[i])) {
      num_digits++;
    }
    else if(!isspace(input_str[i])) {
      num_special++;
    }
  }

  // Calculate paranoid score based on number of characters and type of characters
  paranoid_score = length * 2;
  paranoid_score += num_upper * 5;
  paranoid_score += num_lower * 3;
  paranoid_score += num_digits * 4;
  paranoid_score += num_special * 6;

  // Print out paranoid score and output string
  printf("Paranoid Score: %d\n", paranoid_score);
  printf("Output String: %s\n", output_str);

  return 0;
}