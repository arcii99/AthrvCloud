//FormAI DATASET v1.0 Category: Recursive ; Style: relaxed
#include <stdio.h>

int recursive_function(int num) {
    if (num == 0) {
        return 0;
    } else if (num == 1) {
        return 1;
    } else {
        return recursive_function(num-1) + recursive_function(num-2);
    }
}

int main() {
    int n, i;

    printf("Enter the number of terms to be displayed:\n");
    scanf("%d", &n);

    printf("The Fibonacci series is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", recursive_function(i));
    }

    return 0;
}