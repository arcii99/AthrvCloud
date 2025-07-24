//FormAI DATASET v1.0 Category: Error handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf buffer;

void foo(int i) {
    if (i == 0) {
        printf("Error: division by zero\n");
        longjmp(buffer, 1);
    }
    printf("Result: %d\n", 10/i);
}

void bar() {
    int i;
    printf("Enter a non-zero integer: ");
    if (scanf("%d", &i) != 1)
    {
        printf("Error: invalid input\n");
        longjmp(buffer, 2);
    }
    foo(i);
}

int main() {
    int error_code;
    if ((error_code = setjmp(buffer)) != 0) {
        printf("An error occurred with error code %d\n", error_code);
        switch(error_code) {
            case 1:
                printf("Error: division by zero occurred\n");
                break;
            case 2:
                printf("Error: invalid input occurred\n");
                break;
            default:
                printf("Unknown error occurred\n");
                break;
        }
        exit(1);
    }
    bar();

    return 0;
}