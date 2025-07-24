//FormAI DATASET v1.0 Category: Compression algorithms ; Style: medieval
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_TABLE_SIZE 4096

char *text = "Hello, how are you? I'm doing well, thank you for asking.";

unsigned int table[MAX_TABLE_SIZE][2];
unsigned int table_size = 0;

unsigned int hash(unsigned int prefix, unsigned int suffix) {
  return ((prefix << 12) + suffix) % MAX_TABLE_SIZE;
}

void compress(char *input) {
  unsigned int prefix = *input++;
  while (*input != '\0') {
    unsigned int suffix = *input++;
    unsigned int index = hash(prefix, suffix);
    if (table[index][1] != 0) {
      prefix = table[index][1];
    } else {
      printf("%d ", prefix);
      table[index][0] = table_size++;
      table[index][1] = suffix;
      prefix = suffix;
    }
  }
  printf("%d\n", prefix);
}

int main() {
  memset(table, 0, sizeof(table));
  printf("Original Text: %s\n", text);
  compress(text);
  return 0;
}