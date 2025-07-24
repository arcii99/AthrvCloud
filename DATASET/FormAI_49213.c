//FormAI DATASET v1.0 Category: Recursive ; Style: Cryptic
#include <stdio.h>

int mystery(const int* values, const int start, const int end) {
    if (end - start == 2) {
        return values[start] * values[start + 1];
    }
    
    int middle = (start + end) / 2;
    int left = mystery(values, start, middle);
    int right = mystery(values, middle, end);
    
    return left + right;
}

int main() {
    const int values[] = {1, 2, 3, 4, 5};
    const int length = sizeof(values) / sizeof(int);
    const int result = mystery(values, 0, length);
    
    printf("Result: %d\n", result);
    return 0;
}