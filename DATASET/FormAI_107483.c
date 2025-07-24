//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Initialize variables
    int number_of_values, value, checksum = 0;

    // Ask user for number of values
    printf("Enter the number of values: ");
    scanf("%d", &number_of_values);

    // Ask user for each value and add to checksum
    for (int i = 0; i < number_of_values; i++)
    {
        printf("Enter value %d: ", i+1);
        scanf("%d", &value);
        checksum += value;
    }

    // Output checksum
    printf("Checksum: %d", checksum);

    return 0;
}