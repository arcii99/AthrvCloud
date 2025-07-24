//FormAI DATASET v1.0 Category: Searching algorithm ; Style: rigorous
#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x)
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

int interpolationSearch(int arr[], int n, int x)
{
    int lo = 0, hi = (n - 1);
  
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        if (lo == hi) {
            if (arr[lo] == x) return lo;
            return -1;
        }
  
        int pos = lo + (((double)(hi - lo) /
                      (arr[hi] - arr[lo])) * (x - arr[lo]));
  
        if (arr[pos] == x)
            return pos;
  
        if (arr[pos] < x)
            lo = pos + 1;
  
        else
            hi = pos - 1;
    }
    return -1;
}

int interpolation_recursive(int *mas, int mid, int low, int high, int word_to_find)
{
    int low2 = low, high2 = high;
    mid = low2 + ((word_to_find - mas[low2]) * (high2 - low2))
                 / (mas[high2] - mas[low2]);

    if (mas[mid] == word_to_find)
        return mid;

    if (mas[mid] < word_to_find)
        return interpolation_recursive(mas, mid + 1, low, high, word_to_find);

    if (mas[mid] > word_to_find)
        return interpolation_recursive(mas, mid - 1, low, high, word_to_find);

    return -1;
}

int main()
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if(result != -1){
        printf("%d was found at index %d\n", x, result);
    }else{
        printf("%d was not found in the array\n", x);
    }

    int arr2[] = { 10, 12, 13, 16, 18, 19, 20, 21,
                  22, 23, 24, 33, 35, 42, 47 };
    n = sizeof(arr2) / sizeof(arr2[0]);
    x = 18;
    result = interpolationSearch(arr2, n, x);
    if(result != -1){
        printf("%d was found at index %d\n", x, result);
    }else{
        printf("%d was not found in the array\n", x);
    }

    int arr3[] = { 1, 2, 4, 5, 6, 7, 8, 9, 10 };
    n = sizeof(arr3) / sizeof(arr3[0]);
    x = 4;
    result = interpolation_recursive(arr3, 0, 0, n - 1, x);
    if(result != -1){
        printf("%d was found at index %d\n", x, result);
    }else{
        printf("%d was not found in the array\n", x);
    }
    
    return 0;
}