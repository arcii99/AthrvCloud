//FormAI DATASET v1.0 Category: Searching algorithm ; Style: recursive
#include<stdio.h>

int recursiveSearch(int arr[], int l, int h, int x){
    if (h < l)
       return -1;
    if (arr[l] == x)
       return l;
    if (arr[h] == x)
       return h;
    return recursiveSearch(arr, l+1, h-1, x);
}

int main(){
    int n, x, i;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    
    int arr[n];
    printf("Enter the elements of array: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    printf("Enter the element to be searched: ");
    scanf("%d",&x);
 
    int index = recursiveSearch(arr, 0, n-1, x);
 
    if (index != -1)
       printf("Element %d is present at index %d", x, index);
    else
        printf("Element %d is not present in the array", x);
    return 0;
}