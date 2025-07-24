//FormAI DATASET v1.0 Category: Pattern printing ; Style: complex
#include <stdio.h>

int main()
{
    // Define size of pattern
    int size = 6;
    
    // Loop through each row
    for(int i = 1; i <= size; i++)
    {
        // Print spaces
        for(int j = 1; j <= size - i; j++)
        {
            printf(" ");
        }
        
        // Print pattern
        for(int j = 1; j <= 2*i - 1; j++)
        {
            printf("*");
        }
        
        // Newline
        printf("\n");
    }
    
    // Loop through each row
    for(int i = 1; i <= size - 1; i++)
    {
        // Print spaces
        for(int j = 1; j <= i; j++)
        {
            printf(" ");
        }
        
        // Print pattern
        for(int j = 1; j <= 2*(size - i) - 1; j++)
        {
            printf("*");
        }
        
        // Newline
        printf("\n");
    }
    
    return 0;
}