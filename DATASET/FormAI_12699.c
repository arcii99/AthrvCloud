//FormAI DATASET v1.0 Category: Text processing ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  printf("Enter the text to process: ");
  fgets(input, 100, stdin); // Taking input from the user

  // Word Count
  int count = 0;
  for(int i=0; i<strlen(input); i++) {
    if(input[i] == ' ' || input[i] == '\n' || input[i] == '\t') count++;
  }

  // Capitalize every other letter
  for(int i=0; i<strlen(input); i++) {
    if(i%2 == 0) {
      if(input[i] >= 'a' && input[i] <= 'z') input[i] -= 32;
    }
  }

  // Remove vowels
  char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  char output[100];
  int j = 0;
  for(int i=0; i<strlen(input); i++) {
    int found = 0;
    for(int k=0; k<10; k++) {
      if(input[i] == vowels[k]) {
        found = 1;
        break;
      }
    }
    if(found == 0) {
      output[j] = input[i];
      j++;
    }
  }
  output[j] = '\0';

  // Reverse the text
  char reversed[100];
  j = 0;
  for(int i=strlen(output)-1; i>=0; i--) {
    reversed[j] = output[i];
    j++;
  }
  reversed[j] = '\0';

  // Print the processed text
  printf("Processed Text: %s\n", reversed);
  printf("Word Count: %d\n", count+1);

  return 0;
}