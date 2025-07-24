//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: future-proof
#include <stdio.h>

// Define the number of elements in the periodic table
#define NUM_ELEMENTS 118

// Define the maximum number of attempts allowed in quiz
#define MAX_ATTEMPTS 3

// Define the structure of an element in the periodic table
typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
} Element;

// Define an array of elements in the periodic table
Element periodic_table[NUM_ELEMENTS] = {
    {"H", "Hydrogen", 1},
    {"He", "Helium", 2},
    {"Li", "Lithium", 3},
    {"Be", "Beryllium", 4},
    // Rest of the elements...
    {"Fl", "Flerovium", 114},
    {"Mc", "Moscovium", 115},
    {"Lv", "Livermorium", 116},
    {"Ts", "Tennessine", 117},
    {"Og", "Oganesson", 118}
};

// Define a function to print the periodic table
void print_periodic_table() {
    printf("Periodic Table:\n");
    printf("%-4s | %-12s | %s\n", "No", "Symbol", "Name");
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        printf("%-4d | %-12s | %s\n", periodic_table[i].atomic_number,
               periodic_table[i].symbol, periodic_table[i].name);
    }
}

// Define the main function
int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Print the periodic table
    print_periodic_table();

    int score = 0; // Initialize the score to 0
    int attempts = 0; // Initialize the number of attempts to 0
    
    // Loop until the maximum number of attempts is reached
    while (attempts < MAX_ATTEMPTS) {
        // Generate random index of an element in the periodic table
        int index = rand() % NUM_ELEMENTS;
        
        // Print the symbol and prompt the user to enter the name of the element
        printf("\nWhat is the name of the element with symbol %s?\n", 
               periodic_table[index].symbol);
        char answer[20];
        scanf("%s", answer);
        
        // Check if the answer is correct and update the score
        if (strcmp(answer, periodic_table[index].name) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", periodic_table[index].name);
        }
        
        // Increment the number of attempts
        attempts++;
    }
    
    // Print the final score
    printf("\nYour score is %d out of %d.\n", score, MAX_ATTEMPTS);
    
    return 0;
}