//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: protected
#include <stdio.h>

#define MAX_SIZE 100

// Function to calculate checksum
unsigned char checksum(unsigned char *data, int size) {
    unsigned char result = 0;
    for (int i = 0; i < size; i++) {
        result += data[i];
    }
    return result;
}

// Main Function
int main() {
    unsigned char data[MAX_SIZE];
    int size;
    printf("Enter data size (less than 100): ");
    scanf("%d", &size);

    // Read the data
    printf("Enter the data (maximum size 100): ");
    for (int i = 0; i < size; i++) {
        scanf(" %c", &data[i]);
    }

    // Calculate checksum
    unsigned char cs = checksum(data, size);

    // Display the result
    printf("Computed checksum is %u.\n", cs);

    return 0;
}