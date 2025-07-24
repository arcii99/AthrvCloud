//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: invasive
#include <stdio.h>

int main() {
  FILE *fp;
  char fileName[100], ch;
  
  printf("Enter the image file name: ");
  scanf("%s", fileName);
  
  fp = fopen(fileName, "r");
  
  if(fp == NULL) {
    printf("Error opening file!\n");
    return 0;
  }
  
  printf("\nASCII art representation of the image:\n\n");
  
  while((ch = fgetc(fp)) != EOF) {
    for(int i=0; i<8; i++) {   // loop for each pixel in a byte
      if((ch >> (7-i)) & 1) {  // if the bit is 1, print a block
        printf("█");
      } else {                 // if the bit is 0, print a space
        printf(" ");
      }
    }
    if(ftell(fp) % 64 == 0) {  // add a line break every 8 bytes (64 pixels)
      printf("\n");
    }
  }
  
  fclose(fp);
  
  return 0;
}