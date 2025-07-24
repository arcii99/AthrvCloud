//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *elements[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"}; // Array of elements

int main() {
    int score = 0; // initialize user's score to 0
    int num_questions, i; // declare variables
    char input[3]; // holds user's input
    
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions would you like to answer? "); // prompt user for number of questions
    scanf("%d", &num_questions);
    printf("\n");
    
    for (i = 0; i < num_questions; i++) {
        int index = rand() % 118; // generates random index of element array
        printf("What is the symbol for %s? ", elements[index]); // prompt user for symbol of element
        scanf("%s", input);
        if (strcmp(input, elements[index]) == 0) { // check if user's input matches element symbol
            printf("Correct answer!\n");
            score++;
        } else {
            printf("Incorrect answer. The correct answer is %s.\n", elements[index]);
        }
    }
    printf("\nFinal score: %d out of %d\n", score, num_questions); // display user's final score
    return 0;
}