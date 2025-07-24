//FormAI DATASET v1.0 Category: Error handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, result;
    printf("Enter two numbers:");

    if(scanf("%d %d", &num1, &num2) == 2) {
        if(num2 != 0) {
            result = num1/num2;
            printf("%d divided by %d is %d\n", num1, num2, result);
        }
        else {
            fprintf(stderr, "Error: Cannot divide by zero\n");
            exit(EXIT_FAILURE);
        }
    }
    else {
        fprintf(stderr, "Error: Invalid input\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}