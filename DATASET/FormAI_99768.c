//FormAI DATASET v1.0 Category: Online Examination System ; Style: unmistakable
#include <stdio.h>
#include <string.h>

struct Question {
    char question[100];
    char options[4][50];
    int correct_answer;
};

void display_question(struct Question q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d) %s\n", i+1, q.options[i]);
    }
}

int main() {
    struct Question questions[5];
    strcpy(questions[0].question, "What is the capital of India?");
    strcpy(questions[0].options[0], "Mumbai");
    strcpy(questions[0].options[1], "Delhi");
    strcpy(questions[0].options[2], "Chennai");
    strcpy(questions[0].options[3], "Kolkata");
    questions[0].correct_answer = 2;

    strcpy(questions[1].question, "What is the biggest animal in the world?");
    strcpy(questions[1].options[0], "Elephant");
    strcpy(questions[1].options[1], "Whale");
    strcpy(questions[1].options[2], "Giraffe");
    strcpy(questions[1].options[3], "Hippo");
    questions[1].correct_answer = 2;

    strcpy(questions[2].question, "What is the smallest country in the world?");
    strcpy(questions[2].options[0], "India");
    strcpy(questions[2].options[1], "China");
    strcpy(questions[2].options[2], "Vatican City");
    strcpy(questions[2].options[3], "Mexico");
    questions[2].correct_answer = 3;

    strcpy(questions[3].question, "What is the largest organ in the human body?");
    strcpy(questions[3].options[0], "Heart");
    strcpy(questions[3].options[1], "Liver");
    strcpy(questions[3].options[2], "Kidneys");
    strcpy(questions[3].options[3], "Skin");
    questions[3].correct_answer = 4;

    strcpy(questions[4].question, "What is the first element on the periodic table?");
    strcpy(questions[4].options[0], "Oxygen");
    strcpy(questions[4].options[1], "Carbon");
    strcpy(questions[4].options[2], "Hydrogen");
    strcpy(questions[4].options[3], "Helium");
    questions[4].correct_answer = 3;

    int score = 0;
    int selected_answer;
    printf("Welcome to the Online Examination System!\n");
    printf("You will be presented with 5 multiple choice questions.\n");
    printf("Choose the correct option to score points.\n");
    for (int i = 0; i < 5; i++) {
        printf("Question %d\n", i+1);
        display_question(questions[i]);
        printf("Enter your answer (1-4): ");
        scanf("%d", &selected_answer);
        if (selected_answer == questions[i].correct_answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is option %d.\n", questions[i].correct_answer);
        }
    }
    printf("Your final score is %d/5.\n", score);
    printf("Thank you for taking the exam!\n");

    return 0;
}