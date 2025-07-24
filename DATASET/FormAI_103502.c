//FormAI DATASET v1.0 Category: Text processing ; Style: random
#include <stdio.h>

int main() {
  char str[100], vowels[50] = {'\0'};
  int i, j = 0;

  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);

  for (i = 0; i < strlen(str); i++) {
    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
      vowels[j] = str[i];
      j++;
    }
    else if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = str[i] + 32;
    }
  }

  printf("\nThe string after converting to lowercase and extracting vowels is:\n");

  for (i = 0; i < strlen(str); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      printf("%c", str[i]);
    }
  }

  printf("\nThe vowels in the string are: %s", vowels);

  return 0;
}