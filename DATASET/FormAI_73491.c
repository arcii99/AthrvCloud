//FormAI DATASET v1.0 Category: String manipulation ; Style: future-proof
#include <stdio.h>
#include <string.h>

int main() {
    char originalString[100];
    char copyString[100];

    printf("Please enter a string: ");
    fgets(originalString, 100, stdin);

    // Remove newline characters from original string
    originalString[strcspn(originalString, "\n")] = 0;

    printf("Original string: %s\n", originalString);

    // Copy every other character from original string to copy string
    int j = 0;
    for(int i = 0; i < strlen(originalString); i++) {
        if(i % 2 == 0) {
            copyString[j] = originalString[i];
            j++;
        }
    }
    copyString[j] = '\0';

    printf("Modified string: %s\n", copyString);

    return 0;
}