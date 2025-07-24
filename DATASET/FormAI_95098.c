//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Linus Torvalds
#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>

// Define the hash function
uint32_t my_hash(char *str, uint32_t len) {
  uint32_t hash = 5381;
  for (uint32_t i = 0; i < len; i++) {
    hash = ((hash << 5) + hash) + str[i]; /* hash * 33 + c */
  }
  return hash;
}

// Define the main function
int main(int argc, char *argv[]) {
  if (argc != 2) {
      printf("Usage: %s <string>\n", argv[0]);
      return 1;
  }
  char* input_str = argv[1];
  uint32_t input_str_len = strlen(input_str);

  // Calculate the hash
  uint32_t hash = my_hash(input_str, input_str_len);

  // Print the hash
  printf("%u\n", hash);

  return 0;
}