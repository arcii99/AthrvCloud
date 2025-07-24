//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: future-proof
#include <stdio.h>

/*
    This program calculates a checksum of a given input array using trailing zeroes method.
    It starts by taking the sum of all elements in the array, then adding leading zeroes 
    to the sum so that the total number of digits is a multiple of 10. Finally, it calculates 
    a checksum by taking the 10's complement of the sum.
*/

int main()
{
    int input[] = {1,2,3,4,5,6,7,8,9,10};
    int input_len = sizeof(input) / sizeof(input[0]);
    
    // Calculate the sum of all input elements
    int sum = 0;
    for(int i=0; i<input_len; i++)
    {
        sum += input[i];
    }
    
    // Add leading zeroes to the sum
    int trailing_zeroes = (10 - (input_len % 10)) % 10;
    for(int i=0; i<trailing_zeroes; i++)
    {
        sum += 0;
    }
    
    // Calculate the 10's complement
    int checksum = 10 - (sum % 10);
    
    // Output the results
    printf("Input array: ");
    for(int i=0; i<input_len; i++)
    {
        printf("%d ", input[i]);
    }
    printf("\n");
    
    printf("Sum: %d\n", sum);
    printf("Trailing zeroes: %d\n", trailing_zeroes);
    printf("Checksum: %d\n", checksum);
    
    return 0;
}