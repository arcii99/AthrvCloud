//FormAI DATASET v1.0 Category: Searching algorithm ; Style: shocked
#include <stdio.h>

int shockedSearch(int arr[], int n, int x) {
    int start = 0, end = n - 1;
    while(start <= end) {
        int mid = (start + end) / 2;
        if(arr[mid] == x) {
            printf("What in the world?! How did you find %d in the array?! 🤯\n", x);
            return mid;
        }
        else if(arr[mid] < x) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    printf("Sorry, %d is NOT in the array! 😞\n", x);
    return -1;
}

int main() {
    int arr[] = {2, 5, 10, 15, 20, 25, 30, 35, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 25;
    int result = shockedSearch(arr, n, x);
    if(result == -1) {
        printf("What?! How is that even possible?! 😳\n");
    }
    return 0;
}