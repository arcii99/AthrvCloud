//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  //Generate seed for random pixel art
  srand(time(NULL));
  
  //Create array for pixel art, size of image is 10 x 10 pixels
  char pixels[10][10];
  
  //Generate random pixels using ASCII characters 
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      int random_num = rand() % 3;
      if(random_num == 0){
        pixels[i][j] = '+';
      }else if(random_num == 1){
        pixels[i][j] = '-';
      }else{
        pixels[i][j] = '|';
      }
    }
  }
  
  //Print generated pixel art in ASCII format
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      printf("%c ", pixels[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}