//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool recursive_check(char buffer[], int length, int index, char pattern[], int pat_len) {
  if (index >= length) {
    return false;
  }
  
  if (strncmp(&buffer[index], pattern, pat_len) == 0) { // match found!
    return true;
  }
  
  return recursive_check(buffer, length, index+1, pattern, pat_len);
}

int main() {
  FILE *infile;
  char buffer[256];
  char pattern[] = "password";
  int pat_len = strlen(pattern);
  
  // Open the input file
  infile = fopen("input.txt", "r");
  
  if (infile == NULL) {
    printf("Input file cannot be opened!\n");
    exit(1);
  }
  
  while (fgets(buffer, 256, infile)) {
    int length = strlen(buffer);
    if (recursive_check(buffer, length, 0, pattern, pat_len)) {
      printf("Intrusion detected in: %s", buffer);
    }
  }
  
  fclose(infile);
  return 0;
}