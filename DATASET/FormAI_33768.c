//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum number of questions in the quiz
#define MAX_QUESTIONS 10

// Define the maximum length of the element symbol
#define MAX_SYMBOL_LEN 3

// Define the maximum length of the element name
#define MAX_NAME_LEN 50

// Define a structure to store each element in the periodic table
struct Element {
    char symbol[MAX_SYMBOL_LEN];
    char name[MAX_NAME_LEN];
    int atomic_number;
};

// Define an array to store all the elements of the periodic table
struct Element elements[] = {
    {"H", "Hydrogen", 1},
    {"He", "Helium", 2},
    {"Li", "Lithium", 3},
    {"Be", "Beryllium", 4},
    {"B", "Boron", 5},
    {"C", "Carbon", 6},
    {"N", "Nitrogen", 7},
    {"O", "Oxygen", 8},
    {"F", "Fluorine", 9},
    {"Ne", "Neon", 10},
    {"Na", "Sodium", 11},
    {"Mg", "Magnesium", 12},
    {"Al", "Aluminium", 13},
    {"Si", "Silicon", 14},
    {"P", "Phosphorus", 15},
    {"S", "Sulfur", 16},
    {"Cl", "Chlorine", 17},
    {"Ar", "Argon", 18},
    {"K", "Potassium", 19},
    {"Ca", "Calcium", 20},
    // Add more elements if desired...
};

// Define the number of elements in the periodic table
const int num_elements = sizeof(elements) / sizeof(elements[0]);

// Define a function to generate a random number within a given range
int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Define a function to shuffle an array of integers
void shuffle_array(int arr[], int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    // Initialize the random number generator with the current time
    srand(time(NULL));
    
    // Generate a random sequence of question indices
    int question_indices[MAX_QUESTIONS];
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        question_indices[i] = get_random_number(0, num_elements - 1);
    }
    shuffle_array(question_indices, MAX_QUESTIONS);
    
    // Display a welcome message and instructions for the quiz
    printf("Welcome to the Periodic Table Quiz! You will be asked %d questions.\n", MAX_QUESTIONS);
    printf("Type the atomic symbol of the element and press Enter to submit your answer.\n");
    printf("Press Enter without typing anything to skip a question.\n");
    printf("Let's get started!\n\n");
    
    // Iterate over the question indices and ask each question
    int correct_answers = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        struct Element element = elements[question_indices[i]];
        
        // Ask the question and get the user's input
        printf("Question %d: What is the atomic symbol of %s?\n", i + 1, element.name);
        char answer[MAX_SYMBOL_LEN];
        fgets(answer, MAX_SYMBOL_LEN, stdin);
        strtok(answer, "\n"); // Remove the newline character
        
        // Check the user's answer
        if (strlen(answer) == 0) {
            printf("You skipped this question.\n\n");
        } else if (strcmp(answer, element.symbol) == 0) {
            printf("Correct!\n\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is %s.\n\n", element.symbol);
        }
    }
    
    // Display the quiz results
    printf("Quiz complete! You answered %d out of %d questions correctly.\n", correct_answers, MAX_QUESTIONS);
    
    // Exit the program
    return 0;
}