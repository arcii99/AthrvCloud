//FormAI DATASET v1.0 Category: Arithmetic ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *arr;
  int n;
  printf("Enter the size of the array: ");
  scanf("%d", &n);
  arr = (int *)malloc(n * sizeof(int));
  
  if(arr == NULL)
  {
    printf("Memory allocation failed!\n");
    return 0;
  }
  
  printf("Enter the elements of the array: ");
  for(int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  
  int max = arr[0];
  int min = arr[0];
  float avg = 0;
  
  printf("The array elements are: ");
  for(int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
    if(arr[i] > max)
      max = arr[i];
    if(arr[i] < min)
      min = arr[i];
    avg += arr[i];
  }
  
  avg /= n;
  
  printf("\nThe maximum element in the array is: %d\n", max);
  printf("The minimum element in the array is: %d\n", min);
  printf("The average of the elements in the array is: %f\n", avg);
  
  free(arr);
  return 0;
}