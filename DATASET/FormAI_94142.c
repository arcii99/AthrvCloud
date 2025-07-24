//FormAI DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h>
#include <errno.h>
#include <string.h>

int divide(int a, int b)
{
    if (b == 0)
    {
        errno = EDOM;
        return 0;
    }

    return a / b;
}

int main()
{
    int a = 10;
    int b = 0;
    int result;

    result = divide(a, b);

    if (errno == EDOM)
    {
        printf("Error: Division by zero - %s\n", strerror(errno));
        return -1;
    }

    printf("%d divided by %d is %d.\n", a, b, result);

    return 0;
}