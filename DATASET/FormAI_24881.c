//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int len;
    printf("Enter the length of the DNA Sequence: ");
    scanf("%d",&len);

    char *sequence = (char*) malloc((len+1) * sizeof(char)); //allocating memory for sequence

    srand(time(NULL)); //seeding random number generator

    //assigning random nucleotides to the sequence
    for(int i=0;i<len;i++){
        int r = rand() % 4;
        if(r == 0){
            sequence[i] = 'A';
        }
        else if(r == 1){
            sequence[i] = 'T';
        }
        else if(r == 2){
            sequence[i] = 'C';
        }
        else{
            sequence[i] = 'G';
        }
    }

    sequence[len] = '\0'; //terminating the sequence with null character

    //printing the generated sequence
    printf("\nGenerated Sequence: %s",sequence);

    free(sequence); //freeing the allocated memory

    return 0;
}