//FormAI DATASET v1.0 Category: Compression algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
  char symbol;
  int count;
} CharCount;

int compare_char_count(const void* a, const void* b) {
  int freqDiff = ((CharCount*) b)->count - ((CharCount*) a)->count;
  return (freqDiff == 0) ? ((CharCount*) a)->symbol - ((CharCount*) b)->symbol : freqDiff;
}

void compress(FILE* input, FILE* output) {
  // Step 1: Count the frequency of each character in the input
  CharCount frequencies[BUFFER_SIZE] = {0};
  char buffer[BUFFER_SIZE];
  int charsRead;
  while ((charsRead = fread(buffer, sizeof(char), BUFFER_SIZE, input)) > 0) {
    for (int i = 0; i < charsRead; i++) {
      char c = buffer[i];
      CharCount* charCount = &frequencies[c];
      if (charCount->symbol == 0) {
        charCount->symbol = c;
      }
      charCount->count++;
    }
  }
  
  // Step 2: Sort the frequencies in descending order
  qsort(frequencies, BUFFER_SIZE, sizeof(CharCount), compare_char_count);
  
  // Step 3: Generate the codebook
  char codebook[BUFFER_SIZE][BUFFER_SIZE] = {0};
  for (int i = 0; i < BUFFER_SIZE && frequencies[i].count > 0; i++) {
    codebook[frequencies[i].symbol][0] = (char) i; // The first byte of the code is the rank of the character
    codebook[frequencies[i].symbol][1] = frequencies[i].symbol; // The second byte of the code is the character itself
  }
  
  // Step 4: Write the codebook to the output
  fwrite(frequencies, sizeof(CharCount), BUFFER_SIZE, output);
  
  // Step 5: Write the compressed data to the output
  rewind(input);
  while ((charsRead = fread(buffer, sizeof(char), BUFFER_SIZE, input)) > 0) {
    for (int i = 0; i < charsRead; i++) {
      char c = buffer[i];
      fwrite(codebook[c], sizeof(char), BUFFER_SIZE, output);
    }
  }
}

void decompress(FILE* input, FILE* output) {
  // Step 1: Read the codebook from the input
  CharCount frequencies[BUFFER_SIZE];
  fread(frequencies, sizeof(CharCount), BUFFER_SIZE, input);
  
  // Step 2: Sort the frequencies in descending order
  qsort(frequencies, BUFFER_SIZE, sizeof(CharCount), compare_char_count);
  
  // Step 3: Generate the codebook
  char codebook[BUFFER_SIZE][BUFFER_SIZE] = {0};
  for (int i = 0; i < BUFFER_SIZE && frequencies[i].count > 0; i++) {
    fread(codebook[frequencies[i].symbol], sizeof(char), BUFFER_SIZE, input);
  }
  
  // Step 4: Write the decompressed data to the output
  char buffer[BUFFER_SIZE] = {0};
  int bufferIndex = 0;
  char c;
  while (fread(&c, sizeof(char), 1, input) > 0) {
    buffer[bufferIndex] = c;
    bufferIndex++;
    for (int i = 0; i < BUFFER_SIZE && codebook[c][i] > 0; i++) {
      if (bufferIndex - i - 1 >= 0) {
        fwrite(&buffer[bufferIndex - i - 1], sizeof(char), 1, output);
      }
    }
  }
}

int main(int argc, char** argv) {
  if (argc < 4) {
    printf("Usage: %s <input file> <output file> <c/d (compress/decompress)>\n", argv[0]);
    return 1;
  }

  FILE* inputFile = fopen(argv[1], "rb");
  if (inputFile == NULL) {
    printf("Error: Could not open input file.\n");
    return 1;
  }

  FILE* outputFile = fopen(argv[2], "wb");
  if (outputFile == NULL) {
    fclose(inputFile);
    printf("Error: Could not open output file.\n");
    return 1;
  }

  if (strcmp(argv[3], "c") == 0) {
    compress(inputFile, outputFile);
  } else if (strcmp(argv[3], "d") == 0) {
    decompress(inputFile, outputFile);
  } else {
    printf("Error: Invalid command.\n");
  }

  fclose(inputFile);
  fclose(outputFile);
  return 0;
}