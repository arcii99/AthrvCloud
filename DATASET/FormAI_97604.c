//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 118
#define NUM_QUESTIONS 10

int main() {
    char elements[NUM_ELEMENTS][3] = {
        {"H"},
        {"He"},
        {"Li"},
        {"Be"},
        {"B"},
        {"C"},
        {"N"},
        {"O"},
        {"F"},
        {"Ne"},
        {"Na"},
        {"Mg"},
        {"Al"},
        {"Si"},
        {"P"},
        {"S"},
        {"Cl"},
        {"Ar"},
        {"K"},
        {"Ca"},
        {"Sc"},
        {"Ti"},
        {"V"},
        {"Cr"},
        {"Mn"},
        {"Fe"},
        {"Co"},
        {"Ni"},
        {"Cu"},
        {"Zn"},
        {"Ga"},
        {"Ge"},
        {"As"},
        {"Se"},
        {"Br"},
        {"Kr"},
        {"Rb"},
        {"Sr"},
        {"Y"},
        {"Zr"},
        {"Nb"},
        {"Mo"},
        {"Tc"},
        {"Ru"},
        {"Rh"},
        {"Pd"},
        {"Ag"},
        {"Cd"},
        {"In"},
        {"Sn"},
        {"Sb"},
        {"Te"},
        {"I"},
        {"Xe"},
        {"Cs"},
        {"Ba"},
        {"La"},
        {"Ce"},
        {"Pr"},
        {"Nd"},
        {"Pm"},
        {"Sm"},
        {"Eu"},
        {"Gd"},
        {"Tb"},
        {"Dy"},
        {"Ho"},
        {"Er"},
        {"Tm"},
        {"Yb"},
        {"Lu"},
        {"Hf"},
        {"Ta"},
        {"W"},
        {"Re"},
        {"Os"},
        {"Ir"},
        {"Pt"},
        {"Au"},
        {"Hg"},
        {"Tl"},
        {"Pb"},
        {"Bi"},
        {"Th"},
        {"Pa"},
        {"U"},
        {"Np"},
        {"Pu"},
        {"Am"},
        {"Cm"},
        {"Bk"},
        {"Cf"},
        {"Es"},
        {"Fm"},
        {"Md"},
        {"No"},
        {"Lr"},
        {"Rf"},
        {"Db"},
        {"Sg"},
        {"Bh"},
        {"Hs"},
        {"Mt"},
        {"Ds"},
        {"Rg"},
        {"Cn"},
        {"Nh"},
        {"Fl"},
        {"Mc"},
        {"Lv"},
        {"Ts"},
        {"Og"}
    };

    int random_indices[NUM_QUESTIONS];
    int i;

    // Generate random indices for questions
    srand(time(NULL));
    for (i = 0; i < NUM_QUESTIONS; i++) {
        random_indices[i] = rand() % NUM_ELEMENTS;
    }

    printf("Welcome to the periodic table quiz!\n\n");
    printf("The rules are simple: there are %d questions and you must guess the chemical "
           "symbol of each element.\n\n", NUM_QUESTIONS);

    // Ask questions and tally score
    int score = 0;
    for (i = 0; i < NUM_QUESTIONS; i++) {
        char element[3];
        printf("Question %d: What is the chemical symbol for %s?\n", i+1, elements[random_indices[i]]);
        scanf("%s", element);
        if (strcmp(elements[random_indices[i]], element) == 0) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %s.\n\n", elements[random_indices[i]]);
        }
    }

    // Give final score
    printf("You scored %d out of %d.\n", score, NUM_QUESTIONS);

    return 0;
}