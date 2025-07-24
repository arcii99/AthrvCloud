//FormAI DATASET v1.0 Category: Error handling ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void handle_error(int err_num);

void divide_by_zero(int num1, int num2) {
    if (num2 == 0) {
        handle_error(1);
    } else {
        int result = num1 / num2;
        printf("%d / %d = %d\n", num1, num2, result);
    }
}

void handle_error(int err_num) {
    switch(err_num) {
        case 1:
            printf("Error: Attempted to divide by zero\n");
            printf("Please enter a non-zero value for num2: ");
            int num2;
            scanf("%d", &num2);
            divide_by_zero(10, num2);
            break;

        default:
            printf("Unknown error occurred\n");
            exit(1);
    }
}

int main() {
    int num1 = 10;
    int num2;
    printf("Please enter a value for num2: ");
    scanf("%d", &num2);

    divide_by_zero(num1, num2);

    return 0;
}