//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: irregular
#include <stdio.h>
#include <string.h>

void countFrequency(char *str) {
  // create an array to store the frequency of characters
  int freq[256] = {0};

  // loop through the string and update the frequency array
  for (int i = 0; i < strlen(str); i++) {
    freq[str[i]]++;
  }

  // print the frequency of each character
  for (int i = 0; i < 256; i++) {
    if (freq[i] != 0) {
      printf("'%c' appears %d time(s) in the string.\n", i, freq[i]);
    }
  }
}

int main() {
  char str[100];

  printf("Enter a string: ");
  scanf("%[^\n]s", str);

  countFrequency(str);

  return 0;
}