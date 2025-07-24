//FormAI DATASET v1.0 Category: Sorting ; Style: automated
#include<stdio.h>
#include<stdlib.h>

int main()
{
  int n,i,j,temp;
  printf("Enter the size of array: ");
  scanf("%d",&n);
  int arr[n];

  //Input the array elements
  printf("Enter %d elements:\n",n);
  for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

  //Sorting the array using bubble sort
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(arr[j]>arr[j+1])
      {
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }
  }

  //Displaying the sorted array
  printf("\nSorted array is: ");
  for(i=0;i<n;i++)
    printf("%d ",arr[i]);
  printf("\n");

  return 0;
}