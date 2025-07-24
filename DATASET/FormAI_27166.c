//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to calculate the checksum
int calculateChecksum(char* str) {
    int sum = 0, i;
    for (i = 0; i < strlen(str); i++) {
        sum += str[i];
    }
    return sum % 256;
}

int main() {
    char str[100];
    printf("Enter the string to calculate the checksum: ");
    scanf("%s", str);
    int checksum = calculateChecksum(str);
    printf("The checksum of the string is: %d\n", checksum);
    return 0;
}