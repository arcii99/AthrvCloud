//FormAI DATASET v1.0 Category: Recursive ; Style: genious
#include <stdio.h>

int geniusFunc(int n) {
    if (n == 0 || n == 1) { // base case
        return n;
    }
    else if (n % 2 == 0) {
        return geniusFunc(n/2);
    }
    else if (n % 3 == 0) {
        return geniusFunc(n/3);
    }
    else if (n % 5 == 0) {
        return geniusFunc(n/5);
    }
    else {
        return geniusFunc(n-1) + geniusFunc(n-2) + geniusFunc(n-3);
    }
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("The output of the geniusFunc with input %d is %d\n", num, geniusFunc(num));
    return 0;
}