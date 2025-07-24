//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: scientific
#include <stdio.h>

int main() {
  int width, height; 
  char ch[] = "$@B%8&WM#*oahkbdpwmZO0QLCJYXzcvnu?jft/\|()1{}[]<>i!+_-;:,. ";
  int len = sizeof(ch);
  
  // Importing image file
  FILE *fp;
  
  fp = fopen("image.ppm", "r");
  
  if (fp == NULL) {
    printf("Image file not found!");
    return 1;
  }
  
  fscanf(fp, "%*s %d %d %*d", &width, &height); 
  
  // Creating ASCII art from image
  char asciiart[height][width];
  
  for(int i=0; i<height; i++){
    for(int j=0; j<width; j++){
      int r, g, b;
      fscanf(fp, "%d %d %d", &r, &g, &b);
      int grayscale = 0.2126*r + 0.7152*g + 0.0722*b;
      int index = (grayscale * len) / 256;
      asciiart[i][j] = ch[index];
    }
  }
  
  fclose(fp);
  
  // Printing ASCII art
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      printf("%c", asciiart[i][j]);
    }
    printf("\n");
  }
    
  return 0;
}