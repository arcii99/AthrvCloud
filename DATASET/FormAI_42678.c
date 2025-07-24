//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 1000000

int main(){
    srand(time(NULL));
    char dna[LENGTH];
    int i, j;
    for(i=0; i<LENGTH; i++){
        int nucleotide = rand()%4;
        if(nucleotide == 0){
            dna[i] = 'A';
        }
        else if(nucleotide == 1){
            dna[i] = 'C';
        }
        else if(nucleotide == 2){
            dna[i] = 'G';
        }
        else{
            dna[i] = 'T';
        }
    }

    char query_1[100];
    printf("Enter the Query 1:");
    scanf("%s", &query_1);

    char query_2[100];
    printf("Enter the Query 2:");
    scanf("%s", &query_2);

    int match_1=0;
    for(i=0; i<LENGTH-strlen(query_1); i++){
        for(j=0; j<strlen(query_1); j++){
            if(dna[i+j] != query_1[j]){
                break;
            }
            if(j==strlen(query_1)-1){
                match_1++;
            }
        }
    }

    int match_2=0;
    for(i=0; i<LENGTH-strlen(query_2); i++){
        for(j=0; j<strlen(query_2); j++){
            if(dna[i+j] != query_2[j]){
                break;
            }
            if(j==strlen(query_2)-1){
                match_2++;
            }
        }
    }

    printf("Query 1 has %d matches in the genome.\n", match_1);
    printf("Query 2 has %d matches in the genome.\n", match_2);

    return 0;

}