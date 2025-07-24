//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 25
#define COLS 25

void draw(int pixels[ROWS][COLS]){
   int i,j;
   for(i=0;i<ROWS;i++){
      for(j=0;j<COLS;j++){
         if(pixels[i][j]==1){
            printf("*");
         }
         else{
            printf(" ");
         }
      }
      printf("\n");
   }
}

int main(){
   int pixels[ROWS][COLS];
   int i,j;
   srand(time(NULL));
   for(i=0;i<ROWS;i++){
      for(j=0;j<COLS;j++){
         pixels[i][j]= rand() % 2;
      }
   }
   draw(pixels);
   return 0;
}