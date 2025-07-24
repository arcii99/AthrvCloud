//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: paranoid
#include <stdio.h>
#include <string.h>

int checkAnswer(char userAnswer[], char correctAnswer[]) {
    if (strcmp(userAnswer, correctAnswer) == 0) {
        printf("Correct! You didn't get anything wrong, right?\n");
        return 1;
    } else {
        printf("Wrong! Are you sure you studied enough?\n");
        return 0;
    }
}

int main() {
    char answer[50];
    char elementSymbol[][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca"};
    char elementName[][20] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium"};
    char correctAnswer[][20] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Boron", "Carbon", "Nitrogen", "Oxygen", "Fluorine", "Neon", "Sodium", "Magnesium", "Aluminum", "Silicon", "Phosphorus", "Sulfur", "Chlorine", "Argon", "Potassium", "Calcium"};
    int score=0, i, numQuestions=5;
    
    printf("Welcome to the Paranoid Periodic Table Quiz!\n");
    printf("We will ask you %d questions about the periodic table.\n", numQuestions);
    printf("Are you ready? Let's begin:\n\n");
    
    for (i = 0; i < numQuestions; i++) {
        int randomIndex = rand() % 20;
        printf("What is the name of the element with the symbol %s?\n", elementSymbol[randomIndex]);
        scanf("%s", answer);
        score+=checkAnswer(answer, correctAnswer[randomIndex]);
    }
    printf("\nYour score is: %d/%d\n", score, numQuestions);
    
    if (score == numQuestions) {
        printf("Hey, you got a perfect score! Congratulations, you must have studied really hard.\n");
    } else if (score >= numQuestions/2) {
        printf("Good job, you passed the quiz!\n");
    } else {
        printf("Sorry, you didn't pass the quiz. Better luck next time!\n");
    }
    
    return 0;
}