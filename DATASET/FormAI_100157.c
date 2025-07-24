//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: inquisitive
#include <stdio.h>
#include <string.h>

int main()
{
    char str[50];
    int sum = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++)
    {
        sum += str[i];
    }

    printf("Checksum value of '%s' is %d\n", str, sum);

    return 0;
}