//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of elements
#define NUM_ELEMENTS 118

// Define the maximum number of questions
#define MAX_QUESTIONS 10

// Define the structure for an element
typedef struct element {
    int atomic_number;
    char symbol[3];
    char name[30];
    float atomic_weight;
} Element;

// Define the global array of elements
Element elements[NUM_ELEMENTS] = {
    {1, "H",  "Hydrogen",           1.008},
    {2, "He", "Helium",             4.003},
    {3, "Li", "Lithium",            6.941},
    {4, "Be", "Beryllium",          9.012},
    {5, "B",  "Boron",             10.81},
    {6, "C",  "Carbon",            12.01},
    {7, "N",  "Nitrogen",          14.01},
    {8, "O",  "Oxygen",            16.00},
    {9, "F",  "Fluorine",          19.00},
    {10, "Ne", "Neon",             20.18},
    // etc...
};

// Function to generate a random integer within a range
int random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Shuffle the array of elements
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        int j = random_int(0, NUM_ELEMENTS - 1);
        Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }

    // Initialize the variables for the quiz
    int num_correct = 0;
    int num_questions = 0;
    int questions[MAX_QUESTIONS];

    // Display the title and instructions
    printf("C Periodic Table Quiz\n");
    printf("=====================\n");
    printf("You will be asked %d questions about the elements in the periodic table.\n", MAX_QUESTIONS);
    printf("For each question, enter the atomic symbol of the element.\n");
    printf("You will receive a score at the end of the quiz based on the number of correct answers.\n\n");

    // Loop through the desired number of questions
    for (int q = 0; q < MAX_QUESTIONS; q++) {
        // Generate a random question index that hasn't already been asked
        int question_index;
        do {
            question_index = random_int(0, NUM_ELEMENTS - 1);
        } while(questions[0] == question_index || questions[1] == question_index || questions[2] == question_index ||
            questions[3] == question_index || questions[4] == question_index || questions[5] == question_index ||
            questions[6] == question_index || questions[7] == question_index || questions[8] == question_index ||
            questions[9] == question_index);

        // Ask the question and get the user's answer
        printf("Question %d: What is the atomic symbol for %s? ", q + 1, elements[question_index].name);
        char answer[3];
        scanf("%s", answer);

        // Check the answer and update the score
        if (strcasecmp(answer, elements[question_index].symbol) == 0) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[question_index].symbol);
        }

        // Add the question index to the list of asked questions
        questions[q] = question_index;

        // Increment the number of questions asked
        num_questions++;
    }

    // Calculate the score and display the results
    float score = ((float) num_correct / num_questions) * 100;
    printf("\nYou scored %.2f%% on the quiz.\n", score);

    return 0;
}