//FormAI DATASET v1.0 Category: Searching algorithm ; Style: ephemeral
#include <stdio.h>
#define MAX_ARRAY_SIZE 1000

/* Function to search for an integer in an array */
int search(int arr[], int len, int num)
{
   int start = 0, end = len-1, mid;
   while(start <= end)
   {
      mid = (start + end)/2;
      if(arr[mid] == num)
         return mid;
      else if(arr[mid] > num)
         end = mid-1;
      else
         start = mid+1;
   }
   return -1;
}

int main()
{
   int num, arr[MAX_ARRAY_SIZE], len, idx;
   
   printf("Enter the number of elements in array (max %d): ", MAX_ARRAY_SIZE);
   scanf("%d", &len);
   
   if(len > MAX_ARRAY_SIZE)
   {
      printf("Array size is too large\n");
      return 0;
   }
   
   printf("Enter the elements in increasing order:\n");
   for(int i = 0; i < len; i++)
      scanf("%d", &arr[i]);
      
   printf("Enter the number to be searched: ");
   scanf("%d", &num);
   
   idx = search(arr, len, num);
   
   if(idx == -1)
      printf("%d not found in the array\n", num);
   else
      printf("%d found at position %d\n", num, idx+1);
   
   return 0;
}