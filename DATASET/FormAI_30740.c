//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: grateful
#include <stdio.h>

int main() {
  // dimensions of the image (in pixels)
  int width = 50;
  int height = 30;
  
  // input image value array
  int image[height][width];

  // code to read image from file into image array
  
  // iterate through each pixel in the image and convert to ASCII character equivalent
  for(int i=0; i<height; i++) {
    for(int j=0; j<width; j++) {
      int pixel = image[i][j]; // get pixel value
      
      // convert pixel value to ASCII character equivalent
      char ascii_char;
      if(pixel < 50) {
        ascii_char = ' '; // darkest pixel, use space character
      } else if(pixel < 100) {
        ascii_char = '.'; // slightly lighter pixel, use period character
      } else if(pixel < 150) {
        ascii_char = '|'; // even lighter pixel, use vertical bar character         
      } else if(pixel < 200) {
        ascii_char = '-'; // lighter pixel, use horizontal bar character
       } else {
        ascii_char = '='; // lightest pixel, use equal sign character 
      }
      
      // print ASCII character to console
      printf("%c", ascii_char);
      
    }
    printf("\n"); // move to next line after each row
  }
  
  return 0;
}