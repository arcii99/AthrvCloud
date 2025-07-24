//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
char elements[118][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr", "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};
int num_elements = 118;

// Recursive quiz function
void periodic_table_quiz(int score) {
    // Generate random element number
    int element_num = rand() % num_elements;
    // Get element symbol for user to guess
    char element[3];
    strcpy(element, elements[element_num]);
    // Print question and get user input
    char guess[3];
    printf("What element has the symbol %s?\n", element);
    scanf("%s", guess);
    // Check if guess is correct
    if (strcmp(guess, element) == 0) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer was %s.\n", element);
    }
    // Ask user if they want to continue
    printf("Your score is %d. Do you want to continue? (y/n)\n", score);
    char choice;
    scanf(" %c", &choice);
    // If user wants to continue, recursively call the function with updated score
    if (choice == 'y') {
        periodic_table_quiz(score);
    } else {
        // If user does not want to continue, print final score
        printf("Thanks for playing. Your final score is %d.\n", score);
    }
}

int main() {
    // Introduce game and get user's name
    printf("Welcome to the Periodic Table Quiz!\n");
    char name[50];
    printf("What is your name?\n");
    scanf("%s", name);
    printf("Hi %s! Let's begin.\n", name);
    // Initialize random number generator
    srand(time(NULL));
    // Start game with score of 0
    periodic_table_quiz(0);
    return 0;
}