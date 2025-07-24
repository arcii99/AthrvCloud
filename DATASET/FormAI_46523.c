//FormAI DATASET v1.0 Category: Data recovery tool ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char original_data[100];
    char recovered_data[100];
    int i, j;

    printf("Enter the original data: ");
    scanf("%[^\n]", original_data);

    // Corrupt the original data
    for (i = 0; i < strlen(original_data); i++) {
        original_data[i] = original_data[i] + i;
    }
    printf("Corrupted data: %s\n", original_data);

    // Recover the original data
    for (i = 0; i < strlen(original_data); i++) {
        recovered_data[i] = original_data[i] - i;
    }
    recovered_data[i] = '\0';

    printf("Recovered data: %s\n", recovered_data);

    return 0;
}