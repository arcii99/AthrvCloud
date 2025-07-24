//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the size of the periodic table */
#define PT_SIZE 118

/* Define the maximum length of an element name */
#define MAX_NAME_LENGTH 20

/* Function prototypes */
void print_menu(void);
void add_element(int number, char symbol[3], char name[MAX_NAME_LENGTH]);
int read_input(void);
void play_quiz(void);

/* Define the structure for each element */
struct element {
    int number;
    char symbol[3];
    char name[MAX_NAME_LENGTH];
};

/* Define the array of elements */
struct element periodic_table[PT_SIZE];

/* Keep track of how many elements have been added */
int num_elements = 0;

/* Define the quiz questions */
char quiz_questions[5][100] = {
    "What is the symbol for Gold?",
    "What is the atomic number for Lead?",
    "What is the name of element number 8?",
    "What is the symbol for Nitrogen?",
    "What is the atomic number for Calcium?"
};

/* Define the quiz answers */
char quiz_answers[5][MAX_NAME_LENGTH] = {
    "Au",
    "82",
    "Oxygen",
    "N",
    "20"
};

/* Main function */
int main(void) {
    int choice;

    /* Initialize the periodic table */
    add_element(1, "H", "Hydrogen");
    add_element(2, "He", "Helium");
    add_element(3, "Li", "Lithium");
    add_element(4, "Be", "Beryllium");
    add_element(5, "B", "Boron");
    add_element(6, "C", "Carbon");
    add_element(7, "N", "Nitrogen");
    add_element(8, "O", "Oxygen");
    add_element(9, "F", "Fluorine");
    add_element(10, "Ne", "Neon");
    add_element(11, "Na", "Sodium");
    add_element(12, "Mg", "Magnesium");
    add_element(13, "Al", "Aluminum");
    add_element(14, "Si", "Silicon");
    add_element(15, "P", "Phosphorus");
    add_element(16, "S", "Sulfur");
    add_element(17, "Cl", "Chlorine");
    add_element(18, "Ar", "Argon");
    add_element(19, "K", "Potassium");
    add_element(20, "Ca", "Calcium");

    do {
        /* Print the menu */
        print_menu();

        /* Read the user's choice */
        choice = read_input();

        /* Handle the user's choice */
        switch (choice) {
            case 1:
                play_quiz();
                break;
            case 2:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 2);

    return 0;
}

/* Function to print the menu */
void print_menu(void) {
    printf("Welcome to the Medieval Periodic Table Quiz!\n");
    printf("Please choose an option:\n");
    printf("1. Play Quiz\n");
    printf("2. Exit\n");
}

/* Function to add a new element to the periodic table */
void add_element(int number, char symbol[3], char name[MAX_NAME_LENGTH]) {
    /* Check if the array is full */
    if (num_elements >= PT_SIZE) {
        printf("Error: Periodic Table is full!\n");
        exit(EXIT_FAILURE);
    }

    /* Add the new element */
    periodic_table[num_elements].number = number;
    strncpy(periodic_table[num_elements].symbol, symbol, 3);
    strncpy(periodic_table[num_elements].name, name, MAX_NAME_LENGTH);

    /* Increment the number of elements */
    num_elements++;
}

/* Function to read input from the user */
int read_input(void) {
    int choice;
    char input[10];

    /* Read the input */
    fgets(input, 10, stdin);

    /* Convert the input to an integer */
    choice = atoi(input);

    return choice;
}

/* Function to play the quiz */
void play_quiz(void) {
    int i, num_correct = 0;
    char answer[MAX_NAME_LENGTH];

    /* Ask each question */
    for (i = 0; i < 5; i++) {
        printf("%s\n", quiz_questions[i]);
        scanf("%s", answer);

        /* Check the answer */
        if (strcmp(answer, quiz_answers[i]) == 0) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect.\n");
        }
    }

    /* Print the final score */
    printf("You got %d out of 5 correct!\n", num_correct);
}