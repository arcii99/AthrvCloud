//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: artistic
#include <stdio.h>

int main()
{
    int n, i, j, temp, sum = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array:\n");

    for(i=0; i<n; i++)
      scanf("%d",&arr[i]);

    for(i=0; i<n-1; i++)
    {   
        for(j=i+1; j<n; j++)
        {      
          if(arr[i] > arr[j])
          {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
          }
        }
     }

    int k;
    printf("\nEnter the value of k: ");
    scanf("%d", &k);

    printf("\nSorted array:\n");

    for(i=0; i<n; i++)
      printf("%d ", arr[i]);

    printf("\n%d smallest elements are:\n", k);

    for(i=0; i<k; i++)  
    {
        printf("%d ", arr[i]);
        sum += arr[i];
    }

    printf("\nSum of %d smallest elements is: %d", k, sum);

    return 0;
}