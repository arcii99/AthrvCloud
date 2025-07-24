//FormAI DATASET v1.0 Category: Arithmetic ; Style: recursive
#include <stdio.h>

int sum(int n);

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    printf("Sum = %d", sum(num));
    return 0;
}

int sum(int n) {
    if(n != 0)
        return n + sum(n - 1); // recursive call
    else
        return n;
}