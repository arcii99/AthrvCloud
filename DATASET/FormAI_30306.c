//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the checksum of an array of characters.
int calculate_checksum(char array[], int size) {
    int checksum = 0;
    for (int i = 0; i < size; i++) {
        checksum += (int) array[i];
    }
    return checksum;
}

int main() {
    // Prompt the user to enter a string.
    printf("Enter a string to calculate its checksum: ");
    char string[100];
    scanf("%s", string);

    // Convert the string to an array of characters.
    int size = strlen(string);
    char array[size];
    strcpy(array, string);

    // Calculate the checksum of the array of characters.
    int checksum = calculate_checksum(array, size);

    // Output the checksum.
    printf("The checksum of the string '%s' is %d.", string, checksum);
    return 0;
}