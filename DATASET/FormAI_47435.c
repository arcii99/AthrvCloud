//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: energetic
#include <stdio.h>

int main() {
  printf("Welcome to the energized C Checksum Calculator\n\n");
  printf("Enter data in hexadecimal format:\n");
  
  char input[100];  // assuming input maximum 100 chars
  scanf("%s", input);
  
  int index = 0; 
  unsigned int checksum = 0;

  while(input[index] != '\0') {
    checksum += input[index];
    index++;
  }

  printf("\nChecksum value is: %X", checksum);

  return 0;
}