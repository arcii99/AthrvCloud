//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10
#define PIXEL_SIZE 5
#define PIXEL_SYMBOL "X"

void draw_pixel(){
  int i, j;
  for(i = 0; i < PIXEL_SIZE; i++){
    for(j = 0; j < PIXEL_SIZE; j++){
        printf("%s", PIXEL_SYMBOL);
    }
    printf("\n");
  }
}

int main(){
   int pixel, x, y;
   for(y = 0; y < HEIGHT; y++){
     for(x = 0; x < WIDTH; x++){
       draw_pixel();
     }
     printf("\n");
   }
   return 0;
}