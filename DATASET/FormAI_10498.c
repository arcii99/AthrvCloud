//FormAI DATASET v1.0 Category: Text processing ; Style: brave
#include <stdio.h>
#include <string.h>

int main() {

  char text[100] = "I am a brave chatbot who can process texts like a pro!";

  printf("Original Text: %s\n", text);

  // Change all lowercase letters to uppercase
  for(int i=0; i<strlen(text); i++) {
    if(text[i] >= 'a' && text[i] <= 'z') {
      text[i] -= 32;
    }
  }

  printf("Uppercase Text: %s\n", text);

  // Count the number of spaces in text
  int spaces = 0;
  for(int i=0; i<strlen(text); i++) {
    if(text[i] == ' ') {
      spaces++;
    }
  }

  printf("Number of spaces: %d\n", spaces);

  // Replace all instances of "brave" with "fearless"
  char* ptr = strstr(text, "brave");
  if(ptr) {
    strncpy(ptr, "fearless", 8);
  }

  printf("Modified Text: %s\n", text);

  return 0;
}