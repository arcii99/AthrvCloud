//FormAI DATASET v1.0 Category: Online Examination System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// function to get the questions from file
void getQuestions(char *filename) {
    FILE *file = fopen(filename, "r");
    char question[256];
    char option1[64], option2[64], option3[64];
    char correct_answer[64];

    if(file) {
        while(fgets(question, sizeof(question), file) != NULL) {
            printf("%s", question);
            fgets(option1, sizeof(option1), file);
            printf("A. %s", option1);
            fgets(option2, sizeof(option2), file);
            printf("B. %s", option2);
            fgets(option3, sizeof(option3), file);
            printf("C. %s", option3);
            fgets(correct_answer, sizeof(correct_answer), file);
            printf("Enter your answer (A/B/C): ");
            char answer[2];
            scanf("%s", answer);
            if(answer[0] == correct_answer[0]) {
                printf("Correct answer!\n\n");
            } else {
                printf("Incorrect answer!\n\n");
            }
        }
    } else {
        printf("Cannot open file.\n");
    }

    fclose(file);
}

int main() {
    printf("Welcome to the C Online Examination System!\n\n");
    printf("You will be asked 5 multiple choice questions. Answer the questions\n");
    printf("by entering A, B or C. Good luck!\n\n");
    getQuestions("questions.txt");

    return 0;
}