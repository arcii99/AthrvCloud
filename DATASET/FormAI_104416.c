//FormAI DATASET v1.0 Category: Data mining ; Style: funny
#include <stdio.h>

int main() {
   int goldMine[4][4] = {{5,7,1,3}, 
                         {1,6,8,1},
                         {3,4,4,2},
                         {2,2,7,8}};
   printf("Welcome miners! Let's find some gold!\n");
   int highestValue = 0;
   int rowIndex = 0;
   int columnIndex = 0;
   for(int i = 0; i < 4; i++){
       for(int j = 0; j < 4; j++){
           if(goldMine[i][j] > highestValue){
               highestValue = goldMine[i][j];
               rowIndex = i;
               columnIndex = j;
            }
       }
   }
   printf("We struck gold! We found %d gold nuggets at row %d, column %d!\n", highestValue, rowIndex+1, columnIndex+1);
   return 0;
}