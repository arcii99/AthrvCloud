//FormAI DATASET v1.0 Category: Text processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function that takes a string as input and returns its reverse
char* reverse_string(char* str) {
  int len = strlen(str);
  char* rev_str = (char*) malloc(sizeof(char) * (len + 1));
  
  for (int i = len - 1, j = 0; i >= 0; i--, j++) {
    rev_str[j] = str[i];
  }
  
  rev_str[len] = '\0'; 
  return rev_str;
}

int main() {
  char input_str[100];
  printf("Enter a string: ");
  scanf("%s", input_str);

  char* output_str = reverse_string(input_str);
  printf("Reversed String: %s\n", output_str);

  free(output_str);
  return 0;
}