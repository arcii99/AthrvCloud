//FormAI DATASET v1.0 Category: Recursive ; Style: creative
#include <stdio.h>

void count_to_10(int num) {
    if(num == 10) {
        printf("%d\n", num);
        return;
    }
    else {
        printf("%d\n", num);
        count_to_10(num+1);
    }
}

int fibonacci(int n) {
    if(n <= 1) {
        return n;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

void print_array(int arr[], int size) {
    if(size == 0) {
        return;
    }
    else {
        print_array(arr, size-1);
        printf("%d ", arr[size-1]);
    }
}

int main() {
    // Count to 10 recursively
    printf("Counting to 10...\n");
    count_to_10(1);

    // Fibonacci sequence
    printf("\nFibonacci sequence:\n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", fibonacci(i));
    }

    // Print array in reverse order
    int arr[] = {1, 2, 3, 4, 5};
    printf("\n\nArray in reverse order:\n");
    print_array(arr, 5);

    return 0;
}