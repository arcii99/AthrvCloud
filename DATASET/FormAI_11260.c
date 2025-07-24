//FormAI DATASET v1.0 Category: Text processing ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  printf("Enter your message: ");
  fgets(input, 100, stdin);
  
  // Remove any vowels
  for(int i = 0; i < strlen(input); i++) {
    switch(input[i]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        input[i] = '-';
    }
  }
  
  // Reverse the message
  char output[100];
  int j = 0;
  for(int i = strlen(input)-1; i >= 0; i--) {
    output[j] = input[i];
    j++;
  }
  output[j] = '\0';
  
  // Convert to uppercase
  for(int i = 0; i < strlen(output); i++) {
    if(output[i] >= 'a' && output[i] <= 'z') {
      output[i] = output[i] - 32;
    }
  }
  
  // Print the final message
  printf("Your message is:\n%s\n", output);
  
  return 0;
}