//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NO_OF_ELEMENTS 118
#define MAX_SYMBOL_LENGTH 3

char elements[NO_OF_ELEMENTS][MAX_SYMBOL_LENGTH] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
                                                    "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca",
                                                    "Sc", "Ti", "V", "Cr", "Mn", "Fe", "Co", "Ni", "Cu", "Zn",
                                                    "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y", "Zr",
                                                    "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn",
                                                    "Sb", "Te", "I", "Xe", "Cs", "Ba", "La", "Ce", "Pr", "Nd",
                                                    "Pm", "Sm", "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb",
                                                    "Lu", "Hf", "Ta", "W", "Re", "Os", "Ir", "Pt", "Au", "Hg",
                                                    "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra", "Ac", "Th",
                                                    "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", "Fm",
                                                    "Md", "No", "Lr", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds",
                                                    "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"};

int main()
{
    // Initialize variables
    int score = 0, question_count = 0;
    char answer[MAX_SYMBOL_LENGTH];
    char answer_upper[MAX_SYMBOL_LENGTH];
    int element_index;
    char user_input[MAX_SYMBOL_LENGTH];
    char should_exit = 'N';
    
    // Display welcome message and instructions
    printf("Welcome to the Periodic Table quiz!\n");
    printf("You will be given the symbol of an element, and you must enter the name of the element.\n");
    printf("You can exit the quiz at any time by typing 'exit'.\n\n");
    
    // Continue asking questions until the user chooses to exit
    do {
        // Pick a random element from the elements array
        element_index = rand() % NO_OF_ELEMENTS;
        
        // Ask the user to enter the name of the element
        printf("What is the symbol for %s? ", elements[element_index]);
        fgets(user_input, MAX_SYMBOL_LENGTH, stdin);
        
        // Remove newline character from user_input
        user_input[strcspn(user_input, "\n")] = 0;
        
        // Convert user_input to uppercase
        int i;
        for (i = 0; user_input[i]; i++) {
            answer_upper[i] = toupper(user_input[i]);
        }
        answer_upper[i] = '\0';
        
        // Check if user wants to exit
        if (strcmp(answer_upper, "EXIT") == 0) {
            should_exit = 'Y';
        }
        else {
            // Check if the user's answer is correct
            if (strcmp(answer_upper, elements[element_index]) == 0) {
                printf("Correct!\n\n");
                score++;
            }
            else {
                printf("Incorrect. The correct answer is %s.\n\n", elements[element_index]);
            }
            question_count++;
        }
    } while (should_exit != 'Y');
    
    // Display final score
    printf("You answered %d out of %d questions correctly.\n", score, question_count);

    return 0;
}