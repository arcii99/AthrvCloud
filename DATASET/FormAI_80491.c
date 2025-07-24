//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: invasive
#include <stdio.h>

// Function to calculate checksum
int calculate_checksum(const char* input_string, int len)
{
    int sum = 0;
    int i;

    // Traverse through the string
    for(i = 0; i < len; i++)
    {
        sum += (int)(input_string[i]);
        sum = sum % 255; // 255 because it is the upper limit of ASCII characters
    }

    return sum;
}

int main()
{
    char input_string[100];
    int len;
    int checksum;

    printf("Enter the input string: ");
    scanf("%s", input_string);

    len = strlen(input_string);

    if(len <= 0)
    {
        printf("Invalid input string!\n");
        return 1;
    }

    // Calculate checksum
    checksum = calculate_checksum(input_string, len);
    
    printf("\nChecksum: %d\n", checksum);

    return 0;
}