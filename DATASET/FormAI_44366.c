//FormAI DATASET v1.0 Category: Searching algorithm ; Style: active
#include <stdio.h>

int searchLinear(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int searchBinary(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
  
        if (arr[m] == x)
            return m;
  
        if (arr[m] < x)
            l = m + 1;

        else
            r = m - 1;
    }
    return -1;
}

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int x = 10;
    int result = searchLinear(arr, n, x);
  
    if(result == -1)
        printf("Element is not present in array\n");
    else
        printf("Element is present at index %d\n", result);

    int y = 40;
    int a = 0;
    int b = n-1;
    int result2 = searchBinary(arr, a, b, y);
  
    if(result2 == -1)
        printf("Element is not present in array\n");
    else
        printf("Element is present at index %d\n", result2);
  
    return 0;
}