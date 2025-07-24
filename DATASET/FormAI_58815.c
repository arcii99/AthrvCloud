//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum = 0;
    int num, temp;

    printf("Enter the number: ");
    scanf("%d", &num);

    temp = num;

    while (temp != 0)
    {
        sum += temp % 10;
        temp /= 10;
    }

    printf("The checksum of %d is %d\n", num, sum);

    return 0;
}