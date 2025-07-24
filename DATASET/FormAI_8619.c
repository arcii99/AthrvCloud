//FormAI DATASET v1.0 Category: Online Examination System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

/* Define the number of questions */
#define NUM_QUESTIONS 10

/* Define the allowable time for exam in minutes */
#define EXAM_TIME 30

/* Define the exam questions and answers */
const char *questions[NUM_QUESTIONS] = {
    "What is the capital of France?",
    "Who invented the telephone?",
    "What is the square root of 64?",
    "What is the smallest prime number?",
    "Who painted the Mona Lisa?",
    "What is the atomic number of oxygen?",
    "What is the largest planet in our solar system?",
    "What is the chemical symbol for gold?",
    "Who wrote the novel 'War and Peace'?",
    "What is the tallest mountain in North America?"
};

const char *answers[NUM_QUESTIONS] = {
    "Paris",
    "Alexander Graham Bell",
    "8",
    "2",
    "Leonardo da Vinci",
    "8",
    "Jupiter",
    "Au",
    "Leo Tolstoy",
    "Denali"
};

/* Define a function to display the exam instructions */
void display_instructions() {
    printf("Welcome to the C Online Examination System!\n\n");
    printf("You will have %d minutes to complete the exam.\n", EXAM_TIME);
    printf("There are %d questions in total.\n\n", NUM_QUESTIONS);
}

/* Define a function to get the user's answer */
char *get_answer() {
    char *answer = malloc(sizeof(char) * 256);
    scanf("%s", answer);
    return answer;
}

/* Define a function to grade the exam */
int grade_exam(char *user_answers[]) {
    int score = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        if (strcmp(user_answers[i], answers[i]) == 0) {
            score++;
        }
    }
    return score;
}

/* Define the main function */
int main() {
    /* Display the exam instructions */
    display_instructions();

    /* Get the current time */
    time_t start_time = time(NULL);

    /* Ask the questions */
    char *user_answers[NUM_QUESTIONS];
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("Question %d: %s\n", i+1, questions[i]);
        user_answers[i] = get_answer();
    }

    /* Get the elapsed time */
    time_t end_time = time(NULL);
    int elapsed_time = (int) difftime(end_time, start_time);

    /* Grade the exam */
    int score = grade_exam(user_answers);

    /* Display the results */
    printf("\n\n\n");
    printf("==============================================\n");
    printf("               Exam Results                    \n");
    printf("==============================================\n");
    printf("Total questions:  %d\n", NUM_QUESTIONS);
    printf("Total time taken: %d minutes\n", elapsed_time/60);
    printf("Your score:       %d/%d\n", score, NUM_QUESTIONS);
    printf("==============================================\n");

    /* Free the memory */
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        free(user_answers[i]);
    }

    return 0;
}