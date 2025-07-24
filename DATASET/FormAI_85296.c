//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for each element
struct Element {
    char symbol[3];     // element symbol
    char name[20];      // element name
    int atomic_number;  // atomic number
};

// Function to initialize array of elements
void initialize_elements(struct Element elements[]) {
    strcpy(elements[0].symbol, "H");
    strcpy(elements[0].name, "Hydrogen");
    elements[0].atomic_number = 1;

    strcpy(elements[1].symbol, "He");
    strcpy(elements[1].name, "Helium");
    elements[1].atomic_number = 2;

    // Add more elements here...
    // You can find a full periodic table here for reference:
    // https://www.ptable.com/
}

// Function to print the periodic table
void print_periodic_table(struct Element elements[], int num_elements) {
    printf("Periodic Table:\n");
    printf("%-3s %-20s %s\n", "No", "Symbol", "Name");
    
    for (int i=0; i<num_elements; i++) {
        printf("%-3d %-20s %s\n", elements[i].atomic_number, elements[i].symbol, elements[i].name);
    }
}

// Function for the quiz
void periodic_table_quiz(struct Element elements[], int num_elements) {
    printf("\nPeriodic Table Quiz\n");
    printf("Enter 'q' to quit.\n");

    int score = 0;
    char answer[3];
    
    // Loop through all the elements
    for (int i=0; i<num_elements; i++) {
        printf("What is the symbol for %s? ", elements[i].name);
        scanf("%s", answer);

        // Check if the user wants to quit
        if (strcmp(answer, "q") == 0) {
            break;
        }

        // Check if the answer is correct
        if (strcmp(answer, elements[i].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[i].symbol);
        }
    }

    // Print final score
    printf("Final Score: %d/%d\n", score, num_elements);
}

int main() {
    struct Element elements[118];  // there are 118 known elements
    initialize_elements(elements);
    print_periodic_table(elements, 118);
    periodic_table_quiz(elements, 118);
    return 0;
}