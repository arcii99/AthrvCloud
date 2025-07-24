//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: cheerful
#include<stdio.h>

int main(){
   int n, i, j;
   printf("Welcome to the Greedy Algorithm Lab!\n\n");
   printf("Enter the number of elements in your array:\n");
   scanf("%d", &n);
   int arr[n];
   printf("\nEnter the elements of the array:\n");
   for(i=0; i<n; i++){
      scanf("%d", &arr[i]);
   }
   printf("\nThis is your original array:\n");
   for(i=0; i<n; i++){
      printf("%d ", arr[i]);
   }
   printf("\n\nWe will now sort your array in ascending order using the Greedy Algorithm:\n");
   int temp;
   for(i=0; i<n-1; i++){
      for(j=i+1; j<n; j++){
         if(arr[i]>arr[j]){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
         }
      }
   }
   printf("\nThis is your array after being sorted in ascending order:\n");
   for(i=0; i<n; i++){
      printf("%d ", arr[i]);
   }
   printf("\n\nThank you for using the Greedy Algorithm Lab! Hope to see you again!\n");
   return 0;
}