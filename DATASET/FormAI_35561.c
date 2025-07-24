//FormAI DATASET v1.0 Category: Pattern printing ; Style: puzzling
#include<stdio.h>
int main(){
   int n=10,i,j,k;
   for(i=1;i<=n;i++){
      for(j=n;j>=i;j--){
         printf("*");
      }
      for(k=2;k<=i*2;k++){
         printf(" ");
      }
      for(j=n;j>=i;j--){
         printf("*");
      }
      printf("\n");
   }
   for(i=n;i>=1;i--){
      for(j=n;j>=i;j--){
         printf("*");
      }
      for(k=2;k<=i*2;k++){
         printf(" ");
      }
      for(j=n;j>=i;j--){
         printf("*");
      }
      printf("\n");
   }
   return 0;
}