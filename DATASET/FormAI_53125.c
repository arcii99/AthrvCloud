//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for rand() function

int main() {
    // define the array of elements and their properties
    char elements[118][3] = {
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

    int atomic_numbers[118] = {
        1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10, 
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
        51, 52, 53, 54, 55, 56, 57, 58, 59, 60,
        61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
        71, 72, 73, 74, 75, 76, 77, 78, 79, 80,
        81, 82, 83, 84, 85, 86, 87, 88, 89, 90,
        91, 92, 93, 94, 95, 96, 97, 98, 99, 100,
        101,102,103,104,105,106,107,108,109,110,
        111,112,113,114,115,116,117,118
    };

    char symbols[118][3] = {
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

    int group[118] = {
        1, 18,  1,  2, 13, 14, 15, 16, 17, 18,
        1,  2, 13, 14, 15, 16, 17, 18,  1,  2,
        3,  4,  5,  6,  7,  8,  9, 10, 11, 12,
        13, 14, 15, 16, 17, 18,  1,  2,  3,  4,
        5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
        15, 16, 17, 18,  1,  2,  3,  4,  5,  6,
        7,  8,  9, 10, 11, 12, 13, 14, 15, 16,
        17, 18,  1,  2,  3,  4,  5,  6,  7,  8,
        9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
        1,  2,  3,  4,  5,  6,  7,  8,  9, 10,
        11, 12, 13, 14, 15, 16, 17, 18,  1,  2,
        3,  4,  5,  6,  7,  8,  9, 10, 11, 12
    };

    int period[118] = {
        1, 1, 2, 2, 2, 2, 2, 2, 2, 2,
        3, 3, 3, 3, 3, 3, 3, 3, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 5, 5, 5, 5,
        5, 5, 5, 5, 5, 5, 6, 6, 6, 6,
        6, 6, 6, 6, 6, 6, 7, 7, 7, 7,
        7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
        7, 7, 7, 7, 7, 7, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
        8, 8, 8, 8, 8, 8, 8, 8, 8, 8
    };

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be presented with a symbol or an atomic number, and you will have to guess which element it corresponds to.\n");
    printf("Let's get started!\n\n");

    srand(time(NULL)); // seed for rand() function

    int num_correct = 0; // initialize number of correct guesses to 0
    char input[3]; // input buffer for user's guess

    while (1) {
        int random_num = rand() % 118; // generate a random number from 0 to 117

        // ask the user which property they want to guess from
        printf("What do you want to guess: symbol (s) or atomic number (n)? ");
        fgets(input, 3, stdin);

        if (input[0] == 's') { // if the user wants to guess the symbol
            printf("Guess the element for the symbol %s: ", symbols[random_num]);
            fgets(input, 3, stdin);
            printf("\n");

            if (input[0] == elements[random_num][0] && input[1] == elements[random_num][1]) { // check if the guess was correct
                num_correct++;
                printf("Correct! You have %d correct guesses so far.\n\n", num_correct);
            } else {
                printf("Sorry, that is incorrect. The correct element for the symbol %s is %s.\n\n", symbols[random_num], elements[random_num]);
            }
        } else if (input[0] == 'n') { // if the user wants to guess the atomic number
            printf("Guess the element for the atomic number %d: ", atomic_numbers[random_num]);
            fgets(input, 3, stdin);
            printf("\n");

            if (atoi(input) == atomic_numbers[random_num]) { // check if the guess was correct
                num_correct++;
                printf("Correct! You have %d correct guesses so far.\n\n", num_correct);
            } else {
                printf("Sorry, that is incorrect. The correct element for the atomic number %d is %s.\n\n", atomic_numbers[random_num], elements[random_num]);
            }
        } else { // if the user entered an invalid input
            printf("Invalid input. Please enter 's' for symbol or 'n' for atomic number.\n\n");
        }

        // ask the user whether to continue or not
        printf("Do you want to continue? (y/n) ");
        fgets(input, 3, stdin);

        if (input[0] == 'n') { // if the user doesn't want to continue
            break;
        }
    }

    printf("You got %d correct guesses in total. Thanks for playing!\n", num_correct);

    return 0;
}