//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int data[100], checksum = 0, len;

    printf("Enter the length of the data stream: ");
    scanf("%d", &len);

    printf("Enter the data stream:\n");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &data[i]);
        checksum += data[i];
    }

    printf("Checksum = %d\n", checksum);

    return 0;
}