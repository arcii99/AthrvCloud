//FormAI DATASET v1.0 Category: Math exercise ; Style: recursive
#include <stdio.h>

int gcd(int x, int y);

int main() {
    int num1, num2, answer;
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    answer = gcd(num1, num2);

    printf("The GCD of %d and %d is %d\n", num1, num2, answer);

    return 0;
}

int gcd(int x, int y) {
    if (x == 0) {
        return y;
    }

    if (y == 0) {
        return x;
    }

    if (x == y) {
        return x;
    }

    if (x > y) {
        return gcd(x-y, y);
    } 
    
    return gcd(x, y-x);
}