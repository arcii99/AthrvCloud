//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: relaxed
#include <stdio.h>

int main() {
  char input[1000];
  int checksum = 0;
  
  printf("Enter a string: ");
  fgets(input, 1000, stdin); // get input string from user
  
  for (int i = 0; input[i] != '\0'; i++) { // iterate through each character in string
    checksum += input[i]; // add the ASCII value of the character to the checksum
  }
  
  printf("Checksum of the input string is: %d\n", checksum);
  
  return 0;
}