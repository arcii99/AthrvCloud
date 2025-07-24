//FormAI DATASET v1.0 Category: Recursive ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int recursive_fibonacci(int number) {
    if(number == 0) {
        return 0;
    }
    else if(number == 1) {
        return 1;
    }
    else {
        return recursive_fibonacci(number-1) + recursive_fibonacci(number-2);
    }
}

int main() {
    int num, result;

    printf("Enter a number: ");
    scanf("%d", &num);

    result = recursive_fibonacci(num);

    printf("The fibonacci number of %d is %d\n", num, result);

    return 0;
}