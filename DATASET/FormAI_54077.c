//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *get_random_element(char *elements[], int num_elements) {
    int random_index = rand() % num_elements;
    return elements[random_index];
}

void display_table(char *elements[][7], int num_rows, int num_cols) {
    printf("\n  ----------------------------------------------------\n");
    for (int i = 0; i < num_rows; i++) {
        printf(" |");
        for (int j = 0; j < num_cols; j++) {
            if (elements[i][j] != NULL) {
                printf(" %-3s |", elements[i][j]);
            } else {
                printf("     |");
            }
        }
        printf("\n  ----------------------------------------------------\n");
    }
}

int main() {
    srand(time(NULL));

    char *elements[][7] = {
        {"H", "Li", "Na", "K", "Rb", "Cs", "Fr"},
        {"Be", "Mg", "Ca", "Sr", "Ba", "Ra", NULL},
        {"Sc", "Y", NULL, NULL, NULL, NULL, NULL},
        {"Ti", "Zr", "Hf", "Rf", NULL, NULL, NULL},
        {"V", "Nb", "Ta", "Db", NULL, NULL, NULL},
        {"Cr", "Mo", "W", "Sg", NULL, NULL, NULL},
        {"Mn", "Tc", "Re", "Bh", NULL, NULL, NULL},
        {"Fe", "Ru", "Os", "Hs", NULL, NULL, NULL},
        {"Co", "Rh", "Ir", "Mt", NULL, NULL, NULL},
        {"Ni", "Pd", "Pt", "Ds", NULL, NULL, NULL},
        {"Cu", "Ag", "Au", "Rg", NULL, NULL, NULL},
        {"Zn", "Cd", "Hg", "Cn", NULL, NULL, NULL},
        {"B", "Al", "Ga", "In", "Tl", "Nh", NULL},
        {"C", "Si", "Ge", "Sn", "Pb", "Fl", NULL},
        {"N", "P", "As", "Sb", "Bi", "Mc", NULL},
        {"O", "S", "Se", "Te", "Po", "Lv", NULL},
        {"F", "Cl", "Br", "I", "At", "Ts", NULL},
        {"He", "Ne", "Ar", "Kr", "Xe", "Rn", "Og"},
        {"La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu"},
        {"Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb"},
        {"Lu", "Ac", "Th", "Pa", "U", "Np", "Pu"},
        {"Am", "Cm", "Bk", "Cf", "Es", "Fm", NULL},
        {"Md", "No", "Lr", NULL, NULL, NULL, NULL}
    };

    int num_rows = sizeof(elements) / sizeof(elements[0]);
    int num_cols = sizeof(elements[0]) / sizeof(elements[0][0]);

    printf("Welcome to the Periodic Table Quiz!\n\n");
    display_table(elements, num_rows, num_cols);

    int num_questions;
    printf("\nHow many questions would you like? ");
    scanf("%d", &num_questions);

    for (int i = 1; i <= num_questions; i++) {
        char *random_element = get_random_element(elements, num_rows * num_cols);
        if (random_element != NULL) {
            printf("\nQuestion %d:\nWhat is the symbol for %s? ", i, random_element);

            char user_answer[3];
            scanf("%s", user_answer);

            if (strcmp(user_answer, random_element) == 0) {
                printf("Congratulations, your answer is correct!\n");
            } else {
                printf("Sorry, the correct answer is %s.\n", random_element);
            }
        }
    }

    printf("\nThanks for playing!\n");

    return 0;
}