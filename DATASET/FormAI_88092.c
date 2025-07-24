//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char original[100], checksum[10] = {'0', 'x', '0', '0', '0', '0', '0', '0', '0', '0'};
    int len, sum = 0, i;

    printf("Welcome to the Checksum Calculator!\n");
    printf("Please enter the string to calculate the checksum: ");
    fgets(original, sizeof(original), stdin);

    len = strlen(original);

    for(i = 0; i < len; i++) {
        sum += original[i];
    }

    sprintf(checksum+2, "%X", sum);

    printf("The calculated checksum is: %s\n", checksum);
    return 0;
}