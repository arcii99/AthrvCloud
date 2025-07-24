//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Array to store Element Name, Symbol, and Atomic Mass
char elements[118][3][20] = {
	{"Hydrogen", "H", "1.008"},
	{"Helium", "He", "4.003"},
	{"Lithium", "Li", "6.941"},
	{"Beryllium", "Be", "9.012"},
	{"Boron", "B", "10.81"},
	{"Carbon", "C", "12.01"},
	{"Nitrogen", "N", "14.01"},
	{"Oxygen", "O", "16.00"},
	{"Fluorine", "F", "19.00"},
	{"Neon", "Ne", "20.18"},
    // Omitted for brevity
};

// Function to display the periodic table
void display_periodic_table() {
    printf("\n\n***************************************\n");
    printf("*            PERIODIC TABLE            *\n");
    printf("***************************************\n\n");
    printf("Atomic No.\tSymbol\t\tName\n");
    printf("----------\t------\t\t----\n");

    // Loop through elements and print their details
    for (int i = 0; i < 118; i++) {
        printf("%-2d\t\t%-2s\t\t%-10s\n", i+1, elements[i][1], elements[i][0]);
    }
}

// Function to get the answer to a question
char* get_answer(char *question) {
    printf("\n%s\n", question);
    char *answer = (char*) malloc(20);
    scanf("%s", answer);
    return answer;
}

// Main Function
int main() {
    char *symbol;
    float atomic_mass, user_mass;
    int index, num_questions = 5;
    int correct_answers = 0;

    // Display the periodic table
    display_periodic_table();

    // Ask the user a series of questions
    for (int i = 0; i < num_questions; i++) {
        // Get a random element from the periodic table
        index = rand() % 118;
        symbol = elements[index][1];
        atomic_mass = atof(elements[index][2]);

        // Ask the user to input the name of this element
        char *user_answer = get_answer("What is the name or symbol for this element?");
        
        // Check if the user's answer is correct
        if (strcmp(user_answer, elements[index][0]) == 0 || strcmp(user_answer, symbol) == 0) {
            printf("\nCorrect!\n");
            correct_answers++;
        } else {
            printf("\nIncorrect!\n");
        }

        // Get the atomic mass of the element from the user
        if (correct_answers > 0) {
            char *mass_question = (char*) malloc(50);
            sprintf(mass_question, "What is the atomic mass of %s (to two decimal places)?", elements[index][0]);
            user_mass = atof(get_answer(mass_question));
            free(mass_question);

            // Check if the user's answer is correct
            if (user_mass == atomic_mass) {
                printf("\nCorrect!\n");
                correct_answers++;
            } else {
                printf("\nIncorrect!\n");
            }
        }

        free(user_answer);
    }

    // Display final score
    printf("\n\n**************************************\n");
    printf("*             FINAL SCORE             *\n");
    printf("**************************************\n");
    printf("Correct Answers: %d\n", correct_answers);
    printf("Incorrect Answers: %d\n", num_questions - correct_answers);
    printf("Percentage Score: %.2f%%\n", ((float) correct_answers / num_questions) * 100);

    return 0;
}