//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 7
#define COLS 18

// Define structure for each element in the periodic table
typedef struct element {
    char symbol[3];
    char name[25];
    int atomic_num;
    float atomic_mass;
} Element;

// Define the periodic table as a 2D array of Element structures
Element table[ROWS][COLS] = {{"H",  "Hydrogen",    1,  1.008}, {"He", "Helium",      2,  4.003},
                             {"Li", "Lithium",     3,  6.941}, {"Be", "Beryllium",  4,  9.012},
                             {"B",  "Boron",       5,  10.81}, {"C",  "Carbon",    6,  12.01},
                             {"N",  "Nitrogen",    7,  14.01}, {"O",  "Oxygen",    8,  16.00},
                             {"F",  "Fluorine",    9,  19.00}, {"Ne", "Neon",      10, 20.18},
                             {"Na", "Sodium",     11,  22.99}, {"Mg", "Magnesium", 12, 24.31},
                             {"Al", "Aluminum",   13, 26.98}, {"Si", "Silicon",   14, 28.09},
                             {"P",  "Phosphorus", 15, 30.97}, {"S",  "Sulfur",    16, 32.06},
                             {"Cl", "Chlorine",   17, 35.45}, {"Ar", "Argon",     18, 39.95}};

// Define a function to shuffle the order of the elements in the quiz
void shuffle_table(Element *arr, size_t n) {
    srand(time(NULL));
    for (int i = 0; i < n - 1; i++) {
        int j = i + rand() / (RAND_MAX / (n - i) + 1);
        Element temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    printf("Welcome to the Periodic Table Quiz!\n\n");
    printf("You will be presented with a symbol or name of an element, and you must provide the corresponding atomic number and atomic mass.\n");
    printf("You will have a total of 10 questions.\n\n");

    // Shuffle the elements in the table
    shuffle_table(table, ROWS * COLS);

    // Define variables to keep track of score and question number
    int score = 0;
    int num_questions = 10;

    // Loop through each question
    for (int i = 1; i <= num_questions; i++) {
        // Generate a random number to determine whether to display symbol or name
        int rand_num = rand() % 2;

        // Determine which element to display
        Element current_element;
        if (rand_num == 0) {
            int rand_row = rand() % ROWS;
            int rand_col = rand() % COLS;
            current_element = table[rand_row][rand_col];
            printf("Question %d: What is the atomic number and atomic mass of the element with the symbol %s?\n", i, current_element.symbol);
        } else {
            int rand_row = rand() % ROWS;
            int rand_col = rand() % COLS;
            current_element = table[rand_row][rand_col];
            printf("Question %d: What is the atomic number and atomic mass of the element with the name %s?\n", i, current_element.name);
        }

        // Get user input for atomic number and atomic mass
        int user_atomic_num;
        float user_atomic_mass;
        printf("Atomic Number: ");
        scanf("%d", &user_atomic_num);
        printf("Atomic Mass: ");
        scanf("%f", &user_atomic_mass);

        // Check if user answered correctly
        if (user_atomic_num == current_element.atomic_num && user_atomic_mass == current_element.atomic_mass) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d and %.3f.\n\n", current_element.atomic_num, current_element.atomic_mass);
        }
    }

    // Display final score
    printf("Quiz complete.\n");
    printf("You answered %d out of %d questions correctly.\n", score, num_questions);

    return 0;
}