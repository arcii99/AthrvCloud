//FormAI DATASET v1.0 Category: Recursive ; Style: realistic
#include <stdio.h>

int recursiveFunction(int num);

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("The factorial of %d is %d.", num, recursiveFunction(num));
    return 0;
}

int recursiveFunction(int num) {
    if(num == 0 || num == 1) {
        return 1;
    } else {
        return num * recursiveFunction(num-1);
    }
}