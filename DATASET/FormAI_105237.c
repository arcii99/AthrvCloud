//FormAI DATASET v1.0 Category: Compression algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100

char* compress(char* input) {
  int len = strlen(input);
  char* compressed = (char*) malloc(sizeof(char) * MAXSIZE);
  int currentIndex = 0;

  // loop through each character in input
  for (int i = 0; i < len; i++) {
    char currentChar = input[i];
    int count = 1;

    // check if next characters match current character
    while (input[i+1] == currentChar) {
      count++;
      i++;
    }

    // write compressed character to output string
    compressed[currentIndex] = currentChar;
    currentIndex++;

    // write count of consecutive characters to output string
    char countStr[10];
    sprintf(countStr, "%d", count);
    int countLen = strlen(countStr);
    for (int j = 0; j < countLen; j++) {
      compressed[currentIndex] = countStr[j];
      currentIndex++;
    }
  }

  // add null terminating character to output string
  compressed[currentIndex] = '\0';
  return compressed;
}

int main() {
  char* input = "aaabbbcccaaa";
  char* compressed = compress(input);
  printf("Input: %s\nCompressed: %s", input, compressed);
  free(compressed);
  return 0;
}