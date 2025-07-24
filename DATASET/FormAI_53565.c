//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: innovative
#include <stdio.h>

// Function to calculate the checksum of the given string
int calculateChecksum(char* str) {
    int sum = 0;
    int i = 0;
    while (str[i] != '\0') {
        sum += (int) str[i];
        i++;
    }
    return sum;
}

int main() {
    char str[100];
    printf("Enter the string: ");
    scanf("%s", str);
    int checksum = calculateChecksum(str);
    printf("Checksum of the string is: %d\n", checksum);
    return 0;
}