//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateQuiz() {
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("You will be given a symbol, and you must enter the corresponding element name.\n");
    printf("Let's begin with some easy ones.\n");
    
    // Easy questions
    char symbols[10][3] = {"H", "He", "Li", "Be", "Na", "Mg", "K", "Ca", "Fe", "Cu"};
    char answers[10][20] = {"Hydrogen", "Helium", "Lithium", "Beryllium", "Sodium", "Magnesium", "Potassium", "Calcium", "Iron", "Copper"};
    int score = 0;
    
    for (int i = 0; i < 10; i++) {
        printf("%s: ", symbols[i]);
        char userAnswer[20];
        fgets(userAnswer, 20, stdin);
        userAnswer[strcspn(userAnswer, "\n")] = 0;
        if (strcmp(userAnswer, answers[i]) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %s.\n", answers[i]);
        }
    }
    
    printf("You got %d out of 10 correct.\n", score);
    
    if (score >= 8) {
        printf("Excellent job! You really know your chemistry!\n");
    } else if (score >= 6) {
        printf("Not bad, but you could use some improvement.\n");
    } else {
        printf("Ouch, you really need to study up on your periodic table.\n");
    }
    
    printf("Thanks for playing the C Periodic Table Quiz!\n");
}

int main() {
    generateQuiz();
    return 0;
}