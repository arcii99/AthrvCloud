//FormAI DATASET v1.0 Category: Text processing ; Style: introspective
#include <stdio.h>
#include <string.h>

int main() {
  char input[100], output[100];
  int count = 0, length, i;

  printf("Enter a string: ");
  fgets(input, sizeof(input), stdin); // read input from user

  length = strlen(input);

  // loop through each character and count how many are lowercase
  for (i = 0; i < length; i++) {
    if (input[i] >= 'a' && input[i] <= 'z') {
      count++;
    }
  }

  // print out the original string
  printf("Original String: %s", input);

  // if there are more lowercase letters than uppercase letters
  if (count > (length - count)) {
    // loop through each character and convert to lowercase if it is uppercase
    for (i = 0; i < length; i++) {
      if (input[i] >= 'A' && input[i] <= 'Z') {
        output[i] = input[i] + 32; // add 32 to convert uppercase to lowercase
      } else {
        output[i] = input[i]; // copy the character as is
      }
    }
    output[length] = '\0'; // add null terminator to end of string
    printf("Modified String: %s", output);
  } else {
    // if there are more uppercase letters than lowercase letters
    printf("Too many uppercase letters!");
  }

  return 0;
}