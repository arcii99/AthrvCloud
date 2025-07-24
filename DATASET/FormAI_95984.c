//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sequence(int nucleotides[], int length, int current){
    if(current == length) {
        for(int i=0; i<length; i++){
            switch(nucleotides[i]){
                case 0:
                    printf("A");
                    break;
                case 1:
                    printf("T");
                    break;
                case 2:
                    printf("G");
                    break;
                case 3:
                    printf("C");
                    break;
            }
        }
        printf("\n");
        return;
    }

    for(int i=0; i<4; i++){
        nucleotides[current] = i;
        sequence(nucleotides, length, current+1);
    }
}

int main(){
    int length, nucleotides[1000];
    printf("Enter length of sequence: ");
    scanf("%d", &length);

    printf("Possible sequences:\n");

    sequence(nucleotides, length, 0);

    return 0;
}