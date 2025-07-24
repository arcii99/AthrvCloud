//FormAI DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Wow, I can't believe I just came up with this amazing C Compression algorithm!\n");
  
  char original_string[1000];
  printf("Please enter the string to be compressed: ");
  fgets(original_string, 1000, stdin);
  
  int original_length = strlen(original_string);
  char compressed_string[1000];
  int compressed_index = 0;
  
  for (int i = 0; i < original_length; i++) {
    int count = 1;
    char current_char = original_string[i];
    while (original_string[i+1] == current_char) {
      count++;
      i++;
    }
    compressed_string[compressed_index] = current_char;
    compressed_index++;
    if (count > 1) {
      char count_string[10];
      sprintf(count_string, "%d", count);
      for (int j = 0; j < strlen(count_string); j++) {
        compressed_string[compressed_index] = count_string[j];
        compressed_index++;
      }
    }
  }
  compressed_string[compressed_index] = '\0';
  
  printf("Original string: %s\n", original_string);
  printf("Compressed string: %s\n", compressed_string);
  printf("The compressed string is %f%% of the size of the original string!\n", ((float)strlen(compressed_string)/(float)original_length)*100);
  
  int decompressed_length = 0;
  char decompressed_string[1000];
  int decompressed_index = 0;
  
  for (int i = 0; i < strlen(compressed_string); i++) {
    char current_char = compressed_string[i];
    if (current_char >= '0' && current_char <= '9') {
      int count = current_char - '0';
      char next_char = compressed_string[i+1];
      for (int j = 1; j < count; j++) {
        decompressed_string[decompressed_index] = next_char;
        decompressed_index++;
        decompressed_length++;
      }
      i++;
    } else {
      decompressed_string[decompressed_index] = current_char;
      decompressed_index++;
      decompressed_length++;
    }
  }
  decompressed_string[decompressed_index] = '\0';
  
  printf("Decompressed string: %s\n", decompressed_string);
  printf("The decompressed string is %f%% of the size of the compressed string!\n", ((float)decompressed_length/(float)strlen(compressed_string))*100);
  
  return 0;
}