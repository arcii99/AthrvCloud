//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for the number of elements and the maximum length of element names
#define NUM_ELEMENTS 118
#define MAX_NAME_LENGTH 20

// Define a struct to store information about an element
typedef struct {
    char name[MAX_NAME_LENGTH];
    char symbol[3];
    int atomic_number;
    double atomic_weight;
} element;

// Function prototypes
int parse_int_input(char* input);
void print_table(element* table, int num_elements);
void quiz_user(element* table, int num_elements);

int main() {
    // Create an array of elements
    element table[NUM_ELEMENTS];

    // Fill the table with data from a file
    FILE* file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: Failed to open file\n");
        return 1;
    }

    char line[100];
    char* token;
    int i = 0;
    while (fgets(line, 100, file) != NULL) {
        token = strtok(line, "\t");
        strcpy(table[i].name, token);
        token = strtok(NULL, "\t");
        strcpy(table[i].symbol, token);
        token = strtok(NULL, "\t");
        table[i].atomic_number = atoi(token);
        token = strtok(NULL, "\t");
        table[i].atomic_weight = atof(token);
        i++;
    }
    fclose(file);

    // Print a table of the elements
    print_table(table, NUM_ELEMENTS);

    // Allow the user to take a quiz on the elements
    quiz_user(table, NUM_ELEMENTS);

    return 0;
}

// Parses a string input as an integer, returning -1 if invalid
int parse_int_input(char* input) {
    int value = -1;
    if (sscanf(input, "%d", &value) != 1) {
        value = -1;
    }
    return value;
}

// Prints a table of elements
void print_table(element* table, int num_elements) {
    printf("Name\tSymbol\tAtomic Number\tAtomic Weight\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%s\t%s\t%d\t\t%.4lf\n", table[i].name, table[i].symbol, table[i].atomic_number, table[i].atomic_weight);
    }
}

// Quizzes the user on the elements, repeating until the user enters "quit"
void quiz_user(element* table, int num_elements) {
    char input[20];
    int correct = 0;
    int incorrect = 0;

    while (1) {
        // Generate a random index for an element in the table
        int index = rand() % num_elements;

        // Print the symbol and prompt the user for the element name
        printf("%s\n", table[index].symbol);
        printf("Enter the name of the element (or 'quit'): ");
        fgets(input, 20, stdin);
        // Remove the newline character at the end of the input
        input[strlen(input) - 1] = '\0';

        // Check if the user wants to quit
        if (strcmp(input, "quit") == 0) {
            break;
        }

        // Check if the user's answer is correct
        if (strcmp(input, table[index].name) == 0) {
            printf("Correct!\n");
            correct++;
        }
        else {
            printf("Incorrect. The correct answer is %s.\n", table[index].name);
            incorrect++;
        }
    }

    // Print the user's score
    printf("\nQuiz complete. Score: %d/%d\n", correct, correct + incorrect);
}