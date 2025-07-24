//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char string[100];
    int checksum = 0;
    int i;

    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);

    // Remove newline character
    string[strcspn(string, "\n")] = 0;

    // Calculate checksum
    for (i = 0; i < strlen(string); i++) {
        checksum += (int) string[i];
    }

    printf("Checksum of '%s' is %d.\n", string, checksum);

    return 0;
}