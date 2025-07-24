//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

int calculateChecksum(char* inputString) {
    int sum = 0;
    int i = 0;
    while (inputString[i] != '\0') {   // Loop through the string until the end
        sum += (int) inputString[i++]; // Add ASCII value of each character to the sum
    }
    return sum;
}

int main() {
    char inputString[100];     // String to take input
    printf("Enter a string: ");
    fgets(inputString, 100, stdin);   // fgets is used to take input along with spaces

    int checksum = calculateChecksum(inputString);  // Calculate the checksum
    printf("The checksum of the given string is: %d", checksum);

    return 0;
}