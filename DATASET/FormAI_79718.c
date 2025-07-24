//FormAI DATASET v1.0 Category: Compression algorithms ; Style: funny
#include <stdio.h>

// A funny C compression algorithm

int main() {
  char str[100], compressed[100];
  int i, j, k;

  printf("Welcome to the Fun Compression Algorithm! Please enter your string: ");
  fgets(str, 100, stdin); // gets input from user

  printf("\nCompressing.......");

  // compressing the string
  for (i = 0, j = 0; str[i] != '\0'; i += k) {
    k = 1;
    while (str[i + k] == str[i]) {
      k++;
    }
    if (k == 1) {
      compressed[j++] = str[i];
    } else {
      compressed[j++] = str[i];
      compressed[j++] = k + '0'; // converts integer to character
    }
  }
  compressed[j] = '\0'; // terminates the compressed string

  printf("\n\nYour compressed string is: %s", compressed);
  printf("\nWow, we just compressed this string and saved you %d bytes!\n\n", (int)strlen(str) - (int)strlen(compressed));

  return 0;
}