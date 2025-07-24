//FormAI DATASET v1.0 Category: Online Examination System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct {
    char question[100];
    char options[MAX_ANSWERS][50];
    int correct_answer;
} Question;

Question questions[MAX_QUESTIONS];

int score = 0;

void load_questions();
int take_test();
void print_result();

int main() {
    load_questions();
    score = take_test();
    print_result();
    return 0;
}

void load_questions() {
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].options[0], "A. London");
    strcpy(questions[0].options[1], "B. Paris");
    strcpy(questions[0].options[2], "C. New York");
    strcpy(questions[0].options[3], "D. Sydney");
    questions[0].correct_answer = 1;

    // Add more questions here
    // ...

    printf("Questions loaded!\n");
}

int take_test() {
    int i, answer;
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nQuestion %d: %s\n", i+1, questions[i].question);
        printf("%s\n", questions[i].options[0]);
        printf("%s\n", questions[i].options[1]);
        printf("%s\n", questions[i].options[2]);
        printf("%s\n", questions[i].options[3]);
        printf("Enter your answer (A-D): ");
        
        answer = getchar();
        fflush(stdin);
        answer = toupper(answer) - 'A'; // Convert user's input to index
        
        while (answer < 0 || answer > 3) {
            printf("Invalid answer. Enter again (A-D): ");
            answer = getchar();
            fflush(stdin);
            answer = toupper(answer) - 'A';
        }
        
        if (answer == questions[i].correct_answer - 1) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %s.\n", questions[i].options[questions[i].correct_answer-1]);
        }
    }
    return score;
}

void print_result() {
    printf("\n\nYour score is %d/%d.\n", score, MAX_QUESTIONS);
    if (score < MAX_QUESTIONS/2) {
        printf("You need to study harder!\n");
    } else {
        printf("Good job!\n");
    }
}