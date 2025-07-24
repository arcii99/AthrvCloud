//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: futuristic
#include <stdio.h>

int main() {
    char input[100];
    int i, checksum = 0;

    printf("Welcome to Checksum Calculator 2.0!");
    printf("\nEnter your input (max 100 characters):\n");
    scanf("%s", input);

    for(i = 0; input[i] != '\0'; i++) {
        checksum = checksum + (i+1)*input[i];
    }

    printf("\nCalculated checksum: %d\n", checksum);

    return 0;
}