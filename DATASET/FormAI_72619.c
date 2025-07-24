//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//function to shuffle array
void shuffle(int *array, int n) {
    int i, j, temp;
    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

int main() {
    srand(time(NULL)); //seed for random number generator
    int correct_answers = 0; //initialize number of correct answers
    int total_questions = 0; //initialize number of total questions asked

    //array of elements and their corresponding symbols
    char *elements[] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium"};
    char *symbols[] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca"};

    //initialize array of indices to shuffle
    int indices[20];
    for (int i = 0; i < 20; i++) {
        indices[i] = i;
    }

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be shown an element and you must guess its symbol.\n");

    //loop through all elements in shuffled order
    for (int i = 0; i < 20; i++) {
        shuffle(indices, 20); //shuffle indices
        for (int j = 0; j < 20; j++) {
            int index = indices[j]; //get index of current element
            char *element = elements[index];
            char *symbol = symbols[index];
            printf("What is the symbol for %s?\n", element);
            char guess[3]; //initialize char array for guess
            scanf("%s", guess);
            if (strcmp(guess, symbol) == 0) { //compare guess to actual symbol
                printf("Correct!\n");
                correct_answers++;
            }
            else {
                printf("Incorrect. The symbol for %s is %s.\n", element, symbol);
            }
            total_questions++;
        }
    }

    printf("Quiz complete!\n");
    printf("You answered %d out of %d questions correctly.\n", correct_answers, total_questions);

    return 0;
}