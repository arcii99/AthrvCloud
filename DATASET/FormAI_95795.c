//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Define the hash function to get the hash value of a string */
int hash(char *string) {
  int hash = 0;
  int len = strlen(string);

  for (int i = 0; i < len; i++) {
    hash = hash + (int)string[i];
  }
  return (hash % 100);
}

int main() {
  char str[100];
  printf("Enter a string to hash: ");
  fgets(str, 100, stdin); // Get user input

  // Remove newline character
  int len = strlen(str);
  if (str[len-1] == '\n') {
    str[len-1] = 0;
  }

  int hashed_value = hash(str); // Compute the hash value
  printf("Hashed value of %s is: %d\n", str, hashed_value);

  return 0;
}