//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: grateful
#include <stdio.h>

int main() {
    // Compute checksum of a given string
    char str[100], checksum;
    int i = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    // Computed checksum
    checksum = 0;

    while (str[i] != '\0') {
        checksum ^= str[i];
        i++;
    }

    printf("Checksum of the string is %d\n", checksum);

    return 0;
}