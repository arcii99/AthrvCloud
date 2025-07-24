//FormAI DATASET v1.0 Category: Compression algorithms ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1000

char compressed[MAX_LEN];
char decompressed[MAX_LEN];

char *compress(char *text) {
  int count = 1, total = 0;
  char curr_char = text[0];

  for (int i = 1; i <= strlen(text); i++) {
    if (text[i] == curr_char) {
      count++;
    } else {
      compressed[total++] = curr_char;
      compressed[total++] = count + '0';
      curr_char = text[i];
      count = 1;
    }
  }
  compressed[total] = '\0';
  return compressed;
}

char *decompress(char *text) {
  int total = 0;
  char curr_char;

  for (int i = 0; i < strlen(text); i += 2) {
    curr_char = text[i];
    int count = text[i + 1] - '0';

    for (int j = 0; j < count; j++) {
      decompressed[total++] = curr_char;
    }
  }
  decompressed[total] = '\0';
  return decompressed;
}

int main() {
  char text[MAX_LEN], *compressed_text, *decompressed_text;
  printf("Enter text to be compressed: ");
  scanf("%[^\n]%*c", text);

  compressed_text = compress(text);
  decompressed_text = decompress(compressed_text);

  printf("\nCompressed Text: %s\n", compressed_text);
  printf("Decompressed Text: %s\n", decompressed_text);

  if (strcmp(text, decompressed_text) == 0) {
    printf("Original and decompressed text are same!\n");
  } else {
    printf("Error: Original and decompressed text are not the same.\n");
  }
  return 0;
}