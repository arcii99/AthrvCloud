//FormAI DATASET v1.0 Category: Computer Biology ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    // generate random DNA sequence
    char DNA[50];
    srand(time(NULL));
    for(int i=0; i<50; i++) {
        int rand_num = rand() % 4; // generates random number between 0 and 3
        switch(rand_num) {
            case 0:
                DNA[i] = 'A';
                break;
            case 1:
                DNA[i] = 'C';
                break;
            case 2:
                DNA[i] = 'G';
                break;
            case 3:
                DNA[i] = 'T';
                break;
            default:
                break;
        }
    }

    printf("Generated DNA sequence: %s\n", DNA);

    // count nucleotides
    int adenine_count = 0;
    int cytosine_count = 0;
    int guanine_count = 0;
    int thymine_count = 0;
    for(int i=0; i<50; i++) {
        switch(DNA[i]) {
            case 'A':
                adenine_count++;
                break;
            case 'C':
                cytosine_count++;
                break;
            case 'G':
                guanine_count++;
                break;
            case 'T':
                thymine_count++;
                break;
            default:
                break;
        }
    }

    printf("Adenine count: %d\n", adenine_count);
    printf("Cytosine count: %d\n", cytosine_count);
    printf("Guanine count: %d\n", guanine_count);
    printf("Thymine count: %d\n", thymine_count);

    return 0;
}