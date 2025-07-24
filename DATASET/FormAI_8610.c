//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: excited
#include <stdio.h>

int main() {

    printf("Welcome to the exciting C Checksum Calculator!\n");
    printf("Enter the number of data elements to be used for the calculation: ");
    int dataSize;
    scanf("%d", &dataSize);

    // Allocate memory for the data array
    unsigned char* data = (unsigned char*) malloc(dataSize * sizeof(unsigned char));

    if (data == NULL) {
        printf("Error: Memory could not be allocated for data array.");
        return 1;
    }

    // Prompt user to input the data elements
    printf("\nEnter the data elements (separate each element by space or newline):\n");
    for (int i = 0; i < dataSize; i++) {
        scanf("%hhu", &data[i]);
    }

    // Calculate the checksum
    unsigned int sum = 0;
    for (int i = 0; i < dataSize; i++) {
        sum += (unsigned int) data[i];
    }

    unsigned char checksum = (unsigned char) (sum % 256);

    printf("\nThe checksum is: %hhu\n", checksum);

    // Free the memory allocated for the data array
    free(data);

    printf("\nThank you for using the C Checksum Calculator! Have a great day!\n");

    return 0;
}