//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: excited
#include<stdio.h>
#include<stdlib.h> 
#include<time.h> 

int main() {
    srand(time(NULL)); // Initialize random number generator using time 
    char bases[] = {'A', 'T', 'G', 'C'}; //initialize array containing nucleotide bases
    int seq_length = 1000; //set the sequence length to be generated
    char sequence[seq_length]; //initialize empty array to hold the generated sequence
    
    //generate the sequence
    for(int i = 0; i < seq_length; i++) {
        int random_index = rand() % 4; //pick a random index from the array of nucleotide bases
        sequence[i] = bases[random_index]; //add the randomly chosen nucleotide base to the sequence
    }
    
    //print the sequence
    printf("The generated sequence is: \n");
    for(int j = 0; j < seq_length; j++) {
        printf("%c", sequence[j]);
    }
    
    return 0;
}