//FormAI DATASET v1.0 Category: Text processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char myStr[50] = "aBcDe";
  
  printf("Original string: %s\n", myStr);

  // Convert to lowercase
  for(int i = 0; i < strlen(myStr); i++) {
    if(myStr[i] >= 'A' && myStr[i] <= 'Z') {
      myStr[i] += 32;
    }
  }

  printf("Lowercase string: %s\n", myStr);

  // Shuffle the string
  for(int i = 0; i < strlen(myStr)-1; i++) {
    char temp = myStr[i];
    myStr[i] = myStr[i+1];
    myStr[i+1] = temp;
  }

  printf("Shuffled string: %s\n", myStr);

  // Reverse the string
  for(int i = 0; i < strlen(myStr)/2; i++) {
    char temp = myStr[i];
    myStr[i] = myStr[strlen(myStr)-1-i];
    myStr[strlen(myStr)-1-i] = temp;
  }

  printf("Reversed string: %s\n", myStr);

  // Convert to uppercase
  for(int i = 0; i < strlen(myStr); i++) {
    if(myStr[i] >= 'a' && myStr[i] <= 'z') {
      myStr[i] -= 32;
    }
  }

  printf("Uppercase string: %s\n", myStr);

  // Remove vowels
  for(int i = 0; i < strlen(myStr); i++) {
    if(myStr[i] == 'a' || myStr[i] == 'e' || myStr[i] == 'i' || myStr[i] == 'o' || myStr[i] == 'u' ||
       myStr[i] == 'A' || myStr[i] == 'E' || myStr[i] == 'I' || myStr[i] == 'O' || myStr[i] == 'U') {
      for(int j = i; j < strlen(myStr)-1; j++) {
        myStr[j] = myStr[j+1];
      }
      myStr[strlen(myStr)-1] = '\0';
      i--;
    }
  }
  
  printf("Vowels removed: %s\n", myStr);

  return 0;
}