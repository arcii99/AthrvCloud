//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000000

int paranoid_check(int* arr, int n) {
    int m = n / 2;
    int i = 0;
    int j = n - 1;
    while (i < m && j >= m) {
        if (arr[i] != arr[j]) {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main() {
    int arr[MAX_SIZE];
    int n, i;
    scanf("%d", &n);
    if (n < 0 || n > MAX_SIZE) {
        printf("Invalid input. Please enter a value between 0 and %d", MAX_SIZE);
        return 0;
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (paranoid_check(arr, n)) {
        printf("The array is a palindrome.\n");
    }
    else {
        printf("The array is not a palindrome.\n");
    }
    return 0;
}