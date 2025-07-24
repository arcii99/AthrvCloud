//FormAI DATASET v1.0 Category: Recursive ; Style: interoperable
#include<stdio.h>

int factor(int x);

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Factorial of %d is %d", num, factor(num));
    return 0;
}

int factor(int x) {
    if(x == 0) {
        return 1;
    }
    else {
        return x * factor(x - 1);
    }
}