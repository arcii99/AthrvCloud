//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100 // Define the length of the genome sequence
#define MUTATION_RATE 0.01 // Define the mutation rate, i.e., the probability of a nucleotide being mutated

// Define an array of nucleotides
char nucleotides[] = {'A', 'T', 'C', 'G'};

// Function to generate a random nucleotide
char randomNucleotide()
{
    int index = rand() % 4; // Generate a random index between 0 and 3
    return nucleotides[index]; // Return the nucleotide at the generated index
}

// Function to generate a random genome sequence
void generateGenome(char genome[])
{
    int i;
    for (i = 0; i < GENOME_LENGTH; i++)
    {
        genome[i] = randomNucleotide();
    }
    genome[i] = '\0'; // Null terminate the genome sequence
}

// Function to mutate a nucleotide
void mutateNucleotide(char *nucleotide)
{
    if (((double)rand() / (double)RAND_MAX) < MUTATION_RATE)
    {
        *nucleotide = randomNucleotide(); // Mutate the nucleotide
    }
}

// Function to mutate the genome sequence
void mutateGenome(char genome[])
{
    int i;
    for (i = 0; i < GENOME_LENGTH; i++)
    {
        mutateNucleotide(&genome[i]);
    }
}

// Function to print the genome sequence
void printGenome(char genome[])
{
    printf("%s\n", genome);
}

// Main function
int main()
{
    srand(time(NULL)); // Seed the random number generator
    
    char genome[GENOME_LENGTH + 1]; // Define a char array to hold the genome sequence
    
    printf("Generating initial genome sequence...\n");
    generateGenome(genome); // Generate the initial genome sequence
    printGenome(genome); // Print the initial genome sequence
    
    int i;
    for (i = 1; i <= 10; i++) // Mutate the genome sequence 10 times
    {
        printf("Mutating genome sequence %d...\n", i);
        mutateGenome(genome); // Mutate the genome sequence
        printGenome(genome); // Print the mutated genome sequence
    }
    
    return 0;
}