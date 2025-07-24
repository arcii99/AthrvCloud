//FormAI DATASET v1.0 Category: Searching algorithm ; Style: futuristic
#include<stdio.h>

int futuristicSearch(int arr[], int n, int x) {
    int start = 0, end = n-1;
    while(start <= end && x >= arr[start] && x <= arr[end]) {
        int pos = start + (((double)(end - start) / (arr[end] - arr[start])) * (x - arr[start]));
        if(arr[pos] == x) {
            return pos;
        }
        if(arr[pos] < x) {
            start = pos + 1;
        } else {
            end = pos - 1;
        }
    }
    return -1;
}

int main() {
    int n, arr[100], x, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &x);
    int result = futuristicSearch(arr, n, x);
    if(result == -1) {
        printf("%d not found in the array\n", x);
    } else {
        printf("%d found at index %d\n", x, result);
    }
    return 0;
}