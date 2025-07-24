//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

void drawPixel(int colorCode);

int main(){
   srand(time(NULL));
   int canvas[HEIGHT][WIDTH];
   for(int i = 0; i < HEIGHT; i++){
      for(int j = 0; j < WIDTH; j++){
         canvas[i][j] = rand() % 256;
         drawPixel(canvas[i][j]);
      }
      printf("\n");
   }
   return 0;
}

void drawPixel(int colorCode){
   if(colorCode < 85){
      printf("*");
   }
   else if(colorCode < 170){
      printf("X");
   }
   else{
      printf("#");
   }
}