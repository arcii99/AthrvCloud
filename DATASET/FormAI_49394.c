//FormAI DATASET v1.0 Category: Scientific ; Style: introspective
#include <stdio.h>

// Define the function that will be called recursively
int foo(int n) {
    printf("foo(%d) called\n", n);
    if (n <= 0) {
        return 0;
    }
    return n + foo(n-1);
}

int main() {
    // Call the foo function with n = 5
    int result = foo(5);
    printf("result: %d\n", result);
    return 0;
}