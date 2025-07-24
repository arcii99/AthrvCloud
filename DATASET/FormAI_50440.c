//FormAI DATASET v1.0 Category: Computer Biology ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Structure for DNA
struct DNA {
    char sequence[1000];
};

// Function to generate a random DNA sequence
void generateRandomSequence(char sequence[]) {
    int i;
    char nitrogenousBases[4] = {'A', 'T', 'C', 'G'};

    for(i = 0; i < 1000; i++) {
        sequence[i] = nitrogenousBases[rand() % 4];
    }
}

// Function to count the number of each nitrogenous base in a DNA sequence
void countNitrogenousBases(char sequence[], int count[]) {
    int i;

    for(i = 0; i < 1000; i++) {
        switch(sequence[i]) {
            case 'A':
                count[0]++;
                break;
            case 'T':
                count[1]++;
                break;
            case 'C':
                count[2]++;
                break;
            case 'G':
                count[3]++;
                break;
        }
    }
}

// Function to display the nitrogenous bases count in a DNA sequence
void displayNitrogenousBasesCount(int count[]) {
    printf("Number of Adenine (A) bases: %d\n", count[0]);
    printf("Number of Thymine (T) bases: %d\n", count[1]);
    printf("Number of Cytosine (C) bases: %d\n", count[2]);
    printf("Number of Guanine (G) bases: %d\n", count[3]);
}

int main() {
    srand(time(0));
    struct DNA dna;
    int count[4] = {0, 0, 0, 0};

    generateRandomSequence(dna.sequence);
    countNitrogenousBases(dna.sequence, count);
    displayNitrogenousBasesCount(count);

    return 0;
}