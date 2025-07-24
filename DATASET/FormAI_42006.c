//FormAI DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the frequency of each character
int frequency(char *text, int n, char c) {
  int count = 0;
  for (int i = 0; i < n; i++)
    if (text[i] == c)
      count++;
  return count;
}

// Struct to hold a character and its frequency
typedef struct {
  char c;
  int freq;
} character;

// Function to compare two characters by frequency for sorting
int compare_freq(const void *a, const void *b) {
  const character *ca = (const character *) a;
  const character *cb = (const character *) b;
  return (cb->freq - ca->freq);
}

// Function to compress the text using Huffman coding
void compress(char *text, int n) {
  // Allocate memory for each character and its frequency
  character *chars = malloc(n * sizeof(character));
  if (chars == NULL) exit(1);

  // Calculate the frequency of each character
  int num_chars = 0;
  for (int i = 0; i < n; i++) {
    char c = text[i];
    if (frequency(text, i, c) == 0) {
      chars[num_chars].c = c;
      chars[num_chars].freq = frequency(text, n, c);
      num_chars++;
    }
  }

  // Sort the characters by frequency
  qsort(chars, num_chars, sizeof(character), compare_freq);

  // Create Huffman tree
  while (num_chars > 1) {
    // Combine the two characters with the lowest frequency
    character *a = &chars[num_chars - 1];
    character *b = &chars[num_chars - 2];
    character *node = malloc(sizeof(character));
    if (node == NULL) exit(1);
    node->freq = a->freq + b->freq;
    node->c = 0;
    // Move the combined character to the end of the list
    chars[num_chars - 2] = *node;
    num_chars--;
    free(node);
    // Resort the list by frequency
    qsort(chars, num_chars, sizeof(character), compare_freq);
  }

  // Dictionary to hold Huffman codes for each character
  const int MAX_DICT_SIZE = 128; // ASCII characters
  char *dict[MAX_DICT_SIZE];
  for (int i = 0; i < MAX_DICT_SIZE; i++)
    dict[i] = NULL;

  // Traverse Huffman tree to build dictionary
  char prefix[128]; // Maximum code length is n - 1
  prefix[0] = 0;
  int prefix_len = 1;
  void traverse(character *node) {
    if (node->c != 0)
      dict[(int) node->c] = strdup(prefix);
    else {
      prefix[prefix_len++] = '0';
      traverse(&chars[num_chars - prefix_len]);
      prefix_len--;
      prefix[prefix_len++] = '1';
      traverse(&chars[num_chars - prefix_len]);
      prefix_len--;
    }
  }
  traverse(&chars[num_chars - 1]);

  // Print dictionary for debugging purposes
  for (int i = 0; i < MAX_DICT_SIZE; i++)
    if (dict[i] != NULL)
      printf("%c: %s\n", (char) i, dict[i]);

  // Compress the text using the dictionary
  for (int i = 0; i < n; i++) {
    char *code = dict[(int) text[i]];
    if (code == NULL) {
      fprintf(stderr, "Undefined character %c!\n", text[i]);
      exit(1);
    }
    printf("%s", code);
  }
  printf("\n");

  // Free memory
  for (int i = 0; i < MAX_DICT_SIZE; i++)
    free(dict[i]);
  free(chars);
}

int main() {
  // Example text to compress
  char *text = "MISSISSIPPI RIVER";
  int n = strlen(text);

  // Compress the text using Huffman coding
  compress(text, n);

  return 0;
}