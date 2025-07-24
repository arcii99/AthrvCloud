//FormAI DATASET v1.0 Category: Online Examination System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

// Define constants
#define MAX_QUESTIONS 10
#define MAX_ANS_LENGTH 50
#define MAX_QS_LENGTH 100
#define TIME_LIMIT 60 // time limit for exam in seconds

// Define global variables
int score = 0;
bool is_timed_out = false;
char ans[MAX_QUESTIONS][MAX_ANS_LENGTH];
char qs[MAX_QUESTIONS][MAX_QS_LENGTH];

// Declare functions
void clear_stdin();
void print_welcome();
void generate_questions();
void display_questions();
void take_exam();
void score_exam();

int main() {
    print_welcome();
    generate_questions();
    display_questions();
    take_exam();
    score_exam();

    return 0;
}

/* Function to clear the standard input buffer */
void clear_stdin() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* Function to print the welcome message */
void print_welcome() {
    printf("Welcome to the Online Examination System!\n");
    printf("----------------------------------------\n\n");
}

/* Function to generate questions for the exam */
void generate_questions() {
    strcpy(qs[0], "What is the capital of France?");
    strcpy(ans[0], "Paris");

    strcpy(qs[1], "What is the largest continent?");
    strcpy(ans[1], "Asia");

    strcpy(qs[2], "What is the smallest country in the world?");
    strcpy(ans[2], "Vatican City");

    strcpy(qs[3], "What is the chemical symbol for gold?");
    strcpy(ans[3], "Au");

    strcpy(qs[4], "What is the tallest building in the world?");
    strcpy(ans[4], "Burj Khalifa");

    strcpy(qs[5], "What is the currency of Japan?");
    strcpy(ans[5], "Yen");

    strcpy(qs[6], "Who wrote the novel 'The Great Gatsby'?");
    strcpy(ans[6], "F. Scott Fitzgerald");

    strcpy(qs[7], "What is the largest planet in our solar system?");
    strcpy(ans[7], "Jupiter");

    strcpy(qs[8], "What is the unit of measurement for electric current?");
    strcpy(ans[8], "Ampere");

    strcpy(qs[9], "Who founded Microsoft?");
    strcpy(ans[9], "Bill Gates");
}

/* Function to display the questions */
void display_questions() {
    printf("Your exam has %d questions. You have %d minutes to complete it.\n\n", MAX_QUESTIONS, TIME_LIMIT / 60);
    sleep(2);

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d: %s\n", i + 1, qs[i]);
        sleep(1);
    }

    printf("\n");
}

/* Function to take the exam */
void take_exam() {
    printf("Please answer the questions below:\n\n");

    time_t start = time(NULL); // record start time

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d: ", i + 1);
        char user_ans[MAX_ANS_LENGTH];
        fgets(user_ans, MAX_ANS_LENGTH, stdin);

        // Remove '\n' from user's answer
        user_ans[strcspn(user_ans, "\n")] = 0;

        // Compare user's answer with correct answer
        if (strcmp(user_ans, ans[i]) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is \"%s\".\n", ans[i]);
        }
    }

    time_t end = time(NULL); // record end time

    // Check if time is up
    if (difftime(end, start) >= TIME_LIMIT) {
        is_timed_out = true;
    }
}

/* Function to score the exam */
void score_exam() {
    if (is_timed_out) {
        printf("\nTime's up! Your score is %d out of %d.\n", score, MAX_QUESTIONS);
        return;
    }

    printf("\nCongratulations! You have completed the exam.\n");
    printf("Your score is %d out of %d.\n", score, MAX_QUESTIONS);
}