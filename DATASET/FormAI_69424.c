//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    srand(time(NULL)); // Initialize random seed
    char elements[8][3] = { "H ", "Li", "Na", "K ", "Rb", "Cs", "Fr", "He" }; // Array containing elements
    int i;
    int score = 0;
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be given the symbol of an element and you have to enter its name.\n");
    printf("Press 'q' to quit.\n\n");
    while(1) { // Loop forever until user quits
        i = rand() % 8; // Generate a random number from 0 to 7
        printf("What is the name of the element %s?\n", elements[i]);
        char input[3];
        scanf("%s", input);
        if(input[0] == 'q') { // If user quits, exit the program
            break;
        }
        char element[3];
        strcpy(element, elements[i]);
        element[2] = '\0'; // Remove newline character from input
        if(strcmp(input, element) == 0) { // If user input matches the element
            printf("Correct!\n");
            score += 1; // Increase score by 1
        } else {
            printf("Incorrect - the correct answer is %s.\n", element);
        }
        printf("Your current score is %d.\n\n", score);
    }
    printf("Thanks for playing! Your final score is %d.\n", score);
    return 0;
}