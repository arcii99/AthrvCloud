//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: minimalist
#include <stdio.h>
#include <string.h>

#define MAX_ELEMENTS 118

int main() {
    // initialize the periodic table
    char periodicTable[MAX_ELEMENTS][3] = {
        "H", "He",
        "Li", "Be", "B",  "C",  "N",  "O",  "F",  "Ne",
        "Na", "Mg", "Al", "Si", "P",  "S",  "Cl", "Ar",
        "K",  "Ca", "Sc", "Ti", "V",  "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr",
        "Rb", "Sr", "Y",  "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I",  "Xe",
        "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu",
        "Hf", "Ta", "W",  "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn",
        "Fr", "Ra", "Ac", "Th", "Pa", "U",  "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr"
    };
    
    // initialize the answers and score
    char answers[MAX_ELEMENTS][3];
    int score = 0;
    
    // iterate through elements and ask for user input
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        printf("What is the symbol for element #%d? ", i + 1);
        scanf("%s", answers[i]);
        
        // check if the answer is correct
        if (strcmp(answers[i], periodicTable[i]) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", periodicTable[i]);
        }
    }
    
    // display the final score
    printf("You scored %d out of %d.\n", score, MAX_ELEMENTS);
    
    return 0;
}