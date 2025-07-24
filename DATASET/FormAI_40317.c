//FormAI DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the given string
char* compress(char* str) {
  int len = strlen(str);
  char* compressed = (char*)malloc(len * sizeof(char));
  int index = 0;
  int count = 1;

  for (int i = 0; i < len; i++) {
    compressed[index++] = str[i];
    while (i < len - 1 && str[i] == str[i + 1]) {
      count++;
      i++;
    }
    char countstr[10];
    sprintf(countstr, "%d", count);
    for (int j = 0; *(countstr + j); j++) {
      compressed[index++] = countstr[j];
    }
    count = 1;
  }

  compressed[index] = '\0';
  return compressed;
}

int main() {
  // Get the input string from user
  char str[100];
  printf("Enter the string to compress: ");
  scanf("%[^\n]%*c", str);

  // Call compress function to compress the input string
  char* compressed = compress(str);

  // Print the compressed string
  printf("Compressed string: %s\n", compressed);

  free(compressed);
  return 0;
}