//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set up the periodic table
    char *elements[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
    int num_elements = sizeof(elements) / sizeof(char *);

    // Seed the random number generator
    srand((unsigned)time(NULL));

    // Generate a random index for the element
    int rand_index = rand() % num_elements;

    // Prompt the user to guess the element at this index
    printf("What element occupies the position with atomic number %d in the periodic table?\n", rand_index + 1);

    // Read in the user's guess
    char guess[3];
    scanf("%s", guess);

    // Check if the guess is correct
    if (strcmp(guess, elements[rand_index]) == 0)
    {
        printf("Congratulations! You guessed the element correctly!\n");
    }
    else
    {
        printf("Sorry, that was incorrect. The correct element was %s.\n", elements[rand_index]);
    }

    return 0;
}