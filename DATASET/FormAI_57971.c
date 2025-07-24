//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // initialize the periodic table with the element names
    char periodicTable[118][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", 
    "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", 
    "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", 
    "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", 
    "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", 
    "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

    // initialize the random number generator
    srand(time(NULL));

    // initialize the score variable
    int score = 0;

    while (1) {
        // generate two random numbers between 0 and 117
        int num1 = rand() % 118;
        int num2 = rand() % 118;

        // print the question
        printf("What is the chemical symbol for %s + %s? ", periodicTable[num1], periodicTable[num2]);

        // read the user input
        char answer[3];
        scanf("%2s", answer);

        // check if the answer is correct
        if (answer[0] == periodicTable[num1][0] && answer[1] == periodicTable[num2][0]) {
            printf("Correct! ");
            score++;
        } else {
            printf("Incorrect. ");
        }

        // print the current score
        printf("Score: %d\n", score);
    }

    return 0;
}