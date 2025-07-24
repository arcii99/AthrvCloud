//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: energetic
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  int i, j;
  printf("Enter your input: ");
  fgets(input, 100, stdin); // Get user input

  for(i = 0; i < strlen(input); i++) {
    if(input[i] == '<' || input[i] == '>') { // Check for < and >
      continue;
    }
    else if(input[i] == '/') { // Check for /
      if(input[i+1] == '<') { // Check for allowed tag
        j = i;
        while(j < strlen(input)) {
          if(input[j] == '>') { // Check for end tag
            break;
          }
          j++;
        }
        if(j < strlen(input)) { // End tag found, valid tag
          i = j; // Update index
          continue;
        }
      }
    }

    printf("%c", input[i]); // If character valid, print it
  }

  return 0;
}