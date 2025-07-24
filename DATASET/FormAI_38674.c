//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    // Initializing variables
    char DNA[4] = {'A', 'T', 'G', 'C'};
    int length;
    
    // User input for sequence length
    printf("Enter the length of the DNA sequence: ");
    scanf("%d", &length);
    
    // Creating random sequence
    int i;
    srand(time(0)); // Seeding random number generator
    printf("Sequence: ");
    for(i=0;i<length;i++){
        printf("%c", DNA[rand()%4]);
    }
    printf("\n");
    
    // Terminate program
    return 0;
}