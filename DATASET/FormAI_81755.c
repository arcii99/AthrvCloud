//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 100

void cyberpunk_sort(int arr[], int n)
{
   int i, key, j;
   for(i = 1; i< n; i++){
       key = arr[i];
       j = i-1;

       while(j >= 0 && arr[j] > key){
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}

int main()
{
   int arr[MAX_SIZE],i,n;
   
   /* Taking input from user */
   printf("Enter the size of Array : ");
   scanf("%d",&n);
   
   /* Generating random elements of array */
   srand(time(0));
   for(i=0; i<n; i++) {
       arr[i] = rand() % 1000;
   }
   
   printf("\nBefore Cyberpunk Sorting: \n");
   for(i=10; i<20; i++) {
       printf("%d ", arr[i]);
   }
   
   cyberpunk_sort(arr, n);
   
   printf("\n\nAfter Cyberpunk Sorting: \n");
   for(i=10; i<20; i++) {
       printf("%d ", arr[i]);
   }
   
   return 0;
}