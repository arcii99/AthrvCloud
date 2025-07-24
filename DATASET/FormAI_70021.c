//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: scientific
// C Checksum Calculator Example Program
// By: [Your Name]
// Date: [Current Date]

#include <stdio.h>
#include <stdlib.h>

// Function to calculate checksum
int calcChecksum(char* inputString) {
    int sum = 0;
    int i;

    for(i = 0; inputString[i] != '\0'; i++) {
        sum += (int)inputString[i];
    }

    return sum % 256;
}

int main() {
    char inputString[100];

    printf("Enter a string to calculate the checksum of: ");
    scanf("%s", inputString);

    int checksum = calcChecksum(inputString);

    printf("The checksum of input string %s is %d\n", inputString, checksum);

    return 0;
}