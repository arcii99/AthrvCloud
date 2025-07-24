//FormAI DATASET v1.0 Category: Online Examination System ; Style: modular
#include <stdio.h>
#include <string.h>

// Define modifiable constants
#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4
#define MAX_STUDENTS 10
#define MAX_NAME_LENGTH 20

// Define data structures
typedef struct {
    char question[100];
    char answers[MAX_ANSWERS][50];
    int correct_answer;
} MCQuestion;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
    int answers[MAX_QUESTIONS];
} Student;

// Define global variables
MCQuestion questions[MAX_QUESTIONS];
int total_questions = 0;
Student students[MAX_STUDENTS];
int total_students = 0;

// Function to add a new multiple choice question
void add_mc_question(char question[100], char answers[MAX_ANSWERS][50], int correct_answer) {
    if (total_questions < MAX_QUESTIONS) {
        MCQuestion new_question;
        strcpy(new_question.question, question);
        for (int i = 0; i < MAX_ANSWERS; i++) {
            strcpy(new_question.answers[i], answers[i]);
        }
        new_question.correct_answer = correct_answer;

        questions[total_questions] = new_question;
        total_questions++;
    }
}

// Function to add a new student
void add_student(char name[MAX_NAME_LENGTH]) {
    if (total_students < MAX_STUDENTS) {
        Student new_student;
        strcpy(new_student.name, name);
        new_student.score = 0;
        for (int i = 0; i < total_questions; i++) {
            new_student.answers[i] = -1;
        }

        students[total_students] = new_student;
        total_students++;
    }
}

// Function to print the exam for a given student index
void print_exam(int student_index) {
    printf("Exam for student %s\n", students[student_index].name);
    for (int i = 0; i < total_questions; i++) {
        printf("\n%s\n", questions[i].question);
        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%d. %s\n", j+1, questions[i].answers[j]);
        }
        printf("Enter your answer (1-4): ");
        scanf("%d", &students[student_index].answers[i]);
    }
}

// Function to grade the exam for a given student index
void grade_exam(int student_index) {
    int score = 0;
    for (int i = 0; i < total_questions; i++) {
        if (students[student_index].answers[i] == questions[i].correct_answer) {
            score++;
        }
    }
    students[student_index].score = score;
}

// Function to print the scores of all students
void print_scores() {
    printf("\nScoreboard:\n");
    for (int i = 0; i < total_students; i++) {
        printf("%s: %d/%d\n", students[i].name, students[i].score, total_questions);
    }
}

// Main function to simulate the examination system
int main() {
    // Example usage
    add_mc_question("What color is the sky?", (char[4][50]){"Blue", "Green", "Red", "Yellow"}, 1);
    add_mc_question("Which planet is closest to the sun?", (char[4][50]){"Venus", "Mercury", "Mars", "Jupiter"}, 2);
    add_student("Alice");
    add_student("Bob");

    for (int i = 0; i < total_students; i++) {
        print_exam(i);
        grade_exam(i);
    }

    print_scores();

    return 0;
}