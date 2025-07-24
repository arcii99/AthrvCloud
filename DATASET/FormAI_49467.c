//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: romantic
#include <stdio.h>

int main()
{
    int num1, num2, i, j, flag;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    printf("Prime numbers between %d and %d are: ", num1, num2);
    for (i = num1; i <= num2; i++)
    {
        if (i == 1 || i == 0)
            continue;
        flag = 1;
        for (j = 2; j <= i / 2; ++j)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
            printf("%d ", i);
    }
    return 0;
}