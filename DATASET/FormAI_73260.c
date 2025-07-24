//FormAI DATASET v1.0 Category: Online Examination System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define NUM_OF_QUESTIONS 5

// struct for questions
struct question {
    char question_text[100];
    char answer_options[4][50];
    int correct_answer;
};

// array of questions
struct question exam_questions[NUM_OF_QUESTIONS];

// some other variables
int student_answers[NUM_OF_QUESTIONS];
int student_id;
int num_of_students = 0;

// function prototype
void * student_exam(void * arg);

int main() {
    // initialize the questions with dummy data
    strcpy(exam_questions[0].question_text, "What is the capital of India?");
    strcpy(exam_questions[0].answer_options[0], "A. Delhi");
    strcpy(exam_questions[0].answer_options[1], "B. Mumbai");
    strcpy(exam_questions[0].answer_options[2], "C. Kolkata");
    strcpy(exam_questions[0].answer_options[3], "D. Bangalore");
    exam_questions[0].correct_answer = 0;

    strcpy(exam_questions[1].question_text, "What is 2+2?");
    strcpy(exam_questions[1].answer_options[0], "A. 4");
    strcpy(exam_questions[1].answer_options[1], "B. 3");
    strcpy(exam_questions[1].answer_options[2], "C. 5");
    strcpy(exam_questions[1].answer_options[3], "D. 2");
    exam_questions[1].correct_answer = 0;

    strcpy(exam_questions[2].question_text, "What is the largest ocean in the world?");
    strcpy(exam_questions[2].answer_options[0], "A. Atlantic Ocean");
    strcpy(exam_questions[2].answer_options[1], "B. Pacific Ocean");
    strcpy(exam_questions[2].answer_options[2], "C. Indian Ocean");
    strcpy(exam_questions[2].answer_options[3], "D. Arctic Ocean");
    exam_questions[2].correct_answer = 1;

    strcpy(exam_questions[3].question_text, "What is the national animal of Australia?");
    strcpy(exam_questions[3].answer_options[0], "A. Kangaroo");
    strcpy(exam_questions[3].answer_options[1], "B. Koala");
    strcpy(exam_questions[3].answer_options[2], "C. Emu");
    strcpy(exam_questions[3].answer_options[3], "D. Australian Cattle Dog");
    exam_questions[3].correct_answer = 0;

    strcpy(exam_questions[4].question_text, "Which planet is known as the Red Planet?");
    strcpy(exam_questions[4].answer_options[0], "A. Venus");
    strcpy(exam_questions[4].answer_options[1], "B. Mars");
    strcpy(exam_questions[4].answer_options[2], "C. Jupiter");
    strcpy(exam_questions[4].answer_options[3], "D. Saturn");
    exam_questions[4].correct_answer = 1;

    // initialize the student_answers array with -1 for all questions
    for (int i = 0; i < NUM_OF_QUESTIONS; i++) {
        student_answers[i] = -1;
    }

    // get number of students appearing for the exam
    printf("Enter the number of students appearing for the exam: ");
    scanf("%d", &num_of_students);

    // array of thread ids for each student
    pthread_t students[num_of_students];

    // create threads for each student
    for (int i = 0; i < num_of_students; i++) {
        student_id = i;
        pthread_create(&students[i], NULL, &student_exam, NULL);
    }

    // join all the threads to wait for all students to finish the exam
    for (int i = 0; i < num_of_students; i++) {
        pthread_join(students[i], NULL);
    }

    // print the final results
    printf("\nFinal Results:");
    for (int i = 0; i < num_of_students; i++) {
        printf("\nStudent %d:", i+1);
        int score = 0;
        for (int j = 0; j < NUM_OF_QUESTIONS; j++) {
            if (student_answers[j] == exam_questions[j].correct_answer) {
                score++;
            }
        }
        printf("\nScore: %d", score);
    }

    return 0;
}

void * student_exam(void * arg) {
    // print the student id
    printf("\nStudent %d started the exam", student_id+1);

    // ask each question to the student
    for (int i = 0; i < NUM_OF_QUESTIONS; i++) {
        printf("\n\nQuestion %d:", i+1);
        printf("\n%s", exam_questions[i].question_text);
        printf("\n\n%s", exam_questions[i].answer_options[0]);
        printf("\n%s", exam_questions[i].answer_options[1]);
        printf("\n%s", exam_questions[i].answer_options[2]);
        printf("\n%s", exam_questions[i].answer_options[3]);

        // ask the student to select an answer
        int answer = -1;
        while (answer < 0 || answer > 3) {
            printf("\n\nEnter your answer (A=0,B=1,C=2,D=3): ");
            scanf("%d", &answer);
        }
        student_answers[i] = answer;
    }

    // print that the student has completed the exam
    printf("\n\nStudent %d completed the exam", student_id+1);

    return NULL;
}