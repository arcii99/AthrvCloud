//FormAI DATASET v1.0 Category: Online Examination System ; Style: visionary
// Online Examination System Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions and options
#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4

// Define the structure of the question
struct Question {
    char text[100];
    char options[MAX_OPTIONS][50];
    int answer;
};

int main() {
    int numQuestions = 0;
    struct Question questions[MAX_QUESTIONS];

    // Add the first question
    strcpy(questions[0].text, "What is the capital of India?");
    strcpy(questions[0].options[0], "New Delhi");
    strcpy(questions[0].options[1], "Mumbai");
    strcpy(questions[0].options[2], "Kolkata");
    strcpy(questions[0].options[3], "Chennai");
    questions[0].answer = 0;
    numQuestions++;

    // Add the second question
    strcpy(questions[1].text, "What is the largest country in the world?");
    strcpy(questions[1].options[0], "Russia");
    strcpy(questions[1].options[1], "China");
    strcpy(questions[1].options[2], "USA");
    strcpy(questions[1].options[3], "Canada");
    questions[1].answer = 0;
    numQuestions++;

    // Add the third question
    strcpy(questions[2].text, "What is the highest mountain in the world?");
    strcpy(questions[2].options[0], "Mount Everest");
    strcpy(questions[2].options[1], "Mount Kilimanjaro");
    strcpy(questions[2].options[2], "Mount Washington");
    strcpy(questions[2].options[3], "Mount Rushmore");
    questions[2].answer = 0;
    numQuestions++;

    // Add the fourth question
    strcpy(questions[3].text, "Who is the first person to walk on the moon?");
    strcpy(questions[3].options[0], "Neil Armstrong");
    strcpy(questions[3].options[1], "Buzz Aldrin");
    strcpy(questions[3].options[2], "Yuri Gagarin");
    strcpy(questions[3].options[3], "Tim Peake");
    questions[3].answer = 0;
    numQuestions++;

    // Output the instructions to the user
    printf("Welcome to the online examination system. You will be asked %d multiple choice questions. Please select the correct option by typing in the number of the correct answer.\n", numQuestions);

    // Loop through all the questions and ask them one by one
    int score = 0;
    for (int i = 0; i < numQuestions; i++) {
        printf("Question %d: %s\n", i + 1, questions[i].text);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d) %s\n", j + 1, questions[i].options[j]);
        }
        int answer;
        scanf("%d", &answer);
        if (answer - 1 == questions[i].answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! The correct answer is %d) %s\n", questions[i].answer + 1, questions[i].options[questions[i].answer]);
        }
    }

    // Output the final score
    printf("You scored %d out of %d.\n", score, numQuestions);

    return 0;
}