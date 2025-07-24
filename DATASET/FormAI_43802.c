//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: peaceful
#include<stdio.h>

// Function to print a pixel
void printPixel(){
  printf("#");
}

// Function to print a blank space
void printBlank(){
  printf(" ");
}

int main(){

  // Define grid size
  int w = 20;
  int h = 20;

  // Loop through each row of pixels
  for(int y=0; y<h; y++){

    // Loop through each column of pixels
    for(int x=0; x<w; x++){

      // Alternate between printing a pixel and a blank space
      if((x+y)%2 == 0){
        printPixel();
      }else{
        printBlank();
      }

    }

    // Start next row on a new line
    printf("\n");

  }

  return 0;

}