//FormAI DATASET v1.0 Category: Searching algorithm ; Style: real-life
#include<stdio.h>

int search(int arr[], int n, int x){
   int i;
   for (i = 0; i < n; i++){
      if (arr[i] == x)
        return i;
   }
   return -1;
}

int main(){
   int arr[] = {10, 55, 89, 21, 53, 77, 99, 31};
   int n = sizeof(arr)/sizeof(arr[0]);

   int x = 53;
   int result = search(arr, n, x);
   if(result == -1)
      printf("The number %d is not present in the array", x);
   else
      printf("The number %d is present at index %d", x, result);

   return 0;
}