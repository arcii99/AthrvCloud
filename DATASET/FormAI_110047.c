//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], checksum[10];
    int i, sum = 0, n, ascii;

    printf("Enter a string: ");
    gets(str);

    n = strlen(str);

    for(i=0; i<n; i++)
    {
        ascii = (int) str[i];
        sum += ascii;
    }

    sprintf(checksum, "%x", sum);

    printf("Checksum is: %s\n", checksum);

    return 0;
}