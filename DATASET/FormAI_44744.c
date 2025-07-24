//FormAI DATASET v1.0 Category: Text processing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a function to encode a given string using the famous Shannon's Entropy algorithm */
char *shannon_entropy_encode(char *input_string) {
  char *output_string = malloc(strlen(input_string) * sizeof(char));
  int char_counts[256] = {0};
  double entropy = 0.0;

  /* Count the number of occurrences of each character in the input string */
  for (int i = 0; i < strlen(input_string); i++) {
    char_counts[input_string[i]]++;
  }

  /* Calculate the entropy of the input string */
  for (int i = 0; i < 256; i++) {
    if (char_counts[i] != 0) {
      double p = (double) char_counts[i] / (double) strlen(input_string);
      entropy += -1.0 * p * log2(p);
    }
  }

  /* Encode the input string using Shannon's Entropy algorithm */
  for (int i = 0; i < strlen(input_string); i++) {
    if (i == 0) {
      output_string[i] = input_string[i];
      continue;
    }

    output_string[i] = input_string[i] ^ (input_string[i - 1] + (int) entropy) % 256;
  }

  return output_string;
}

/* Define a function to decode a given string encoded using Shannon's Entropy algorithm */
char *shannon_entropy_decode(char *input_string) {
  char *output_string = malloc(strlen(input_string) * sizeof(char));
  int char_counts[256] = {0};
  double entropy = 0.0;

  /* Count the number of occurrences of each character in the input string */
  for (int i = 0; i < strlen(input_string); i++) {
    char_counts[input_string[i]]++;
  }

  /* Calculate the entropy of the input string */
  for (int i = 0; i < 256; i++) {
    if (char_counts[i] != 0) {
      double p = (double) char_counts[i] / (double) strlen(input_string);
      entropy += -1.0 * p * log2(p);
    }
  }

  /* Decode the input string using Shannon's Entropy algorithm */
  for (int i = 0; i < strlen(input_string); i++) {
    if (i == 0) {
      output_string[i] = input_string[i];
      continue;
    }

    output_string[i] = input_string[i] ^ (output_string[i - 1] + (int) entropy) % 256;
  }

  return output_string;
}

int main() {
  char *input_string = "Hello, world!";
  char *encoded_string = shannon_entropy_encode(input_string);
  char *decoded_string = shannon_entropy_decode(encoded_string);

  printf("Input String: %s\n", input_string);
  printf("Encoded String: %s\n", encoded_string);
  printf("Decoded String: %s\n", decoded_string);

  free(encoded_string);
  free(decoded_string);

  return 0;
}