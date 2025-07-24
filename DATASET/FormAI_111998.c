//FormAI DATASET v1.0 Category: Word Count Tool ; Style: all-encompassing
#include <stdio.h>
#include <string.h>

int main() {
  char input[1000];
  int count = 0, i;

  printf("Enter a sentence: ");
  fgets(input, 1000, stdin); // read input from user

  // count word logic
  for (i = 0; input[i] != '\0'; i++) {
    if (input[i] == ' ' && input[i+1] != ' ') // check for spaces and ensure it's not consecutive
      count++;
  }

  // if last character is not a space and the word count is at least 1, increment count
  if (input[strlen(input)-2] != ' ' && count >= 1)
    count++;

  printf("Total word count: %d\n", count);

  return 0;
}