//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function to calculate checksum
int calcChecksum(char *str) {
    int sum = 0;
    int i;
    // Iterate through each character
    for(i=0; str[i]!='\0'; i++) {
        sum += str[i];
    }
    return sum % 256;
}

int main() {
    char str[100];
    // Prompt user for input
    printf("Enter a string:");
    scanf("%s", str);
    // Calculate checksum
    int checksum = calcChecksum(str);
    printf("Checksum: %d\n",checksum);
    return 0;
}