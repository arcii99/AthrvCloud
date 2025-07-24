//FormAI DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 50
#define MAX_OPTIONS 4
#define MAX_ANSWER_LENGTH 100

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char options[MAX_OPTIONS][MAX_ANSWER_LENGTH];
    int correct;
} Question;

void display_question(Question q) {
    printf("%s\n", q.question);
    for(int i = 0; i < MAX_OPTIONS; i++) {
        printf("%d. %s\n", i+1, q.options[i]);
    }
    printf("Enter your answer (1-%d): ", MAX_OPTIONS);
}

int main() {
    Question questions[MAX_QUESTIONS];
    int num_questions;
    char input[MAX_ANSWER_LENGTH];
    int score = 0;

    printf("C Programming Online Examination\n");
    printf("Please enter the number of questions: ");
    fgets(input, MAX_ANSWER_LENGTH, stdin);
    num_questions = atoi(input);
    if(num_questions > MAX_QUESTIONS) {
        printf("Sorry, the maximum number of questions is %d.\n", MAX_QUESTIONS);
        exit(1);
    }

    for(int i = 0; i < num_questions; i++) {
        printf("Question %d:\n", i+1);

        printf("Enter the question: ");
        fgets(questions[i].question, MAX_ANSWER_LENGTH, stdin);
        questions[i].question[strcspn(questions[i].question, "\n")] = 0;

        for(int j = 0; j < MAX_OPTIONS; j++) {
            printf("Enter option %d: ", j+1);
            fgets(questions[i].options[j], MAX_ANSWER_LENGTH, stdin);
            questions[i].options[j][strcspn(questions[i].options[j], "\n")] = 0;
        }

        printf("Enter the correct answer (1-%d): ", MAX_OPTIONS);
        fgets(input, MAX_ANSWER_LENGTH, stdin);
        questions[i].correct = atoi(input) - 1;
    }

    printf("You will now be presented with %d questions. Good luck!\n", num_questions);

    for(int i = 0; i < num_questions; i++) {
        int answer;
        display_question(questions[i]);
        fgets(input, MAX_ANSWER_LENGTH, stdin);
        answer = atoi(input) - 1;

        if(answer == questions[i].correct) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Sorry, the correct answer was: %d. %s\n", questions[i].correct+1, questions[i].options[questions[i].correct]);
        }
    }

    printf("Congratulations, you have completed the exam! Your score is: %d/%d\n", score, num_questions);

    return 0;
}