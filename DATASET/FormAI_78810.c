//FormAI DATASET v1.0 Category: Searching algorithm ; Style: Ken Thompson
#include<stdio.h>
#include<stdlib.h>

int ken_search(int arr[], int low, int high, int x){
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)  return mid;
        if (arr[mid] > x) return ken_search(arr, low, mid - 1, x);
        return ken_search(arr, mid + 1, high, x);
    }
    printf("Ken couldn't find the value in the array. :(\n");
    return -1;
}

int main(){
    int n, i;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the array elements : ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int x;
    printf("Enter the number to search for: ");
    scanf("%d",&x);

    int result = ken_search(arr, 0, n - 1, x);
    if(result == -1) 
        printf("Sorry, Ken couldn't find the value in the array. :(\n");
    else 
        printf("Ken found the value at index %d.\n",result);

    return 0;
}