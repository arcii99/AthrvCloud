//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// function to sort using bucket sort
void Bucket_Sort(int array[], int n)
{
    int i, j;
    int count[n];
    for (i = 0; i < n; i++)
        count[i] = 0;
  
    for (i = 0; i < n; i++)
        (count[array[i]])++;
  
    for (i = 0, j = 0; i < n; i++) 
        for(; count[i] > 0; (count[i])--)
            array[j++] = i;
}
  
// main function to test the implementation
int main()
{
    int array[] = {2, 4, 1, 6, 8, 5, 3, 7, 10, 9};
    int n = sizeof(array)/sizeof(array[0]);
    Bucket_Sort(array, n);
  
    printf("Sorted array is \n");
    for (int i=0; i<n; i++)
        printf("%d ", array[i]);
    return 0;
}