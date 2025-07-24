//FormAI DATASET v1.0 Category: Compression algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Synchronous Compression Algorithm
void synchronousCompression(char* text) {
  int text_length = strlen(text);
  int compression_length = 0;
  char compressed[1000];
  
  for (int i = 0; i < text_length; i++) {
    int count = 1;
    while (i < text_length - 1 && text[i] == text[i+1]) {
      count++;
      i++;
    }
    
    // Add compressed character and its count to the output
    compressed[compression_length++] = text[i];
    char count_str[10];
    sprintf(count_str, "%d", count);
    for (int j = 0; j < strlen(count_str); j++) {
      compressed[compression_length++] = count_str[j];
    }
  }
  
  // Add null terminator to the compressed string
  compressed[compression_length] = '\0';
  
  // Print the compressed text
  printf("Compressed text: %s\n", compressed);
}

int main() {
  char text[1000];
  
  // Get input text from user
  printf("Enter text to compress: ");
  fgets(text, 1000, stdin);
  strtok(text, "\n");
  
  // Compress the text
  synchronousCompression(text);
  
  return 0;
}