//FormAI DATASET v1.0 Category: Online Examination System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

/*
 * This is an example of an asynchronous style C Online Examination System program.
 * The program generates a set of multiple choice questions for a timed exam
 * and saves the user's answers to a file. The program then computes the user's
 * score and displays it on the screen.
 */

// define the number of questions, choices, and exam time
#define NUM_QUESTIONS 10
#define NUM_CHOICES 4
#define EXAM_TIME 60

// struct to represent a question
typedef struct {
    char question_text[100];
    char choices[NUM_CHOICES][50];
    int correct_choice;
} question_t;

// function declarations
int generate_exam(question_t questions[], int num_questions);
void save_answers(char *filename, int answers[], int num_questions);
int compute_score(question_t questions[], int user_answers[], int num_questions);

int main() {
    // seed the random number generator
    srand(time(NULL));

    // generate questions for the exam
    question_t questions[NUM_QUESTIONS];
    int num_questions = generate_exam(questions, NUM_QUESTIONS);

    // initialize an array to store the user's answers
    int user_answers[num_questions];

    // set up the timer for the exam
    printf("You have %d seconds to complete the exam.\n", EXAM_TIME);
    sleep(EXAM_TIME);

    // save the user's answers to a file
    char *filename = "answers.txt";
    save_answers(filename, user_answers, num_questions);

    // compute the user's score and display it on the screen
    int score = compute_score(questions, user_answers, num_questions);
    printf("Your score is %d out of %d.\n", score, num_questions);

    return 0;
}

// generate a set of multiple choice questions for the exam
int generate_exam(question_t questions[], int num_questions) {
    int i, j;

    // initialize the questions array
    for (i = 0; i < num_questions; i++) {
        sprintf(questions[i].question_text, "Question %d: What is the capital of ", i+1);

        // choose a random country
        char *countries[] = {"Spain", "France", "Japan", "India", "Australia"};
        int num_countries = sizeof(countries)/sizeof(*countries);
        char *country = countries[rand() % num_countries];
        strcat(questions[i].question_text, country);

        // set up the answer choices
        char *capitals[] = {"Madrid", "Paris", "Tokyo", "New Delhi", "Canberra"};
        int correct_choice = -1;
        for (j = 0; j < NUM_CHOICES; j++) {
            int choice_index = (rand() % num_countries + j) % num_countries;
            if (strcmp(capitals[choice_index], country) == 0) {
                correct_choice = j;
            }
            strcpy(questions[i].choices[j], capitals[choice_index]);
        }
        questions[i].correct_choice = correct_choice;
    }

    return num_questions;
}

// save the user's answers to a file
void save_answers(char *filename, int answers[], int num_questions) {
    int fd = open(filename, O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        exit(1);
    }
    ssize_t n = write(fd, answers, num_questions*sizeof(int));
    if (n < 0) {
        perror("write");
        exit(1);
    }
    close(fd);
}

// compute the user's score
int compute_score(question_t questions[], int user_answers[], int num_questions) {
    int i, score = 0;

    // read the correct answers from the questions array and compare with user answers
    for (i = 0; i < num_questions; i++) {
        if (user_answers[i] == questions[i].correct_choice) {
            score++;
        }
    }

    return score;
}