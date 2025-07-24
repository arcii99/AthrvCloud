//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: invasive
#include <stdio.h>

// Function to calculate the checksum of a given character array
int checksum(char* arr) {
    int sum = 0;

    // Loop through the character array
    for (int i = 0; arr[i] != '\0'; i++) {
        sum += (int) arr[i];  // Add the ASCII value of each character
    }

    return sum % 256;  // Return the sum modulo 256
}

int main() {
    char str[100];

    // Get input from user
    printf("Enter a string: ");
    scanf("%s", str);

    // Calculate checksum of the input string
    int result = checksum(str);

    // Display the result
    printf("The checksum of the input string is %d.\n", result);

    return 0;
}