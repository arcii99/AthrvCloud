//FormAI DATASET v1.0 Category: Computer Biology ; Style: minimalist
#include <stdio.h>

/*
* This program takes DNA sequences as input and outputs their complementary DNA strands.
* For example, if the input is "ATCG", the output will be "TAGC".
*/

int main() {
    char input[100];
    printf("Enter a DNA sequence: ");
    scanf("%s", input);

    int i;

    // Loop through the input string and replace each nucleotide with its complementary nucleotide
    for(i = 0; input[i] != '\0'; i++) {
        // If the current nucleotide is A, replace it with T
        if(input[i] == 'A') {
            input[i] = 'T';
        }
        // If the current nucleotide is T, replace it with A
        else if(input[i] == 'T') {
            input[i] = 'A';
        }
        // If the current nucleotide is C, replace it with G
        else if(input[i] == 'C') {
            input[i] = 'G';
        }
        // If the current nucleotide is G, replace it with C
        else if(input[i] == 'G') {
            input[i] = 'C';
        }
    }

    printf("Complementary DNA Sequence: %s", input);

    return 0;
}