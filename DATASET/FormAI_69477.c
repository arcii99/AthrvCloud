//FormAI DATASET v1.0 Category: Recursive ; Style: rigorous
#include <stdio.h>

int recursive_function(int num) {
    if(num == 0) {
        return 0;
    } else {
        return num + recursive_function(num - 1);
    }
}

int main() {
    int number;
    printf("Enter a non-negative integer: ");
    scanf("%d", &number);
    printf("The sum of integers from 1 to %d is %d\n", number, recursive_function(number));
    return 0;
}