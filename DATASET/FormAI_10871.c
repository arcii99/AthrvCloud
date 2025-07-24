//FormAI DATASET v1.0 Category: String manipulation ; Style: invasive
#include <stdio.h>
#include <string.h>

int main() {
  char str[100], c;
  int i, j, len;

  // Asking user for input
  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);

  len = strlen(str);
  
  // Removing all the vowels
  for(i = 0; i < len; i++) {
    c = str[i];
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      for(j = i; j < len; j++) {
        str[j] = str[j + 1];
      }
      len--;
      i--;
    }
  }

  // Reversing the string
  for(i = 0; i < len/2; i++) {
    c = str[i];
    str[i] = str[len - 1 - i];
    str[len - 1 - i] = c;
  }

  // Converting the string to uppercase
  for(i = 0; i < len; i++) {
    if(str[i] >= 'a' && str[i] <= 'z') {
      str[i] = str[i] - 32;
    }
  }

  // Adding '!' at the end of the string
  str[len] = '!';
  str[len+1] = '\0';

  // Printing the final string
  printf("The manipulated string is: %s\n", str);

  return 0;
}