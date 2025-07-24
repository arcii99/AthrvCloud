//FormAI DATASET v1.0 Category: Computer Biology ; Style: minimalist
#include <stdio.h>

// Let's define a structure for DNA

typedef struct {
    int genes[100000];
    int length;
} DNA;

// This function takes in two DNA strands and returns their complement

void complement(DNA strand1, DNA strand2) {
    for (int i = 0; i < strand1.length; i++) {
        if (strand1.genes[i] == 0) {
            strand2.genes[i] = 3;
        } else if (strand1.genes[i] == 1) {
            strand2.genes[i] = 2;
        } else if (strand1.genes[i] == 2) {
            strand2.genes[i] = 1;
        } else {
            strand2.genes[i] = 0;
        }
    }
}

// Now, let's create a sequence of DNA

int main() {
    DNA sequence = {{0, 2, 1, 3, 0, 0, 1, 2, 2, 1}, 10};
    DNA complementSequence = {{0}, sequence.length};

    complement(sequence, complementSequence);

    printf("Original Sequence: ");
    for (int i = 0; i < sequence.length; i++) {
        printf("%d ", sequence.genes[i]);
    }

    printf("\n");

    printf("Complement Sequence: ");
    for (int i = 0; i < complementSequence.length; i++) {
        printf("%d ", complementSequence.genes[i]);
    }

    printf("\n");

    return 0;
}