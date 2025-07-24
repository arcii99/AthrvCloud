//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of the element
struct Element {
    int atomic_number;
    char symbol[3];
    char name[30];
    float atomic_mass;
} periodic_table[118]; //Define an array of 118 elements

int main() {

    // Populate the periodic_table array with elements
    periodic_table[0] = (struct Element) {1, "H", "Hydrogen", 1.008};
    periodic_table[1] = (struct Element) {2, "He", "Helium", 4.003};
   
    // Do this for all 118 elements

    // Define variables for user input 
    char input[10];
    int user_answer;
    int score = 0;

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be presented with 10 randomly generated elements and asked to provide its atomic number\n");
    printf("Are you ready to start? (yes/no)\n");

    // Get user input to start the quiz
    fgets(input, 10, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character from input

    if (strcmp(input, "yes") == 0) {
        printf("\nGreat! Let's get started.\n");
        printf("---------------------------\n");

        for (int i = 0; i < 10; i++) {
            // Generate a random element from the periodic_table
            int random_index = rand() % 118;
            struct Element random_element = periodic_table[random_index];

            // Present the user with the symbol and name of the element
            printf("What is the atomic number of %s (%s)? ", random_element.symbol, random_element.name);

            // Get user input for the atomic number and convert it to an integer
            fgets(input, 10, stdin);
            user_answer = atoi(input);

            // Check if user_answer matches the correct atomic number of the element
            if (user_answer == random_element.atomic_number) {
                printf("Correct!\n");
                score++;
            } else {
                printf("Incorrect. The correct answer is %d\n", random_element.atomic_number);
            }

            printf("---------------------------\n");
        }

        printf("Your final score is %d/10. Thanks for playing!\n", score);
    } else {
        printf("Okay, maybe next time.\n");
    }

    return 0;
}