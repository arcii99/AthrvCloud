//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Claude Shannon
#include <stdio.h>

int main()
{
    int input[10], i, checksum = 0;

    printf("Enter 10 integers:\n");

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &input[i]);
        checksum += input[i];
    }

    printf("Checksum value: %d\n", checksum);

    return 0;
}