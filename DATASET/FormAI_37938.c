//FormAI DATASET v1.0 Category: Syntax parsing ; Style: curious
#include <stdio.h>

int main() {
  printf("Hello there! I'm a curious chatbot. How can I assist you today?\n");
  printf("Would you like me to parse some C syntax for you? I find it quite fascinating!\n");
  printf("Please enter a C code fragment for me to parse:\n");
  
  char input[100];
  scanf("%[^\n]", input);
  
  int num_ints = 0;
  int num_floats = 0;
  int num_chars = 0;
  int num_strings = 0;
  
  char *pos = input;
  
  while (*pos != '\0') {
    if (*pos == 'i' && *(pos+1) == 'n' && *(pos+2) == 't') {
      num_ints++;
    } else if (*pos == 'f' && *(pos+1) == 'l' && *(pos+2) == 'o' && *(pos+3) == 'a' && *(pos+4) == 't') {
      num_floats++;
    } else if (*pos == 'c' && *(pos+1) == 'h' && *(pos+2) == 'a' && *(pos+3) == 'r') {
      num_chars++;
    } else if (*pos == '"' || *pos == '\'') {
      num_strings++;
      pos++;
      while (*pos != '"' && *pos != '\'') {
        pos++;
      }
    }
    pos++;
  }
  
  printf("Thanks for the code! Here are some C syntax stats for you:\n");
  printf("Number of integers: %d\n", num_ints);
  printf("Number of floating point numbers: %d\n", num_floats);
  printf("Number of characters: %d\n", num_chars);
  printf("Number of strings: %d\n", num_strings);
  
  printf("I hope you found that interesting. Let me know if you need more help with anything!");

  return 0;
}