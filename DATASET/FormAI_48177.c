//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//DNA string of length 100
#define N 100

void mutate(char dna[], int pos){
    int r = rand() % 4;
    switch(r){
        case 0: dna[pos] = 'A'; break;
        case 1: dna[pos] = 'T'; break;
        case 2: dna[pos] = 'C'; break;
        case 3: dna[pos] = 'G'; break;
    }
}

void insert(char dna[], int pos){
    int r = rand() % 4;
    for(int i=N-1;i>pos;i--){
        dna[i] = dna[i-1];
    }
    switch(r){
        case 0: dna[pos] = 'A'; break;
        case 1: dna[pos] = 'T'; break;
        case 2: dna[pos] = 'C'; break;
        case 3: dna[pos] = 'G'; break;
    }
}

void delete(char dna[], int pos){
    for(int i=pos;i<N;i++){
        dna[i] = dna[i+1];
    }
    dna[N-1] = '-';
}

int compare(char dna1[], char dna2[]){
    int score = 0;
    for(int i=0;i<N;i++){
        if(dna1[i] == dna2[i]) score++;
    }
    return score;
}

void printDna(char dna[]){
    for(int i=0;i<N;i++){
        printf("%c", dna[i]);
    }
    printf("\n");
}

int main(){
    srand(time(NULL));
    char dna[N];
    char dna2[N];
    int i, j;
    for(i=0;i<N;i++){
        int r = rand() % 4;
        switch(r){
            case 0: dna[i] = 'A'; break;
            case 1: dna[i] = 'T'; break;
            case 2: dna[i] = 'C'; break;
            case 3: dna[i] = 'G'; break;
        }
        dna2[i] = dna[i];
    }
    int mutations = rand() % 10 + 1;
    int inserts = rand() % 10 + 1;
    int deletes = rand() % 10 + 1;
    printf("Original DNA: ");
    printDna(dna);
    printf("Mutating %d positions\n", mutations);
    for(i=0;i<mutations;i++){
        int pos = rand() % N;
        mutate(dna, pos);
    }
    printf("Inserting %d bases\n", inserts);
    for(i=0;i<inserts;i++){
        int pos = rand() % N;
        insert(dna, pos);
    }
    printf("Deleting %d bases\n", deletes);
    for(i=0;i<deletes;i++){
        int pos = rand() % N;
        delete(dna, pos);
    }
    printf("Mutated DNA: ");
    printDna(dna);
    int score = compare(dna, dna2);
    printf("Match score: %d/%d\n", score, N);
    if(score == N){
        printf("Original and Mutated DNA are identical\n");
    }
    return 0;
}