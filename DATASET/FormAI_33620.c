//FormAI DATASET v1.0 Category: Text processing ; Style: innovative
#include <stdio.h>
#include <string.h>

int main() {
  char str[100];
  int vowels = 0, consonants = 0, digits = 0, spaces = 0, others = 0;

  printf("Enter a string: ");
  fgets(str, sizeof(str), stdin);

  for (int i = 0; str[i] != '\0'; i++) {

    if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
        str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || 
        str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
      vowels++;
    } else if ((str[i] >= 'a' && str[i] <= 'z') || 
               (str[i] >= 'A' && str[i] <= 'Z')) {
      consonants++;
    } else if (str[i] >= '0' && str[i] <= '9') {
      digits++;
    } else if (str[i] == ' ') {
      spaces++;
    } else {
      others++;
    }
  }

  printf("Vowels: %d\n", vowels);
  printf("Consonants: %d\n", consonants);
  printf("Digits: %d\n", digits);
  printf("Spaces: %d\n", spaces);
  printf("Others: %d\n", others);

  return 0;
}