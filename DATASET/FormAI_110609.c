//FormAI DATASET v1.0 Category: Online Examination System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constants
#define MAX_QUESTIONS 50
#define MAX_CHOICES 4
#define MAX_NAME_LENGTH 30

//Structures
typedef struct {
    int question_number;
    char question_text[100];
    char choices[MAX_CHOICES][50];
    int correct_answer;
} Question;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int score;
} Student;

//Functions
void display_welcome_message();
void display_instructions();
void generate_questions(Question *questions);
void display_question(Question question);
int get_student_count();
void get_student_names(Student *students, int count);
void conduct_exam(Question *questions, Student *students, int count);
void record_score(Student *student);
void display_result(Student *students, int count);
void display_goodbye_message();

int main() {
    Question questions[MAX_QUESTIONS];
    Student students[MAX_QUESTIONS];
    int student_count;
    
    display_welcome_message();
    display_instructions();
    
    generate_questions(questions);
    
    student_count = get_student_count();
    get_student_names(students, student_count);
    
    conduct_exam(questions, students, student_count);
    
    display_result(students, student_count);
    display_goodbye_message();
    
    return 0;
}

void display_welcome_message() {
    printf("Welcome to the Online Examination System.\n");
}

void display_instructions() {
    printf("\nYou are about to take an exam consisting of %d multiple-choice questions.\n", MAX_QUESTIONS);
    printf("You will have four choices for each question, and must select the correct one.\n");
    printf("You will receive your score at the end of the exam.\n");
    printf("Best of luck!\n\n");
}

void generate_questions(Question *questions) {
    //Generate random questions
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        questions[i].question_number = i + 1;
        sprintf(questions[i].question_text, "What is %d + %d?", rand() % 10, rand() % 10);
        sprintf(questions[i].choices[0], "%d", rand() % 20);
        sprintf(questions[i].choices[1], "%d", rand() % 20);
        sprintf(questions[i].choices[2], "%d", rand() % 20);
        sprintf(questions[i].choices[3], "%d", rand() % 20);
        questions[i].correct_answer = rand() % 4;
    }
}

void display_question(Question question) {
    //Display question
    printf("\n%d) %s\n", question.question_number, question.question_text);
    for (int i = 0; i < MAX_CHOICES; i++) {
        printf("%c) %s\n", 'A' + i, question.choices[i]);
    }
}

int get_student_count() {
    int count;
    printf("Please enter the number of students: ");
    scanf("%d", &count);
    return count;
}

void get_student_names(Student *students, int count) {
    for (int i = 0; i < count; i++) {
        printf("Enter name for student %d: ", i+1);
        scanf("%s", students[i].name);
        students[i].score = 0;
    }
}

void conduct_exam(Question *questions, Student *students, int count) {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("\nQuestion %d:\n", i+1);
        display_question(questions[i]);
        for (int j = 0; j < count; j++) {
            printf("%s, please enter your answer (A, B, C or D): ", students[j].name);
            char choice;
            scanf(" %c", &choice);
            //Check answer
            if (choice - 'A' == questions[i].correct_answer) {
                printf("Correct answer!\n");
                students[j].score++;
            } else {
                printf("Incorrect answer.\n");
            }
        }
    }
}

void record_score(Student *student) {
    //Record score to file
    FILE *outfile = fopen("scores.txt", "a");
    fprintf(outfile, "%s: %d\n", student->name, student->score);
    fclose(outfile);
}

void display_result(Student *students, int count) {
    printf("\nExam Results:\n");
    for (int i = 0; i < count; i++) {
        printf("%s scored %d out of %d.\n", students[i].name, students[i].score, MAX_QUESTIONS);
        record_score(&students[i]);
    }
}

void display_goodbye_message() {
    printf("\nThank you for taking the exam.\n");
}