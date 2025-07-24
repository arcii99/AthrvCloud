//FormAI DATASET v1.0 Category: Online Examination System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char question[50];
    char optionA[20];
    char optionB[20];
    char optionC[20];
    char optionD[20];
    char correctAnswer[20];
};

int main() {
    int i, j, score = 0;
    struct Question questions[5];

    // Manually inputting questions and answers
    strcpy(questions[0].question, "What is the capital of India?");
    strcpy(questions[0].optionA, "New Delhi");
    strcpy(questions[0].optionB, "Mumbai");
    strcpy(questions[0].optionC, "Kolkata");
    strcpy(questions[0].optionD, "Bangalore");
    strcpy(questions[0].correctAnswer, "a");

    strcpy(questions[1].question, "What is the largest state in the USA?");
    strcpy(questions[1].optionA, "Alaska");
    strcpy(questions[1].optionB, "Texas");
    strcpy(questions[1].optionC, "California");
    strcpy(questions[1].optionD, "Hawaii");
    strcpy(questions[1].correctAnswer, "a");

    strcpy(questions[2].question, "What is the tallest mountain in Africa?");
    strcpy(questions[2].optionA, "Kilimanjaro");
    strcpy(questions[2].optionB, "Mount Kenya");
    strcpy(questions[2].optionC, "Mount Elgon");
    strcpy(questions[2].optionD, "Mount Meru");
    strcpy(questions[2].correctAnswer, "a");

    strcpy(questions[3].question, "Which country hosts the world's largest carnival?");
    strcpy(questions[3].optionA, "Brazil");
    strcpy(questions[3].optionB, "USA");
    strcpy(questions[3].optionC, "Germany");
    strcpy(questions[3].optionD, "India");
    strcpy(questions[3].correctAnswer, "a");

    strcpy(questions[4].question, "Who discovered the first antibiotic?");
    strcpy(questions[4].optionA, "Alexander Fleming");
    strcpy(questions[4].optionB, "Robert Koch");
    strcpy(questions[4].optionC, "Louis Pasteur");
    strcpy(questions[4].optionD, "Joseph Lister");
    strcpy(questions[4].correctAnswer, "a");

    printf("==== Welcome to the Online Examination System ====\n\n");

    // Loop through each question
    for (i = 0; i < 5; i++) {
        printf("Question %d: %s\n", i+1, questions[i].question);
        printf("A: %s\n", questions[i].optionA);
        printf("B: %s\n", questions[i].optionB);
        printf("C: %s\n", questions[i].optionC);
        printf("D: %s\n", questions[i].optionD);

        // Get user's answer
        char answer[1];
        printf("\nEnter your answer: ");
        scanf("%s", answer);

        // Check if answer is correct and update score
        if (strcasecmp(answer, questions[i].correctAnswer) == 0) {
            printf("\nCorrect!\n");
            score++;
        } else {
            printf("\nIncorrect. The correct answer is %s\n", questions[i].correctAnswer);
        }
    }

    // Display final score
    printf("\n====== Final Score ======\n");
    printf("%d out of 5", score);

    return 0;
}