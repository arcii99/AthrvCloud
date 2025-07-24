//FormAI DATASET v1.0 Category: Online Examination System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define the maximum number of questions and choices
#define MAX_QUESTIONS 10
#define MAX_CHOICES 4

// Define a structure for each question
typedef struct {
    char question[100];
    char choices[MAX_CHOICES][50];
    int answer; // index of the answer in 'choices' array
} Question;

// Define a structure for each student
typedef struct {
    char name[50];
    int score;
    bool hasTakenExam;
} Student;

// Define a function to load questions from a file
void loadQuestions(Question* questions, int* numQuestions) {
    FILE* fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error loading questions!\n");
        exit(EXIT_FAILURE);
    }
    char buffer[1000];
    char** tokens = (char**) malloc(MAX_CHOICES * sizeof(char*));
    for (int i = 0; i < MAX_CHOICES; i++) {
        tokens[i] = (char*) malloc(50 * sizeof(char));
    }
    int i = 0;
    while (fgets(buffer, 1000, fp) != NULL) {
        if (i >= MAX_QUESTIONS) {
            printf("WARNING: Maximum number of questions reached!\n");
            break;
        }
        strcpy(questions[i].question, buffer);
        for (int j = 0; j < MAX_CHOICES; j++) {
            fgets(buffer, 1000, fp);
            sscanf(buffer, "%d.%[^\n]", &j, tokens[j]);
            strcpy(questions[i].choices[j], tokens[j]);
        }
        fgets(buffer, 1000, fp);
        sscanf(buffer, "%d", &questions[i].answer);
        i++;
    }
    *numQuestions = i;
    fclose(fp);
}

// Define a function to present a question to the student and get their answer
void presentQuestion(Question question) {
    printf("%s", question.question);
    for (int i = 0; i < MAX_CHOICES; i++) {
        printf("%d. %s\n", i, question.choices[i]);
    }
    printf("Enter your answer (0-3): ");
    int answer;
    scanf("%d", &answer);
    if (answer == question.answer) {
        printf("Correct!\n");
    } else {
        printf("Wrong!\n");
    }
}

// Define a function to present the exam to the student
void presentExam(Question* questions, int numQuestions, Student* student) {
    printf("Welcome %s to the exam!\n", student->name);
    for (int i = 0; i < numQuestions; i++) {
        presentQuestion(questions[i]);
    }
    student->hasTakenExam = true;
}

// Define a function to grade the student's exam
void gradeExam(Question* questions, int numQuestions, Student* student) {
    printf("Grading %s's exam...\n", student->name);
    int score = 0;
    for (int i = 0; i < numQuestions; i++) {
        printf("Question %d: ", i+1);
        presentQuestion(questions[i]);
        if (questions[i].answer == student->score) {
            score++;
        }
    }
    student->score = score;
    printf("%s's final score is %d/%d.\n", student->name, student->score, numQuestions);
}

// Define a function to write the student's information to a file
void saveStudent(Student student) {
    FILE* fp = fopen("students.txt", "a");
    if (fp == NULL) {
        printf("Error saving student!\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "%s,%d,%d\n", student.name, student.score, student.hasTakenExam);
    fclose(fp);
}

int main() {
    int selection;
    Question questions[MAX_QUESTIONS];
    int numQuestions = 0;
    Student student;

    printf("Welcome to the online exam system!\n");
    printf("Please select an option:\n");
    printf("1. Take the exam\n");
    printf("2. Grade a student's exam\n");
    printf("3. Exit\n");
    scanf("%d", &selection);

    switch (selection) {
        case 1:
            printf("Enter your name: ");
            scanf(" %s", student.name);
            loadQuestions(questions, &numQuestions);
            presentExam(questions, numQuestions, &student);
            gradeExam(questions, numQuestions, &student);
            saveStudent(student);
            break;
        case 2:
            printf("Enter the student's name: ");
            scanf(" %s", student.name);
            // Load the student's information
            break;
        case 3:
            return EXIT_SUCCESS;
        default:
            printf("Invalid input!\n");
            break;
    }

    return EXIT_SUCCESS;
}