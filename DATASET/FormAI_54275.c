//FormAI DATASET v1.0 Category: Arithmetic ; Style: Cryptic
#include <stdio.h>

int main()
{
    int x, y, z;
    char a[50], b[50], c[50];

    printf("Enter the first integer: ");
    scanf("%d", &x);
    printf("Enter the second integer: ");
    scanf("%d", &y);

    printf("\nEnter the first character: ");
    scanf("%s", a);

    printf("\nEnter the second character: ");
    scanf("%s", b);

    z = x - y;

    if(z < 0)
    {
        printf("\nThe difference between %d and %d is negative", x, y);
        printf("\nAbsolute difference: %d\n", z * -1);
    }
    else
    {
        printf("\nThe difference between %d and %d is: %d\n", x, y, z);
    }

    printf("\nThe ASCII value of %c: %d\n", a[0], (int) a[0]);

    printf("\nThe ASCII value of %c: %d\n", b[0], (int) b[0]);

    sprintf(c, "%d", z); 

    printf("\nThe difference between %d and %d in string format: %s\n", x, y, c);

    return 0;
}