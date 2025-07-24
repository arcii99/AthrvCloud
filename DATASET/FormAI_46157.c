//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 4
#define MAX_GENOME 10000

void generate_random_genome(char genome[]) {
    int i;
    for(i = 0; i < MAX_GENOME; i++) {
        int random_nucleotide = rand() % 4; // randomly generate 0, 1, 2 or 3
        switch(random_nucleotide) {
            case 0:
                genome[i] = 'A';
                break;
            case 1:
                genome[i] = 'T';
                break;
            case 2:
                genome[i] = 'C';
                break;
            case 3:
                genome[i] = 'G';
                break;
        }
    }
    genome[i] = '\0'; // add null terminator at end
}

int main() {
    srand(time(NULL)); // set random seed based on current time
    char genome[MAX_GENOME+1];
    generate_random_genome(genome);
    printf("Randomly generated genome:\n%s\n", genome);
    
    // create simulated sequencing reads
    int i, j, read_number;
    char read[SIZE+1];
    for(read_number = 1, i = 0; i < MAX_GENOME-SIZE+1; i += SIZE) {
        strncpy(read, &genome[i], SIZE); // copy next SIZE characters of genome into read
        read[SIZE] = '\0'; // add null terminator at end
        printf("Read %d: %s\n", read_number, read);
        read_number++;
    }
    if(i < MAX_GENOME) { // print any remaining part of genome that is less than SIZE in length
        printf("Read %d: %s\n", read_number, &genome[i]);
    }
    return 0;
}