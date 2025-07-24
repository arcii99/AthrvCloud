//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char message[100];
    int sum = 0;

    printf("Enter a message: ");
    scanf("%s", message);

    for (int i = 0; message[i] != '\0'; i++)
    {
        sum += message[i];
    }

    printf("Checksum: %d\n", sum % 255);

    return 0;
}