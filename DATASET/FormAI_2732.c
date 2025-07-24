//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: futuristic
#include <stdio.h>

int main() {

    // Get input from user
    char input[100];
    printf("Enter the input string: ");
    scanf("%s", input);

    // Calculate checksum
    int checksum = 0;
    for(int i=0; i<strlen(input); i++) {
        checksum += input[i];
    }
    checksum %= 256;

    // Display input and checksum
    printf("Input string: %s\n", input);
    printf("Checksum: %X\n", checksum);

    return 0;
}