//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Linus Torvalds
/* 
  This program is an implementation of a unique compression algorithm developed by Linus Torvalds himself.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main()
{
  char input_string[MAX_SIZE];
  printf("Enter a string to compress: ");
  fgets(input_string, MAX_SIZE, stdin);

  // Allocate memory for the compressed string
  char *compressed_string = (char*) malloc(sizeof(char) * MAX_SIZE);
  strcpy(compressed_string, "");

  int len = strlen(input_string);
  int count = 1;
  for(int i = 0; i < len - 1; i++)
  {
    // Check if the current character is the same as the next one
    if(input_string[i] == input_string[i+1])
    {
      count++;
    }
    else
    {
      // Append the character and its count to the compressed string
      char count_char[10];
      sprintf(count_char, "%d", count);
      strncat(compressed_string, &input_string[i], 1);
      strcat(compressed_string, count_char);
      count = 1;
    }
  }

  // Print the original and compressed strings
  printf("\nOriginal string: %s", input_string);
  printf("Compressed string: %s\n", compressed_string);

  free(compressed_string);
  return 0;
}