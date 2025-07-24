//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: sophisticated
#include <stdio.h>
#include <string.h>

struct Element {
    char name[20];
    char symbol[3];
    int atomicNumber;
};

int main() {
    
    int score = 0;
    int totalQuestions = 10;
    
    // create an array of elements
    struct Element elements[] = {
        {"Hydrogen", "H", 1},
        {"Helium", "He", 2},
        {"Lithium", "Li", 3},
        {"Beryllium", "Be", 4},
        {"Carbon", "C", 6},
        {"Nitrogen", "N", 7},
        {"Oxygen", "O", 8},
        {"Fluorine", "F", 9},
        {"Neon", "Ne", 10},
        {"Sodium", "Na", 11},
        {"Magnesium", "Mg", 12},
        {"Aluminum", "Al", 13},
        {"Silicon", "Si", 14},
        {"Phosphorus", "P", 15},
        {"Sulfur", "S", 16},
        {"Chlorine", "Cl", 17},
        {"Argon", "Ar", 18},
        {"Potassium", "K", 19},
        {"Calcium", "Ca", 20},
        {"Iron", "Fe", 26}
    };
    
    // shuffle the elements array
    for (int i = 0; i < 20; i++) {
        int j = rand() % 20;
        struct Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
    
    // ask questions
    for (int i = 0; i < totalQuestions; i++) {
        printf("Question #%d: What is the symbol for %s?\n", i+1, elements[i].name);
        char answer[3];
        scanf("%s", answer);
        if (strcmp(answer, elements[i].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[i].symbol);
        }
    }
    
    // show final score
    printf("\nYour final score is %d out of %d!\n", score, totalQuestions);
    
    return 0;
}