//FormAI DATASET v1.0 Category: Searching algorithm ; Style: light-weight
#include <stdio.h>

int search(int arr[], int n, int x){
    int i;
    for (i = 0; i < n; i++){
        if (arr[i] == x){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int x;
    printf("Enter the element to search: ");
    scanf("%d", &x);
    int result = search(arr, n, x);
    if (result == -1){
        printf("%d not found in the array.\n", x);
    } else {
        printf("%d found at index %d.\n", x, result);
    }
    return 0;
}