//FormAI DATASET v1.0 Category: Online Examination System ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct question {
    char question[100];
    char optionA[50];
    char optionB[50];
    char optionC[50];
    char optionD[50];
    int answer;
};

struct student {
    char name[50];
    int score;
};

int main() {
    struct question questions[5];
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].optionA, "Berlin");
    strcpy(questions[0].optionB, "London");
    strcpy(questions[0].optionC, "Paris");
    strcpy(questions[0].optionD, "New York");
    questions[0].answer = 3;

    strcpy(questions[1].question, "What is the largest organ in the human body?");
    strcpy(questions[1].optionA, "Heart");
    strcpy(questions[1].optionB, "Lungs");
    strcpy(questions[1].optionC, "Liver");
    strcpy(questions[1].optionD, "Skin");
    questions[1].answer = 4;

    strcpy(questions[2].question, "What is the name of the biggest planet in our solar system?");
    strcpy(questions[2].optionA, "Earth");
    strcpy(questions[2].optionB, "Mars");
    strcpy(questions[2].optionC, "Jupiter");
    strcpy(questions[2].optionD, "Saturn");
    questions[2].answer = 3;

    strcpy(questions[3].question, "Who invented the telephone?");
    strcpy(questions[3].optionA, "Alexander Graham Bell");
    strcpy(questions[3].optionB, "Thomas Edison");
    strcpy(questions[3].optionC, "Nikola Tesla");
    strcpy(questions[3].optionD, "Benjamin Franklin");
    questions[3].answer = 1;

    strcpy(questions[4].question, "What is the most spoken language in the world?");
    strcpy(questions[4].optionA, "Spanish");
    strcpy(questions[4].optionB, "Mandarin");
    strcpy(questions[4].optionC, "English");
    strcpy(questions[4].optionD, "Hindi");
    questions[4].answer = 2;

    struct student students[10];
    int i, j;
    for (i = 0; i < 10; i++) {
        printf("Enter your name: ");
        scanf("%s", students[i].name);
        students[i].score = 0;
        printf("\nWelcome %s, let's get started!\n\n", students[i].name);
        for (j = 0; j < 5; j++) {
            printf("%s\n", questions[j].question);
            printf("A. %s\n", questions[j].optionA);
            printf("B. %s\n", questions[j].optionB);
            printf("C. %s\n", questions[j].optionC);
            printf("D. %s\n", questions[j].optionD);
            printf("Your answer: ");
            char answer[2];
            scanf("%s", answer);
            if (answer[0] == 'A' || answer[0] == 'a') {
                if (questions[j].answer == 1) students[i].score++;
            }
            else if (answer[0] == 'B' || answer[0] == 'b') {
                if (questions[j].answer == 2) students[i].score++;
            }
            else if (answer[0] == 'C' || answer[0] == 'c') {
                if (questions[j].answer == 3) students[i].score++;
            }
            else if (answer[0] == 'D' || answer[0] == 'd') {
                if (questions[j].answer == 4) students[i].score++;
            }
            printf("\n");
        }
    }
    printf("\n\nResults:\n\n");
    for (i = 0; i < 10; i++) {
        printf("%s's score: %d\n", students[i].name, students[i].score);
    }
    return 0;
}