//FormAI DATASET v1.0 Category: Error handling ; Style: active
#include <stdio.h>
#include <stdlib.h>

int divide(int a, int b) {
    if(b==0) {
        fprintf(stderr, "Error: Division by zero\n");
        return -1;
    }
    return a/b;
}

int main() {
    int x = 10, y = 0;
    int result;
    result = divide(x, y);
    if(result == -1) {
        exit(EXIT_FAILURE);
    }
    printf("%d divided by %d is %d\n", x, y, result);
    return 0;
}