//FormAI DATASET v1.0 Category: Compression algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  char input[1000];
  printf("Enter the text to compress using our unique algorithm\n");
  scanf("%s", input);

  int length = strlen(input);
  int counter = 0;
  char output[1000] = "";
  
  for(int i = 0; i < length; i++) {
    char current = input[i];
    counter++;
    
    if(i == length - 1) {
      if(counter > 1) {
        char countChar = counter + '0';
        strcat(output, countChar);
      }
      strcat(output, &current);
      break;
    }
    
    if(current != input[i+1]) {
      if(counter > 1) {
        char countChar = counter + '0';
        strcat(output, countChar);
      }
      strcat(output, &current);
      counter = 0;
    }
  }
  
  printf("Compressed string: %s\n", output);
  return 0;
}