//FormAI DATASET v1.0 Category: Recursive ; Style: portable
#include <stdio.h>

int factorial(int n) {
    if (n==1 || n==0) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int fibonacci(int n) {
    if (n==0 || n==1) {
        return n;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

void hanoiTower(int n, char start, char mid, char end) {
    if (n==1) {
        printf("Move disk 1 from rod %c to rod %c\n", start, end);
    }
    else {
        hanoiTower(n-1, start, end, mid);
        printf("Move disk %d from rod %c to rod %c\n", n, start, end);
        hanoiTower(n-1, mid, start, end);
    }
}

int sumArray(int arr[], int size) {
    if (size==0) {
        return 0;
    }
    else {
        return arr[size-1] + sumArray(arr, size-1);
    }
}

int main() {
    int n = 5;
    printf("Factorial of %d = %d\n", n, factorial(n));
    
    int m = 6;
    printf("Fibonacci sequence of %d = ", m);
    for (int i=0; i<m; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    
    int numDisks = 3;
    hanoiTower(numDisks, 'A', 'B', 'C');
    
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Sum of array = %d\n", sumArray(arr, size));
    
    return 0;
}