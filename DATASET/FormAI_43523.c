//FormAI DATASET v1.0 Category: Online Examination System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 50
#define MAX_OPTIONS 4
#define MAX_ANSWERS 10
#define MAX_STUDENTS 100

typedef struct {
    int id;
    char question[100];
    char options[MAX_OPTIONS][50];
    char answer[MAX_ANSWERS][50];
} Question;

typedef struct {
    int roll_no;
    char name[50];
    int marks_obtained;
} Student;

void display_question(Question ques) {
    printf("%d) %s\n", ques.id, ques.question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%c) %s\n", 'A' + i, ques.options[i]);
    }
    printf("Answer: %s\n", ques.answer[0]);
}

void display_questions(Question ques[], int num_qs) {
    for (int i = 0; i < num_qs; i++) {
        display_question(ques[i]);
        printf("\n");
    }
}

int grade_exam(Question ques[], int num_qs, char answers[][50]) {
    int score = 0;
    for (int i = 0; i < num_qs; i++) {
        if (strcmp(ques[i].answer[0], answers[i]) == 0) {
            score++;
        }
    }
    return score;
}

void display_student(Student s) {
    printf("%d. %s - %d\n", s.roll_no, s.name, s.marks_obtained);
}

void display_students(Student students[], int num_students) {
    for (int i = 0; i < num_students; i++) {
        display_student(students[i]);
    }
}

int main() {
    Question questions[MAX_QUESTIONS];
    Student students[MAX_STUDENTS];

    // Populate question bank
    questions[0] = (Question) {1, "What is 2 + 2?", {"1", "2", "3", "4"}, {"D"}};
    questions[1] = (Question) {2, "What is the capital of France?", {"Paris", "Berlin", "London", "Madrid"}, {"A"}};
    questions[2] = (Question) {3, "What is the largest mammal on earth?", {"Elephant", "Hippopotamus", "Blue Whale", "Polar Bear"}, {"C"}};

    int num_questions = 3;

    // Display questions to user
    display_questions(questions, num_questions);

    // Collect answers from user and grade exam
    char answers[MAX_QUESTIONS][50];
    for (int i = 0; i < num_questions; i++) {
        printf("Enter your answer for question %d: ", i + 1);
        scanf("%s", answers[i]);
    }
    int score = grade_exam(questions, num_questions, answers);
    printf("You scored %d out of %d\n", score, num_questions);

    // Collect student info and store in array
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    for (int i = 0; i < num_students; i++) {
        printf("Enter the roll no. of student %d: ", i + 1);
        scanf("%d", &students[i].roll_no);
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", students[i].name);

        // Grade exam
        char student_answers[MAX_QUESTIONS][50];
        for (int j = 0; j < num_questions; j++) {
            printf("Enter answer for question %d: ", j + 1);
            scanf("%s", student_answers[j]);
        }
        students[i].marks_obtained = grade_exam(questions, num_questions, student_answers);
    }

    // Display student information
    display_students(students, num_students);

    return 0;
}