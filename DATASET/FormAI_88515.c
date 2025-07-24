//FormAI DATASET v1.0 Category: Pattern printing ; Style: systematic
#include <stdio.h>

int main() {
   int rows,cols;
   
   printf("Enter the number of rows and columns (odd number of rows): ");
   scanf("%d %d", &rows, &cols);
   
   int mid_row = rows/2;
   
   printf("\n");
   for(int i=0; i<rows;i++){
       
       if(i==mid_row){
           for(int j=0; j<cols; j++){
               printf("*");
           }
       }else{
           for(int j=0; j<cols;j++){
               if(j==0 || j==cols-1){
                   printf("*");
               }else if(i<mid_row && j==i+1){
                   printf("*");
               }else if(i>mid_row && j==cols-(i-mid_row)){
                   printf("*");
               }else{
                   printf(" ");
               }
           }
       }
       printf("\n");
   }

   return 0;
}