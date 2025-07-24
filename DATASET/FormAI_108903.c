//FormAI DATASET v1.0 Category: Online Examination System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for maximum number of questions and options
#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4

// Define a struct for each question
typedef struct {
    char question[100];
    char options[MAX_OPTIONS][50];
    int answer;
} Question;

// Function to display the introduction message and wait for user to start the exam
void display_intro() {
    printf("Welcome to the C Online Examination System!\n");
    printf("This exam contains 10 questions in total.\n");
    printf("You will have 30 seconds to answer each question.\n");
    printf("Press any key to start the exam...\n");
    getchar(); // Wait for user input
    printf("\n");
}

// Function to read a single question from the file and return as a Question struct
Question read_question(FILE *file) {
    Question question;
    char buffer[100];
    fgets(buffer, 100, file); // Read question text
    strcpy(question.question, buffer);

    for (int i = 0; i < MAX_OPTIONS; i++) {
        fgets(buffer, 100, file); // Read option text
        strcpy(question.options[i], buffer);
    }

    fscanf(file, "%d", &question.answer); // Read answer integer

    return question;
}

int main() {
    FILE *file = fopen("exam.txt", "r"); // Open file containing exam questions
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    Question questions[MAX_QUESTIONS];

    // Read each question from file and store in array
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        questions[i] = read_question(file);
        getchar(); // Wait for user input before proceeding to next question
    }

    fclose(file); // Close file

    display_intro(); // Display introduction message before starting exam

    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d:\n\n", i+1);
        printf("%s\n", questions[i].question);
        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s", j+1, questions[i].options[j]);
        }
        printf("\n");
        int answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);
        if (answer == questions[i].answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %d.\n", questions[i].answer);
        }
        printf("\n");
        getchar(); // Wait for user input before proceeding to next question
    }

    int percentage_score = (score*100)/MAX_QUESTIONS; // Calculate percentage score
    printf("Exam completed. You scored %d/%d (%d%%).\n", score, MAX_QUESTIONS, percentage_score);

    if (percentage_score >= 60) {
        printf("Congratulations, you have passed the exam!\n");
    } else {
        printf("Sorry, you have failed the exam. Better luck next time!\n");
    }

    return 0;
}