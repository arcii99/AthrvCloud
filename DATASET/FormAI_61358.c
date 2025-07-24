//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: brave
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{ 
    srand(time(NULL)); 

    char nucleotides[] = { 'A', 'C', 'G', 'T' }; 

    int length; 
    printf("Enter the length of genome sequence: "); 
    scanf("%d", &length); 

    printf("Generating genome sequence...\n\n"); 

    // Generating random genome sequence 
    char sequence[length]; 
    for(int i=0; i<length; i++) 
    { 
        int index = rand() % 4; 
        sequence[i] = nucleotides[index]; 
    } 

    // Printing the generated genome sequence 
    printf("Genome Sequence: \n"); 
    for(int i=0; i<length; i++) 
    { 
        printf("%c", sequence[i]); 

        // Adding spaces after every 10 nucleotides for better readability 
        if((i+1) % 10 == 0) 
            printf(" "); 
    } 

    // Saving the generated genome sequence to a file 
    FILE *file = fopen("genome_sequence.txt", "w"); 
    if(file == NULL) 
    { 
        printf("Error opening file! Exiting..."); 
        return 1; 
    } 
    fprintf(file, "%s", sequence); 
    fclose(file); 

    printf("\n\nGenome sequence saved to genome_sequence.txt"); 
    return 0; 
}