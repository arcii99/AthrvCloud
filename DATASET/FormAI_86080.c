//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: immersive
#include <stdio.h>

void bucket_sort(int arr[], int n)
{
    int i, j; 
    int count[n]; 
    for(i = 0; i < n; i++)
    {
        count[i] = 0;
    }
    for(i = 0; i < n; i++)
    {
        (count[arr[i]])++;
    }
    for(i = 0, j = 0; i < n; i++)
    {
        for(; count[i] > 0; (count[i])--)
        {
            arr[j++] = i;
        }
    } 
}
 
int main()
{
    int arr[] = {12, 5, 9, 10, 8, 15, 10, 7, 5, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    bucket_sort(arr, n);
    int i;
    for (i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}