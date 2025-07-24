//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    // Initialize the periodic table
    char periodicTable[118][3] = {
        "H ", "He", "Li", "Be", "B ", "C ", "N ", "O ", "F ", "Ne", 
        "Na", "Mg", "Al", "Si", "P ", "S ", "Cl", "Ar", "K ", "Ca",
        "Sc", "Ti", "V ", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
        "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y ", "Zr",
        "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
        "Sb", "Te", "I ", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
        "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
        "Lu", "Hf", "Ta", "W ", "Re", "Os", "Ir", "Pt", "Au", "Hg",
        "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
        "Pa", "U ", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
        "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
        "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
    };

    // Shuffle the periodic table
    for (int i = 0; i < 118; i++) {
        int j = rand() % 118;
        char temp[3];
        strcpy(temp, periodicTable[i]);
        strcpy(periodicTable[i], periodicTable[j]);
        strcpy(periodicTable[j], temp);
    }

    printf("*** WELCOME TO THE MEDIEVAL PERIODIC TABLE QUIZ ***\n");
    printf("Can you match the elements with their symbols?\n");

    int score = 0;
    for (int i = 0; i < 10; i++) {
        char symbol[3];
        printf("\nQuestion %d: What is the symbol of \"%s\"?\n", i+1, periodicTable[i]);
        scanf("%2s", symbol); // Only allow 2 characters
        if (strcmp(symbol, periodicTable[i]) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct symbol is %s\n", periodicTable[i]);
        }
    }

    printf("\n\nYou got %d out of 10 correct!\n", score);
    if (score < 5) {
        printf("You need to study your medieval periodic table!\n");
    } else if (score < 8) {
        printf("You have a good understanding of the medieval periodic table.\n");
    } else {
        printf("You are a medieval periodic table expert!\n");
    }

    return 0;
}