//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_NUCLEOTIDES 500
#define MAX_SAMPLE_SIZE 100

char nucleotides[MAX_NUCLEOTIDES] = {'A', 'T', 'G', 'C'};

int main(){

    int sample_size;
    int sequencing_depth;

    printf("Enter the sample size (max size is %d): ", MAX_SAMPLE_SIZE);
    scanf("%d", &sample_size);
    printf("Enter the sequencing depth: ");
    scanf("%d", &sequencing_depth);

    srand(time(0)); // Set the random seed

    char samples[sample_size][sequencing_depth + 1];

    for(int i=0; i<sample_size; i++){

        printf("Sample %d: ", i+1);

        for(int j=0; j<sequencing_depth; j++){
            int index = rand() % 4;
            samples[i][j] = nucleotides[index];
            printf("%c", samples[i][j]);
        }
        printf("\n");
    }

    return 0;
}