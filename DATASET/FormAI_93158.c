//FormAI DATASET v1.0 Category: Text processing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char input_str[100], output_str[100];
  
  printf("Enter a string: ");
  fgets(input_str, 100, stdin); // read input from user
  
  // parse the input string and extract words
  char *token = strtok(input_str, " ");
  int word_count = 0;
  while (token != NULL) {
    strcpy(output_str+(word_count*8), token);
    word_count++;
    token = strtok(NULL, " ");
  }
  
  // print out the extracted words
  printf("The input string contains %d words:\n", word_count);
  int i;
  for (i = 0; i < word_count; i++) {
    printf("%d: %s\n", i+1, output_str+(i*8));
  }
  
  return 0; // program executed successfully
}