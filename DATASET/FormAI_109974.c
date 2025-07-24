//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: portable
#include <stdio.h>
#include <string.h>

// define maximum length for input values
#define MAX_INPUT_LENGTH 30

int main() {
    // declare variables
    char userInput[MAX_INPUT_LENGTH];
    char correctAnswer[] = "Carbon";
    int attempts = 0;
    int correct = 0;

    // greet user and provide instructions
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be given the symbol for an element and you must guess its name.\n");
    printf("You have 3 attempts per question.\n");

    // loop through quiz questions
    char symbol[] = "C";
    for(int i=1; i<=10; i++) {
        printf("\nQuestion %d:\n", i);

        // prompt user for input
        printf("What is the name of the element with symbol %s? ", symbol);
        fgets(userInput, MAX_INPUT_LENGTH, stdin);
        userInput[strcspn(userInput, "\n")] = 0; // remove newline character from input

        // check if user input is correct
        attempts = 1;
        while (strcmp(userInput, correctAnswer) != 0 && attempts <= 3) {
            printf("Incorrect. Try again (%d of 3): ", attempts);
            fgets(userInput, MAX_INPUT_LENGTH, stdin);
            userInput[strcspn(userInput, "\n")] = 0; // remove newline character from input
            attempts++;
        }

        // check if user input is correct
        if (strcmp(userInput, correctAnswer) == 0) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", correctAnswer);
        }

        // reset user input for next question
        memset(userInput, 0, sizeof(userInput));
        
        // select next symbol
        switch(i) {
            case 1:
                symbol[0] = 'N';
                correctAnswer[0] = 'Nitrogen';
                break;
            case 2:
                symbol[0] = 'O';
                correctAnswer[0] = 'Oxygen';
                break;
            case 3:
                symbol[0] = 'H';
                correctAnswer[0] = 'Hydrogen';
                break;
            case 4:
                symbol[0] = 'He';
                correctAnswer[0] = 'Helium';
                break;
            case 5:
                symbol[0] = 'Ne';
                correctAnswer[0] = 'Neon';
                break;
            case 6:
                symbol[0] = 'Na';
                correctAnswer[0] = 'Sodium';
                break;
            case 7:
                symbol[0] = 'Mg';
                correctAnswer[0] = 'Magnesium';
                break;
            case 8:
                symbol[0] = 'Al';
                correctAnswer[0] = 'Aluminium';
                break;
            case 9:
                symbol[0] = 'Si';
                correctAnswer[0] = 'Silicon';
                break;
            case 10:
                symbol[0] = 'P';
                correctAnswer[0] = 'Phosphorus';
                break;
        }
    }

    // display quiz results
    printf("\nQuiz Completed!\n");
    printf("You got %d out of 10 correct.\n", correct);

    return 0;
}