//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char data[] = {'S', 'o', 'm', 'e', ' ', 'D', 'a', 't', 'a'}; // Sample data to calculate checksum
    int checksum = 0; // Initialize checksum variable

    for(int i = 0; i < sizeof(data); i++)
    {
        int temp_sum = checksum + (int)data[i]; // Add ASCII value of data char to checksum
        if(temp_sum > 255) // Check if the value exceeds 255
        {
            checksum = (temp_sum % 256) + 1; // Wrap the value around and add the carry-over bit
        }
        else
        {
            checksum = temp_sum; // Otherwise, assign the new value to checksum
        }
    }

    printf("Checksum is: %d\n", checksum); // Print the final checksum value

    return 0;
}