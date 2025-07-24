//FormAI DATASET v1.0 Category: Computer Biology ; Style: funny
#include <stdio.h>

int main() {
    printf("Welcome to the Biology Lab!\n");
    printf("Let's create a creature.\n\n");

    // First, we need to get the DNA sequence from the user
    char dna_sequence[50];
    printf("Enter the DNA sequence for the creature (max 50 characters): ");
    fgets(dna_sequence, 50, stdin);

    printf("Great! Now, let's analyze the DNA sequence to see what kind of creature we are dealing with.\n");

    int gc_count = 0;
    int at_count = 0;

    for (int i = 0; i < strlen(dna_sequence); i++) {
        if (dna_sequence[i] == 'G' || dna_sequence[i] == 'C') {
            gc_count++;
        } else if (dna_sequence[i] == 'A' || dna_sequence[i] == 'T') {
            at_count++;
        } else {
            printf("Invalid DNA sequence.\n");
            return 1;
        }
    }

    if (gc_count > at_count) {
        printf("This creature is more likely to be a cold-blooded reptile.\n");
    } else if (gc_count < at_count) {
        printf("This creature is more likely to be a warm-blooded mammal.\n");
    } else {
        printf("Hmm, this creature seems to have an equal amount of GC and AT pairs. Maybe it's a platypus?\n");
    }

    // Let's give the creature a name
    char name[20];
    printf("What would you like to name your creature (max 20 characters)? ");
    fgets(name, 20, stdin);

    printf("Excellent choice! Your creature's name is now %s.\n", name);

    return 0;
}