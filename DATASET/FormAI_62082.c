//FormAI DATASET v1.0 Category: String manipulation ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  printf("Enter a string: ");
  fgets(str, 100, stdin);              // Reads input from user
  
  // Replaces odd and even characters in the string
  for (int i = 0; i <= strlen(str); i++) {
    if (i % 2 != 0 && str[i] != '\n') {  
      str[i] = '*';
    } else if (i % 2 == 0 && str[i] != '\n') {
      str[i] = '+';
    }
  }

  printf("Output string: %s", str);

  // Finds the number of lowercase, uppercase, and digits in the string
  int lowercase = 0, uppercase = 0, digits = 0;
  for (int j = 0; j <= strlen(str); j++) {
    if (isdigit(str[j])) {
      digits++;
    } else if (islower(str[j])) {
      lowercase++;
    } else if (isupper(str[j])) {
      uppercase++;
    }
  }

  printf("\nNumber of lowercase characters: %d", lowercase);
  printf("\nNumber of uppercase characters: %d", uppercase);
  printf("\nNumber of digits: %d", digits);

  // Removes all spaces from the string
  int count = 0;
  for (int k = 0; k < strlen(str); k++) {
    if (str[k] != ' ') {
      str[count++] = str[k];
    }
  }

  str[count] = '\0';
  printf("\nString after removing spaces: %s", str);

  return 0;
}