//FormAI DATASET v1.0 Category: Recursive ; Style: realistic
#include <stdio.h>

int recursive(int num); // function prototype

int main() {
    int num, result;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num);
    result = recursive(num);
    printf("\nFactorial of %d is: %d\n", num, result);
    return 0;
}

int recursive(int num) {
    // base case
    if (num == 0) {
        return 1;
    }
    // recursive case
    else {
        return num * recursive(num - 1);
    }
}