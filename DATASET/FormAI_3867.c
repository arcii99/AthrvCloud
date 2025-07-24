//FormAI DATASET v1.0 Category: Pattern printing ; Style: statistical
#include <stdio.h>

int main()
{
    int size;
    printf("Enter the size of the pattern:\n");
    scanf("%d", &size);
    
    // Frequency table for counting the occurrences of each character
    int freq[26] = {0};
    
    // Generate the pattern
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size-i-1; j++)
        {
            printf("  ");
        }
        
        for(int j = 0; j <= i; j++)
        {
            char c = 'A'+i;
            printf("%c ", c);
            
            freq[c-'A']++; // increment the count for this character
        }
        
        printf("\n");
    }
    
    printf("Character frequency statistics:\n");
    
    // Print the frequency table
    for(int i = 0; i < 26; i++)
    {
        char c = 'A'+i;
        printf("%c: %d\n", c, freq[i]);
    }
    
    return 0;
}