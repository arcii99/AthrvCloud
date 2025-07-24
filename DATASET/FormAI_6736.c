//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: romantic
#include <stdio.h>

int main() {
   int n, i, j, temp;
   int arr[20];
   
   printf("Enter the size of the array: ");
   scanf("%d",&n);
   
   printf("Enter the array elements: ");
   for(i=0;i<n;i++) {
      scanf("%d",&arr[i]);
   }
    
   // Greedy algorithm implementation
   for(i=0;i<n-1;i++) {
      for(j=i+1;j<n;j++) {
         if(arr[i]>arr[j]) {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }
   }
   
   printf("Sorted array: ");
   for(i=0;i<n;i++) {
      printf("%d ",arr[i]);
   }
    
   return 0;
}