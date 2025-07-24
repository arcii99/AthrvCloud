//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: visionary
#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    int sum = 0;
    
    printf("Enter a string to calculate the checksum: ");
    fgets(input, 100, stdin); // read string from user input
    
    int length = strlen(input);
    
    for(int i=0;i<length-1;i++) // checksum calculation
    {
        sum += input[i];
    }
    
    printf("Checksum: %d", sum); // display the checksum
    
    return 0;
}