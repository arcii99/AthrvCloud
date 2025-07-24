//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[1024] = ""; // to store user input
    int checksum = 0; // to store the calculated checksum value
    int i = 0; // loop counter

    printf("Enter the data to calculate checksum: ");
    scanf("%s", input);

    // loop through each character in input and add its ASCII value to checksum
    for(i=0; i<strlen(input); i++)
    {
        checksum += input[i];
    }

    // convert checksum to 16-bit hexadecimal value
    int hex_value = checksum & 0xffff;

    printf("The checksum of %s is 0x%x.",input,hex_value);

    return 0;
}