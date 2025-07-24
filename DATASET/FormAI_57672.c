//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#define MAX 256

void main() {
    int num[MAX], i, j, k;
    char string[MAX];
    unsigned short int checksum = 0;

    printf("Enter the string: ");
    scanf("%s", string);

    for(i = 0; string[i] != '\0'; i++) {
        num[i] = (int) string[i];
    }

    j = i;

    for(k = 0; k < j; k++) {
        checksum += num[k];
    }

    printf("\nChecksum: %hu", checksum);
}