//FormAI DATASET v1.0 Category: Searching algorithm ; Style: cheerful
#include<stdio.h>

int main(){

   int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   int n, i, flag = 0;
   
   printf("Enter the number you want to search: ");
   scanf("%d", &n);

   for(i = 0; i < 10; i++){
      if(arr[i] == n){
         flag = 1;
         break;
      }
   }

   if(flag == 1)
      printf("\nYay, Your number is found at position %d.\n", i+1);
   else
      printf("\nSorry, Your number is not found in the list.\n");

   return 0;
}