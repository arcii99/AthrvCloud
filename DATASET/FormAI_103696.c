//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Recursive function to calculate checksum
int CalculateChecksum(int num)
{
    if(num == 0)
    {
        return 0;
    }
    else
    {
        return (num % 10) + CalculateChecksum(num / 10); // Recursive call
    }
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int checksum = CalculateChecksum(num); // Calling the recursive function

    printf("\nChecksum of %d is %d", num, checksum);
    return 0;
}