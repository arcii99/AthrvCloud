//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Ken Thompson
#include<stdio.h>

int main(){
   int n, i, j, temp;
   printf("Enter the number of elements: ");
   scanf("%d",&n);
   int arr[n];
   printf("Enter the array elements:\n");
   
   // Taking input array from user
   for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

  // Sorting the array in descending order using Bubble Sort
   for(i=0;i<n-1;i++){
      for(j=0;j<n-i-1;j++){
         if(arr[j]<arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
         }
      }
   }
   
   // Displaying the sorted array
   printf("The sorted array in descending order:\n");
   for(i=0;i<n;i++){
      printf("%d\t",arr[i]);
   }
   printf("\n");

   // Using Greedy Approach to calculate the minimum number of coins required
   int coins[4]={25, 10, 5, 1};
   int count=0, k=0;
   while(n!=0){
      if(n>=coins[k]){
         count=count+(n/coins[k]);
         n=n%coins[k];
      }
      k++;
   }
   printf("The minimum number of coins required = %d\n",count);
   return 0;
}