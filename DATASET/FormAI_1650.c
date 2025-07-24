//FormAI DATASET v1.0 Category: Searching algorithm ; Style: brave
#include <stdio.h> 

int brave_search(int arr[], int n, int x) 
{ 
    int i = 0; 
    while (i < n && arr[i] != x) 
        i++; 
  
    if (i == n) 
        return -1; 
    else
        return i; 
} 

int main(void) 
{ 
    int arr[] = { 4, 3, 6, 8, 1, 9, 2, 5, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 7; 
  
    int index = brave_search(arr, n, x); 
    if (index == -1) 
        printf("%d is not present in the array", x); 
    else
        printf("%d is present at index %d in the array", x, index); 
    return 0; 
}