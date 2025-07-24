//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: detailed
#include<stdio.h>

int main()
{
    char input[1000];
    int checksum = 0;

    printf("Enter the input message: ");
    fgets(input, 1000, stdin); //Input

    for(int i = 0; input[i] != '\0'; i++)
    {
        checksum += input[i]; //Adding up the ASCI values
    }

    checksum %= 256; //Modulus 256 to get the final checksum value

    printf("The checksum value is: %d\n", checksum);

    return 0;
}