//FormAI DATASET v1.0 Category: Error handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void print_error_message(int err_num) {
    switch(err_num) {
        case 1:
            printf("Error: Division by zero.\n");
            break;
        case 2:
            printf("Error: Invalid input value.\n");
            break;
        default:
            printf("Error: Unknown error has occurred.\n");
    }
}

int perform_division(int num, int denom) {
    if(denom == 0) {
        print_error_message(1);
        exit(1);
    }
    return num / denom;
}

int main() {
    int num, denom, result;

    printf("Enter the numerator: ");
    if(scanf("%d", &num) != 1) {
        print_error_message(2);
        exit(1);
    }

    printf("Enter the denominator: ");
    if(scanf("%d", &denom) != 1) {
        print_error_message(2);
        exit(1);
    }

    result = perform_division(num, denom);
    printf("%d / %d = %d\n", num, denom, result);

    return 0;
}