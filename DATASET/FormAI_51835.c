//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: calm
#include <stdio.h>
#include <string.h>

// Define the maximum size of the element name
#define MAX_NAME_LEN 20

// Define the maximum number of elements in the periodic table
#define MAX_ELEMENTS 118

// Define a struct to hold information about elements
typedef struct {
    char symbol[3];
    char name[MAX_NAME_LEN];
    int atomic_number;
} element;

// Define function to initialize elements
void init_elements(element elements[]) {
    strcpy(elements[0].symbol, "H");
    strcpy(elements[0].name, "Hydrogen");
    elements[0].atomic_number = 1;

    strcpy(elements[1].symbol, "He");
    strcpy(elements[1].name, "Helium");
    elements[1].atomic_number = 2;

    // Continue for all elements
    // ...

    strcpy(elements[117].symbol, "Ts");
    strcpy(elements[117].name, "Tennessine");
    elements[117].atomic_number = 117;
}

// Define function to prompt user for an element symbol
void prompt_for_symbol(char symbol[]) {
    printf("Enter an element symbol: ");
    scanf("%2s", symbol);  // Read in the first 2 characters for the symbol
}

// Define function to find an element by symbol
int find_element_by_symbol(element elements[], char symbol[]) {
    int i;
    for (i = 0; i < MAX_ELEMENTS; i++) {
        if (strcmp(elements[i].symbol, symbol) == 0) {
            return i;
        }
    }
    return -1;
}

// Define main function
int main() {
    // Initialize the elements array
    element elements[MAX_ELEMENTS];
    init_elements(elements);

    // Display instructions
    printf("Welcome to the Periodic Table quiz!\n");
    printf("You will be prompted for an element symbol and asked to enter the corresponding atomic number.\n");

    // Prompt user for 10 symbols
    int i, score = 0;
    char symbol[3];
    for (i = 0; i < 10; i++) {
        prompt_for_symbol(symbol);

        // Find the corresponding element
        int index = find_element_by_symbol(elements, symbol);
        if (index == -1) {
            printf("Sorry, that is not a valid element symbol.\n");
            continue;  // Prompt for another symbol
        }

        // Prompt for atomic number
        int atomic_number;
        printf("What is the atomic number of %s?\n", elements[index].name);
        scanf("%d", &atomic_number);

        // Check if answer is correct
        if (atomic_number == elements[index].atomic_number) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The atomic number of %s is %d.\n", elements[index].name, elements[index].atomic_number);
        }
    }

    // Display final score
    printf("Congratulations, you've completed the quiz!\n");
    printf("Final score: %d/10\n", score);

    return 0;
}