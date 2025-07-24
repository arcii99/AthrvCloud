//FormAI DATASET v1.0 Category: Online Examination System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct question {
    char question_text[1000];
    char options[4][1000];
    int correct_option;
} questions[10];

int main() {
    int score = 0;
    printf("Welcome to the Online Examination System\n\n");

    // Load questions from file
    FILE *fp;
    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char line[500];
    int current_question = 0;
    int current_option = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strcmp(line, "\n") == 0) {
            current_question++;
            current_option = 0;
            continue;
        }

        if (current_option == 0) {
            strcpy(questions[current_question].question_text, line);
        } else {
            strcpy(questions[current_question].options[current_option - 1], line);
        }

        if (strstr(line, "*") != NULL) {
            questions[current_question].correct_option = current_option;
        }

        current_option++;
    }

    fclose(fp);

    // Ask questions
    for (int i = 0; i < 10; i++) {
        printf("%s\n", questions[i].question_text);

        for (int j = 0; j < 4; j++) {
            printf("%d. %s", j + 1, questions[i].options[j]);
        }

        int answer;
        printf("Enter answer: ");
        scanf("%d", &answer);
        fflush(stdin);

        if (answer == questions[i].correct_option) {
            printf("Correct!\n");
            score += 10;
        } else {
            printf("Wrong! The correct answer is option %d\n", questions[i].correct_option);
        }
    }

    printf("Your score is %d\n\n", score);
    return 0;
}