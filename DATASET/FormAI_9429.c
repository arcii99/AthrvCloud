//FormAI DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void error(const char *msg, int code)
{
    fprintf(stderr, "Error: %s\n", msg);
    exit(code);
}

int divide(int num, int den)
{
    if (den == 0)
    {
        error("Division by zero", EPERM);
    }
    return num / den;
}

int main()
{
    int num, den, result;
    printf("Enter numerator: ");
    scanf("%d", &num);
    printf("Enter denominator: ");
    scanf("%d", &den);
    result = divide(num, den);
    printf("Result: %d\n", result);
    return 0;
}