//FormAI DATASET v1.0 Category: Word Count Tool ; Style: surprised
#include <stdio.h>
#include <string.h>

int main() {
  char input[1000];
  int wordcount = 0;
  printf("Welcome to the C Word Count Tool!\n");
  printf("Please enter a sentence:\n");
  fgets(input, 1000, stdin);  // Read user input
  printf("Analyzing...\n");
  
  // Loop through input to count words
  for(int i = 0; i < strlen(input); i++) {
    if(input[i] == ' ' || input[i] == '\n') {  // Check for space or newline character
      wordcount++;
    }
  }
  
  printf("Your sentence contains %d words!\n", wordcount);
  printf("Wow! You sure have a way with words!\n");
  
  return 0;
}