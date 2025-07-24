//FormAI DATASET v1.0 Category: Online Examination System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define TRUE 1
#define FALSE 0

// Define structs for question, answer, and student
typedef struct {
    int id;
    char question[256];
    char option1[64];
    char option2[64];
    char option3[64];
    char option4[64];
    int answer;
} Question;

typedef struct {
    int qid;
    int sid;
    int answer;
} Response;

typedef struct {
    int id;
    char name[64];
    int score;
} Student;

// Declare global variables
Question questions[10];
Response responses[100];
Student students[10];
int num_questions = 0;
int num_responses = 0;
int num_students = 0;

// Function to add a question to the system
void add_question(Question q) {
    questions[num_questions] = q;
    num_questions++;
}

// Function to add a response to the system
void add_response(Response r) {
    responses[num_responses] = r;
    num_responses++;
}

// Function to add a student to the system
void add_student(Student s) {
    students[num_students] = s;
    num_students++;
}

// Function to display all questions in the system
void display_questions() {
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d:\n", i+1);
        printf("%s\n", questions[i].question);
        printf("1. %s\n", questions[i].option1);
        printf("2. %s\n", questions[i].option2);
        printf("3. %s\n", questions[i].option3);
        printf("4. %s\n", questions[i].option4);
        printf("\n");
    }
}

// Function to display the results of a given student
void display_results(int sid) {
    int num_correct = 0;
    int num_incorrect = 0;
    for (int i = 0; i < num_responses; i++) {
        if (responses[i].sid == sid) {
            int qid = responses[i].qid;
            int answer = responses[i].answer;
            if (answer == questions[qid].answer) {
                num_correct++;
            } else {
                num_incorrect++;
            }
        }
    }
    printf("Results for student %d:\n", sid);
    printf("Correct answers: %d\n", num_correct);
    printf("Incorrect answers: %d\n", num_incorrect);
}

// Function to calculate the score of a given student
int calculate_score(int sid) {
    int score = 0;
    for (int i = 0; i < num_responses; i++) {
        if (responses[i].sid == sid) {
            int qid = responses[i].qid;
            int answer = responses[i].answer;
            if (answer == questions[qid].answer) {
                score++;
            }
        }
    }
    return score;
}

// Main function
int main() {
    // Declare variables
    char input[256];
    int finished = FALSE;

    // Add questions to the system
    Question q1 = {1, "What is the capital of France?", "Paris", "London", "Rome", "Madrid", 1};
    Question q2 = {2, "What is the highest mountain in the world?", "Mount Everest", "Kilimanjaro", "Mount McKinley", "Mount Fuji", 1};
    Question q3 = {3, "What is the largest country in the world?", "Canada", "United States", "Russia", "China", 3};
    add_question(q1);
    add_question(q2);
    add_question(q3);

    // Display welcome message
    printf("Welcome to the online examination system!\n");

    // Loop until user is finished
    while (!finished) {
        // Display menu options
        printf("\n");
        printf("1. Display all questions\n");
        printf("2. Take the exam\n");
        printf("3. Check results\n");
        printf("4. Exit\n");

        // Get user input
        printf("Enter your choice: ");
        fgets(input, sizeof(input), stdin);
        int choice = atoi(input);

        // Handle user choice
        switch (choice) {
            case 1:
                // Display all questions
                display_questions();
                break;
            case 2:
                // Take the exam
                printf("Enter your name: ");
                fgets(input, sizeof(input), stdin);
                strtok(input, "\n");
                int sid = num_students + 1;
                Student s = {sid, "", 0};
                strcpy(s.name, input);
                add_student(s);
                for (int i = 0; i < num_questions; i++) {
                    printf("Question %d:\n", i+1);
                    printf("%s\n", questions[i].question);
                    printf("1. %s\n", questions[i].option1);
                    printf("2. %s\n", questions[i].option2);
                    printf("3. %s\n", questions[i].option3);
                    printf("4. %s\n", questions[i].option4);
                    printf("Enter your answer: ");
                    fgets(input, sizeof(input), stdin);
                    int answer = atoi(input);
                    Response r = {i, sid, answer};
                    add_response(r);
                }
                printf("Exam complete!\n");
                break;
            case 3:
                // Check results
                printf("Enter your student ID: ");
                fgets(input, sizeof(input), stdin);
                int id = atoi(input);
                display_results(id);
                break;
            case 4:
                // Exit program
                printf("Goodbye!\n");
                finished = TRUE;
                break;
            default:
                // Invalid input
                printf("Invalid choice, please try again.\n");
                break;
        }
    }

    // Calculate and display scores for all students
    printf("Final scores:\n");
    for (int i = 0; i < num_students; i++) {
        int score = calculate_score(students[i].id);
        students[i].score = score;
        printf("%s: %d\n", students[i].name, score);
    }

    return 0;
}