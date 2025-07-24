//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GENOME_LENGTH 100
#define BASES "ATCG"

int main() {
    // Set seed for random number generator
    srand(time(NULL));
    
    char genome[GENOME_LENGTH];
    
    // Generate random genome sequence
    for(int i = 0; i < GENOME_LENGTH; i++) {
        genome[i] = BASES[rand() % 4];
    }
    
    // Print out genome sequence
    printf("Genome Sequence:\n");
    for(int i = 0; i < GENOME_LENGTH; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
    
    // Calculate base frequencies
    int a_count = 0, t_count = 0, c_count = 0, g_count = 0;
    for(int i = 0; i < GENOME_LENGTH; i++) {
        switch(genome[i]) {
            case 'A':
                a_count++;
                break;
            case 'T':
                t_count++;
                break;
            case 'C':
                c_count++;
                break;
            case 'G':
                g_count++;
                break;
        }
    }
    
    // Calculate total base count
    int total_bases = a_count + t_count + c_count + g_count;
    
    // Calculate base frequencies as percentages
    double a_freq = (double)a_count / total_bases * 100;
    double t_freq = (double)t_count / total_bases * 100;
    double c_freq = (double)c_count / total_bases * 100;
    double g_freq = (double)g_count / total_bases * 100;
    
    // Print out base frequencies
    printf("Base frequencies:\n");
    printf("A: %.1f%%\n", a_freq);
    printf("T: %.1f%%\n", t_freq);
    printf("C: %.1f%%\n", c_freq);
    printf("G: %.1f%%\n", g_freq);
    
    return 0;
}