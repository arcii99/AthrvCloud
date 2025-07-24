//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Function to calculate checksum for given data
int calculate_checksum(char data[], int size) {
    int sum = 0;

    for(int i=0; i<size; i++) {
        sum += data[i];
    }

    // Take one's complement of sum
    sum = ~sum;

    // Return checksum
    return sum;
}

int main() {
    // Input data string
    char input_string[50];

    printf("Enter data string (max 50 characters): ");
    scanf("%s", input_string);

    // Calculate checksum of given data
    int checksum = calculate_checksum(input_string, strlen(input_string));

    printf("Calculated Checksum: %d\n", checksum);

    return 0;
}