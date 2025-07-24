//FormAI DATASET v1.0 Category: Compression algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to compress the string
char* compress(char* str) {
  char* compressed = (char*) malloc(MAX_LEN * sizeof(char));
  
  int j = 0, count = 1;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] == str[i+1]) {
      count++;
    } else {
      compressed[j++] = str[i];
      compressed[j++] = count + '0'; // convert count to char and add to compressed string
      count = 1;
    }
  }
  compressed[j] = '\0';
  if (strlen(compressed) >= strlen(str)) { // if compressed string is longer than original string
    return str; // return original string
  } else {
    return compressed; // return compressed string
  }
}

// Driver code
int main() {
  char str[MAX_LEN];
  printf("Enter a string: ");
  fgets(str, MAX_LEN, stdin);
  str[strlen(str)-1] = '\0'; // remove newline character from input string
  
  char* compressed = compress(str);
  printf("Compressed string: %s\n", compressed);
  
  free(compressed);
  return 0;
}