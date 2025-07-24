//FormAI DATASET v1.0 Category: Recursive ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

int recursive_function(int num);

int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);
    if (num >= 0) {
        printf("The factorial of %d is %d\n", num, recursive_function(num));
    } else {
        printf("Invalid input! Please enter a positive integer.\n");
        main(); // Recursive call
    }
    return 0;
}

int recursive_function(int num) {
    if (num <= 1) {
        return 1;
    } else {
        int result = num * recursive_function(num-1);
        printf("%d! = %d\n", num, result);
        return result;
    }
}