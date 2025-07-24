//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: active
#include <stdio.h>
#include <string.h>

#define MAX_QUIZ_QUESTIONS 10
#define MAX_ANSWER_LENGTH 20

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
} QuizQuestion;

QuizQuestion periodicTableQuestions[MAX_QUIZ_QUESTIONS] = {
    {"What is the symbol for hydrogen?", "H"},
    {"What is the symbol for carbon?", "C"},
    {"What is the symbol for oxygen?", "O"},
    {"What is the symbol for gold?", "Au"},
    {"What is the symbol for silver?", "Ag"},
    {"What is the symbol for lead?", "Pb"},
    {"What is the symbol for iron?", "Fe"},
    {"What is the symbol for nitrogen?", "N"},
    {"What is the symbol for helium?", "He"},
    {"What is the symbol for sodium?", "Na"}
};

int main() {
    int score = 0;
    printf("Welcome to the C Periodic Table Quiz!\n\n");
    printf("Test your knowledge of the periodic table by answering %d questions.\n\n", MAX_QUIZ_QUESTIONS);
    printf("Enter your answers below:\n");
    for(int i = 0; i < MAX_QUIZ_QUESTIONS; i++) {
        char userAnswer[MAX_ANSWER_LENGTH];
        printf("%d. %s\n", i+1, periodicTableQuestions[i].question);
        printf("Answer: ");
        scanf("%s", userAnswer);
        if(strcmp(userAnswer, periodicTableQuestions[i].answer) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", periodicTableQuestions[i].answer);
        }
        printf("\n");
    }
    
    printf("Quiz complete! You scored %d out of %d.\n", score, MAX_QUIZ_QUESTIONS);
    return 0;
}