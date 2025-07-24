//FormAI DATASET v1.0 Category: Computer Biology ; Style: grateful
/*
 * This program is a grateful example of a C computer biology program
 * that calculates the GC content of a DNA sequence.
 * 
 * Written by [Your Name]
 * 
 */

#include <stdio.h>
#include <string.h>

int main()
{
    // Declare variables
    char sequence[100];
    int i, length, gc_count = 0;
    float gc_content;
    
    printf("Welcome to the GC Content Calculator!\n");
    printf("Please enter a DNA sequence: ");
    scanf("%s", sequence);
    
    length = strlen(sequence);
    
    // Loop through the sequence to count the GC pairs
    for (i = 0; i < length; i++)
    {
        if (sequence[i] == 'G' || sequence[i] == 'C')
            gc_count++;
    }
    
    // Calculate the GC content as a percentage
    gc_content = (float) gc_count / length * 100.0;
    
    // Output the result
    printf("The GC content of your sequence is %.2f%%.\n", gc_content);
    
    printf("Thank you for using the GC Content Calculator!\n");
    
    return 0;
}