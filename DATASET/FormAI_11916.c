//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main() {
    char periodicTable[118][3] = {
        "H", "He",
        "Li", "Be", "B", "C", "N", "O", "F", "Ne",
        "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar",
        "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr",
        "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe",
        "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn",
        "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
    };

    int numQuestions;
    printf("Welcome to the periodic table quiz!\n");
    printf("How many questions would you like to answer? (max: 118)\n");
    scanf("%d", &numQuestions);
    printf("\n");

    if (numQuestions > 118) {
        printf("Sorry, the maximum number of questions is 118.\n");
        return 0;
    }

    srand(time(0)); // seed the random number generator with the current time
    int score = 0;

    for (int i = 1; i <= numQuestions; i++) {
        int randNum = rand() % 118; // generate a random number between 0 and 117
        char guess[3];
        printf("Question %d:\n", i);
        printf("What is the symbol for element number %d?\n", randNum + 1);
        scanf("%s", guess);

        if (strcasecmp(guess, periodicTable[randNum]) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct symbol is %s.\n", periodicTable[randNum]);
        }
        printf("\n");
    }

    printf("Quiz complete! You answered %d out of %d questions correctly.\n", score, numQuestions);

    return 0;
}