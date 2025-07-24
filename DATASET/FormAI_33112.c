//FormAI DATASET v1.0 Category: Online Examination System ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Define the maximum number of questions in the exam */
#define MAX_QUESTIONS 10

/* Define the maximum length of question and answer strings */
#define MAX_LENGTH 100

/* Define a structure to hold each question and answer */
typedef struct {
    char question[MAX_LENGTH];
    char answer[MAX_LENGTH];
} Question;

/* Function to display the exam instructions */
void display_instructions() {
    printf("Welcome to the Online Exam System!\n");
    printf("You will be presented with %d multiple choice questions.\n", MAX_QUESTIONS);
    printf("Type in the letter of the correct answer and press enter.\n");
    printf("Good luck!\n");
    printf("----------------------------------\n\n");
}

/* Function to display a single question and get the user's answer */
char get_answer(Question q) {
    printf("%s\n", q.question);
    printf("a) %s\n", q.answer);
    printf("b) %s\n", q.answer);
    printf("c) %s\n", q.answer);
    printf("d) %s\n", q.answer);
    printf("Please enter your answer (a, b, c, or d): ");

    char answer;
    scanf(" %c", &answer);

    return answer;
}

/* Function to grade the exam and display the results */
void grade_exam(Question questions[], char answers[]) {
    int num_correct = 0;

    for(int i = 0; i < MAX_QUESTIONS; i++) {
        if(answers[i] == questions[i].answer[0]) {
            num_correct++;
        }
    }

    printf("----------------------------------\n");
    printf("You answered %d out of %d questions correctly.\n", num_correct, MAX_QUESTIONS);
    printf("Your score is %.2f%%\n", ((float)num_correct/MAX_QUESTIONS) * 100);
}

int main() {
    /* Create the exam questions */
    Question questions[MAX_QUESTIONS];
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].answer, "Paris");
    strcpy(questions[1].question, "What is the largest country in the world by land area?");
    strcpy(questions[1].answer, "Russia");
    strcpy(questions[2].question, "What is the boiling point of water in degrees Celsius?");
    strcpy(questions[2].answer, "100");
    strcpy(questions[3].question, "What is the symbol for Sodium on the periodic table?");
    strcpy(questions[3].answer, "Na");
    strcpy(questions[4].question, "What is the highest mountain in the world?");
    strcpy(questions[4].answer, "Mt. Everest");
    strcpy(questions[5].question, "What is the name of the force that keeps planets in orbit around the sun?");
    strcpy(questions[5].answer, "Gravity");
    strcpy(questions[6].question, "What is the smallest country in the world by land area?");
    strcpy(questions[6].answer, "Vatican City");
    strcpy(questions[7].question, "What is the chemical formula for water?");
    strcpy(questions[7].answer, "H2O");
    strcpy(questions[8].question, "What is the name of the currency used in Japan?");
    strcpy(questions[8].answer, "Yen");
    strcpy(questions[9].question, "What is the name of the largest ocean on Earth?");
    strcpy(questions[9].answer, "Pacific Ocean");

    /* Create an array to hold the user's answers */
    char answers[MAX_QUESTIONS];

    /* Display the exam instructions */
    display_instructions();

    /* Get the user's answers to each question */
    for(int i = 0; i < MAX_QUESTIONS; i++) {
        answers[i] = get_answer(questions[i]);
    }

    /* Grade the exam and display the results */
    grade_exam(questions, answers);

    return 0;
}