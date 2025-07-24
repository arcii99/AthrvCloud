//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_LENGTH 1000

int main() {
    int genome[SEQUENCE_LENGTH];
    srand(time(NULL)); // initialize random seed

    // randomly generate genome sequence
    for(int i=0; i<SEQUENCE_LENGTH; i++) {
        genome[i] = rand() % 4; // create a random gene at each index
    }

    // print out the generated genome sequence
    printf("Generated Genome Sequence:\n");

    for(int i=0; i<SEQUENCE_LENGTH; i++) {
        switch(genome[i]) {
            case 0:
                printf("A");
                break;
            case 1:
                printf("C");
                break;
            case 2:
                printf("G");
                break;
            case 3:
                printf("T");
                break;
        }
    }
    printf("\n");

    // randomly remove segments from genome sequence
    int num_segments = rand() % 10; // randomly choose number of segments to remove
    int segment_lengths[num_segments]; // store lengths of segments to be removed

    for(int i=0; i<num_segments; i++) {
        int segment_length = rand() % 100; // randomly choose length of segment to remove
        int segment_start = rand() % (SEQUENCE_LENGTH - segment_length); // randomly choose starting index of segment

        // store segment length and remove from genome sequence
        segment_lengths[i] = segment_length;
        for(int j=segment_start; j<segment_start+segment_length; j++) {
            genome[j] = -1; // mark segment as removed with a designated value
        }
    }

    // print out the modified genome sequence with removed segments marked as '*'
    printf("Modified Genome Sequence with Removed Segments:\n");

    for(int i=0; i<SEQUENCE_LENGTH; i++) {
        if(genome[i] == -1) {
            printf("*");
        } else {
            switch(genome[i]) {
                case 0:
                    printf("A");
                    break;
                case 1:
                    printf("C");
                    break;
                case 2:
                    printf("G");
                    break;
                case 3:
                    printf("T");
                    break;
            }
        }
    }
    printf("\n");

    // print out information about removed segments
    printf("Segments Removed:\n");

    for(int i=0; i<num_segments; i++) {
        printf("Segment %d: Length %d\n", i+1, segment_lengths[i]);
    }

    return 0;
}