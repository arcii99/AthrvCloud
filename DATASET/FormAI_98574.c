//FormAI DATASET v1.0 Category: Online Examination System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This program simulates an online examination system */

/* define the question struct */
typedef struct {
    char question[100];
    char options[4][50];
    int correct_option;
} Question;

/* define the exam struct */
typedef struct {
    char exam_name[50];
    int number_of_questions;
    Question *questions;
} Exam;

/* function to display the menu */
void display_menu() {
     printf("Welcome to the online examination system\n");
     printf("1. Begin exam\n");
     printf("2. View scores\n");
     printf("3. Exit\n");
}

/* function to begin the exam */
void begin_exam(Exam *exam) {
    int num_correct = 0;
    int i;
    int selection;

    printf("Beginning %s exam\n", exam->exam_name);

    for (i = 0; i < exam->number_of_questions; i++) {
        printf("Question %d: %s\n", i+1, exam->questions[i].question);
        printf("a. %s\n", exam->questions[i].options[0]);
        printf("b. %s\n", exam->questions[i].options[1]);
        printf("c. %s\n", exam->questions[i].options[2]);
        printf("d. %s\n", exam->questions[i].options[3]);

        printf("Enter your selection: ");
        scanf("%d", &selection);

        /* check if the selected option is correct */
        if (selection-1 == exam->questions[i].correct_option) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect.\n");
        }
    }

    /* calculate and display final score */
    printf("Exam complete. You got %d/%d correct.\n", num_correct, exam->number_of_questions);
}

/* function to view scores */
void view_scores() {
    printf("Sorry, this functionality is not yet implemented.\n");
}

/* function to free memory allocated to exam */
void cleanup_exam(Exam *exam) {
    int i;
    for (i = 0; i < exam->number_of_questions; i++) {
        free(exam->questions[i].question);
        int j;
        for (j = 0; j < 4; j++) {
            free(exam->questions[i].options[j]);
        }
    }
    free(exam->questions);
}

int main() {
    /* create the exam */
    Exam exam;
    strcpy(exam.exam_name, "C Programming");
    exam.number_of_questions = 3;
    exam.questions = malloc(exam.number_of_questions*sizeof(Question));

    /* add questions to the exam */
    strcpy(exam.questions[0].question, "What is the output of printf(\"Hello, %s\\n\", name); where name=\"world\"?");
    strcpy(exam.questions[0].options[0], "Hello, world");
    strcpy(exam.questions[0].options[1], "Hello, ");
    strcpy(exam.questions[0].options[2], "Runtime error");
    strcpy(exam.questions[0].options[3], "Compilation error");
    exam.questions[0].correct_option = 0;

    strcpy(exam.questions[1].question, "What is the output of the following program?\n#include <stdio.h>\nint main() {\nint x = 5;\nint y = ++x;\nprintf(\"%d %d\", x, y);\nreturn 0;\n}");
    strcpy(exam.questions[1].options[0], "5 6");
    strcpy(exam.questions[1].options[1], "6 6");
    strcpy(exam.questions[1].options[2], "6 5");
    strcpy(exam.questions[1].options[3], "5 5");
    exam.questions[1].correct_option = 1;

    strcpy(exam.questions[2].question, "What is the result of 5+5*(5/5)?");
    strcpy(exam.questions[2].options[0], "10");
    strcpy(exam.questions[2].options[1], "15");
    strcpy(exam.questions[2].options[2], "25");
    strcpy(exam.questions[2].options[3], "5");
    exam.questions[2].correct_option = 0;

    int choice = 0;

    /* display the menu and wait for input */
    while (choice != 3) {
        display_menu();
        printf("Enter your selection: ");
        scanf("%d", &choice);

        /* execute selected option */
        switch (choice) {
            case 1:
                begin_exam(&exam);
                break;
            case 2:
                view_scores();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    /* free memory allocated to exam */
    cleanup_exam(&exam);

    return 0;
}