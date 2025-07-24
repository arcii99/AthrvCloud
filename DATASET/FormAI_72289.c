//FormAI DATASET v1.0 Category: Online Examination System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 50
#define MAX_OPTIONS 4
#define MAX_ANSWER_LENGTH 10

/* Struct to store a question */
typedef struct {
    char text[100];
    char options[MAX_OPTIONS][50];
    int correct_option;
} Question;

/* Struct to store an exam */
typedef struct {
    char name[50];
    Question questions[MAX_QUESTIONS];
    int num_questions;
} Exam;

/* Function to create a new exam */
Exam create_exam() {
    Exam exam;
    printf("Enter the name of the exam: ");
    fgets(exam.name, 50, stdin);
    exam.name[strcspn(exam.name, "\n")] = '\0';
    printf("Enter the number of questions for this exam (maximum %d): ", MAX_QUESTIONS);
    scanf("%d", &exam.num_questions);
    getchar();
    printf("\n");

    for (int i = 0; i < exam.num_questions; i++) {
        printf("Enter the text for question %d: ", i+1);
        fgets(exam.questions[i].text, 100, stdin);
        exam.questions[i].text[strcspn(exam.questions[i].text, "\n")] = '\0';

        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("Enter option %d for this question: ", j+1);
            fgets(exam.questions[i].options[j], 50, stdin);
            exam.questions[i].options[j][strcspn(exam.questions[i].options[j], "\n")] = '\0';
        }

        printf("Enter the correct option for this question: ");
        scanf("%d", &exam.questions[i].correct_option);
        getchar();
        printf("\n");
    }

    return exam;
}

/* Function to display an exam */
void display_exam(Exam exam) {
    printf("Exam: %s\n", exam.name);

    for (int i = 0; i < exam.num_questions; i++) {
        printf("%d. %s\n", i+1, exam.questions[i].text);

        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%c. %s\n", 'A'+j, exam.questions[i].options[j]);
        }

        printf("Answer: %c\n\n", 'A' + exam.questions[i].correct_option - 1);
    }
}

/* Function to take an exam and grade it */
void take_exam(Exam exam) {
    int num_correct = 0;

    for (int i = 0; i < exam.num_questions; i++) {
        printf("%d. %s\n", i+1, exam.questions[i].text);

        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%c. %s\n", 'A'+j, exam.questions[i].options[j]);
        }

        char answer[MAX_ANSWER_LENGTH];
        printf("Enter your answer: ");
        fgets(answer, MAX_ANSWER_LENGTH, stdin);
        answer[strcspn(answer, "\n")] = '\0';

        if (tolower(answer[0]) == 'a' + exam.questions[i].correct_option - 1) {
            printf("Correct!\n\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct answer is %c.\n\n", 'A' + exam.questions[i].correct_option - 1);
        }
    }

    printf("You got %d out of %d questions correct.\n", num_correct, exam.num_questions);
}

int main() {
    Exam exam = create_exam();
    display_exam(exam);
    take_exam(exam);

    return 0;
}