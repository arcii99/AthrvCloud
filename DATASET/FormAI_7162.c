//FormAI DATASET v1.0 Category: Compression algorithms ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Custom compression algorithm that replaces repeated characters with their count */

#define MAX_COMPRESS_LENGTH (256)

uint8_t* compress(const uint8_t* input, const uint32_t input_length,
                  uint32_t* output_length) {
  uint8_t* output = malloc(MAX_COMPRESS_LENGTH);
  *output_length = 0;
  uint32_t count = 0;
  uint32_t index = 0;

  for(uint32_t i = 0; i <= input_length; i++) {
    count++;
    if(input[i] != input[i+1] || count == 255) {
      output[index++] = count; // Count of the repeated characters
      output[index++] = input[i]; // Actual character
      count = 0;
    }
  }

  *output_length = index;
  return output;
}

int main() {
  // Test case - "Helloooo Worlddd"
  uint8_t input[] = {72, 101, 108, 108, 111, 111, 111, 111, 32, 87, 111, 114, 108, 100, 100, 100};
  uint32_t input_length = strlen((char*)input);
  uint32_t output_length = 0;

  uint8_t* compressed = compress(input, input_length, &output_length);
  for(uint32_t i = 0; i < output_length; i++) {
    printf("%x ", compressed[i]);
  }
  printf("\n");

  free(compressed);
  return 0;
}