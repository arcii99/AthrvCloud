//FormAI DATASET v1.0 Category: Recursive ; Style: innovative
#include <stdio.h>

int recursiveFunction(int num) {
    if (num == 0) {
        return 0;
    } else {
        return num + recursiveFunction(num - 1);
    }
}

int main() {
    int number = 5;
    int result = recursiveFunction(number);
    printf("The sum of 1 to %d is %d", number, result);
    return 0;
}