//FormAI DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>

/* Function to perform binary search in array */
int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
   }
   return -1;
}

/* Function to perform interpolation search in array */
int interpolationSearch(int arr[], int n, int x)
{
    int lo = 0, hi = (n - 1);
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        if (lo == hi)
        {
            if (arr[lo] == x) return lo;
            return -1;
        }
        int pos = lo + (((double)(hi-lo) /(arr[hi]-arr[lo]))*(x - arr[lo]));
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
}

/* Function to print array elements */
void printArray(int arr[], int n)
{
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* Main function */
int main()
{
    int arr[] = {2, 3, 4, 10, 40, 50, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int x = 60;
    printf("Array elements: ");
    printArray(arr, n); /* Print array elements */
    int result1 = binarySearch(arr, 0, n-1, x); /* Perform binary search in array */
    if(result1 == -1)
        printf("%d is not present in array\n", x);
    else
        printf("%d is present at index %d\n", x, result1);
    int result2 = interpolationSearch(arr, n, x); /* Perform interpolation search in array */
    if(result2 == -1)
        printf("%d is not present in array\n", x);
    else
        printf("%d is present at index %d\n", x, result2);
    return 0;
}