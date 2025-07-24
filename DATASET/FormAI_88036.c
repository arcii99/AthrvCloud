//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char elements[118][3] = {
        "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne",
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
        "Rg", "Cn", "Nh", "Fl", "Mc", "Lv", "Ts", "Og"
    };

    int correct_answers = 0;
    int wrong_answers = 0;
    int total_questions = 0;

    srand(time(NULL));

    while (1) {
        int r = rand() % 118;
        printf("What is the atomic number of %s?\n", elements[r]);

        char ans[50];
        fgets(ans, 50, stdin);

        int answer = atoi(ans);
        if (answer == 0 && ans[0] != '0') {
            printf("Sorry, your answer must be a number.\n");
            continue;
        }

        if (answer == r + 1) {
            printf("You are correct!\n");
            correct_answers++;
        } else {
            printf("Sorry, the correct answer was %d.\n", r + 1);
            wrong_answers++;
        }

        total_questions++;

        printf("Do you want to continue? (y/n): ");
        char choice[10];
        fgets(choice, 10, stdin);
        if (choice[0] == 'n' || choice[0] == 'N') {
            printf("You answered %d questions correctly out of %d questions.\n", correct_answers, total_questions);
            printf("You answered %d questions incorrectly.\n", wrong_answers);

            if (correct_answers == total_questions) {
                printf("You are a periodic table genius!\n");
            } else {
                printf("Better luck next time!\n");
            }

            return 0;
        }
    }

    return 0;
}