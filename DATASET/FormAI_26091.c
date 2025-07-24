//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

// Function to translate an input string into alien language
void translateToAlien(char* inputString) {
    int length = strlen(inputString);
    char outputString[length + 1];
    outputString[length] = '\0';

    // Alien language translation rules:
    // A -> X, B -> Y, C -> Z, D -> A, E -> B, F -> C, G -> D, H -> E, I -> F, J -> G,
    // K -> H, L -> I, M -> J, N -> K, O -> L, P -> M, Q -> N, R -> O, S -> P, T -> Q,
    // U -> R, V -> S, W -> T, X -> U, Y -> V, Z -> W

    for(int i = 0; i < length; i++) {
        char c = inputString[i];

        if(c >= 'A' && c <= 'Z') {
            c = (c - 'A' + 23) % 26 + 'A';
        }

        outputString[i] = c;
    }

    printf("\nTranslated Alien language: %s\n", outputString);
}

int main() {
    char inputString[100];

    printf("Enter a string to translate into Alien language (A -> X, B -> Y, C -> Z, ...):\n");
    fgets(inputString, 100, stdin);

    // Removing newline character from input string
    inputString[strcspn(inputString, "\n")] = 0;

    printf("\nInput String: %s", inputString);

    translateToAlien(inputString);

    return 0;
}