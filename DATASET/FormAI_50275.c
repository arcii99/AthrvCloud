//FormAI DATASET v1.0 Category: Compression algorithms ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Welcome to my unique C Compression algorithm! */

int main()
{
    printf("I can't believe it! I just created a brand new compression algorithm in C! This is amazing!\n");

    char originalString[1000];
    char compressedString[1000];

    printf("Please enter the string to be compressed: ");
    fgets(originalString, 1000, stdin);

    int i, j, k, count;
    for (i = 0, k = 0; originalString[i] != '\0'; i = j, k++) {
        count = 1;
        compressedString[k] = originalString[i];

        for (j = i + 1; originalString[j] == originalString[i]; j++) {
            count++;
        }

        if (count > 1) {
            char countString[5];
            sprintf(countString, "%d", count);
            strcat(compressedString, countString);
            k += strlen(countString) - 1;
        }
    }

    printf("The compressed string is: %s\n", compressedString);

    return 0;
}