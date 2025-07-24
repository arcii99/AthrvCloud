//FormAI DATASET v1.0 Category: Online Examination System ; Style: expert-level
// C Online Examination System Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold student information
typedef struct {
    char name[50];
    int rollNo;
    char branch[20];
} Student;

// Structure to hold questions and answers
typedef struct {
    char question[200];
    char optionA[50];
    char optionB[50];
    char optionC[50];
    char optionD[50];
    char correctAnswer;
} Question;

// Function to display main menu
void showMainMenu() {
    printf("\n\nWelcome to Online Examination System!\n");
    printf("1. Register as a new student\n");
    printf("2. Login as an existing student\n");
    printf("3. Exit\n");
}

// Function to display student dashboard
void showStudentDashboard() {
    printf("\n\nWelcome to your dashboard!\n");
    printf("1. View your profile\n");
    printf("2. View your exam results\n");
    printf("3. Logout\n");
}

// Function to register a new student
void registerStudent(Student *students, int *numStudents) {
    printf("Enter your name: ");
    scanf("%s", students[*numStudents].name);
    printf("Enter your roll number: ");
    scanf("%d", &students[*numStudents].rollNo);
    printf("Enter your branch: ");
    scanf("%s", students[*numStudents].branch);
    printf("Registration successful!\n");
    (*numStudents)++;
}

// Function to log in an existing student
int loginStudent(Student *students, int numStudents, int *currentIndex) {
    int rollNo;
    printf("Enter your roll number: ");
    scanf("%d", &rollNo);
    for (int i = 0; i < numStudents; i++) {
        if (students[i].rollNo == rollNo) {
            printf("Welcome, %s!\n", students[i].name);
            *currentIndex = i;
            return 1;
        }
    }
    printf("Invalid roll number!\n");
    return 0;
}

// Function to display exam questions and record answers
void conductExam(Question *questions, int numQuestions, int *numCorrect) {
    char answer;
    for (int i = 0; i < numQuestions; i++) {
        printf("\n\nQuestion %d:\n\n%s\n\n", i+1, questions[i].question);
        printf("A. %s\n", questions[i].optionA);
        printf("B. %s\n", questions[i].optionB);
        printf("C. %s\n", questions[i].optionC);
        printf("D. %s\n", questions[i].optionD);
        printf("\nEnter your answer (A/B/C/D): ");
        scanf(" %c", &answer);
        if (answer == questions[i].correctAnswer) {
            (*numCorrect)++;
        }
    }
    printf("Exam completed!\n");
}

// Function to display exam results
void showExamResults(int numQuestions, int numCorrect) {
    printf("\n\nExam Results:\n\n");
    printf("Total Questions: %d\n", numQuestions);
    printf("Questions Attempted: %d\n", numQuestions);
    printf("Questions Correct: %d\n", numCorrect);
    printf("Questions Incorrect: %d\n", numQuestions - numCorrect);
}

int main() {
    Student students[50];
    Question questions[10];
    int numStudents = 0;
    int currentIndex = -1;
    int numQuestions = 0;
    int numCorrect = 0;
    int choice;

    // Add sample questions
    strcpy(questions[numQuestions].question, "Which of the following is not a primary color?");
    strcpy(questions[numQuestions].optionA, "Red");
    strcpy(questions[numQuestions].optionB, "Blue");
    strcpy(questions[numQuestions].optionC, "Yellow");
    strcpy(questions[numQuestions].optionD, "Green");
    questions[numQuestions].correctAnswer = 'D';
    numQuestions++;

    strcpy(questions[numQuestions].question, "What is the capital of India?");
    strcpy(questions[numQuestions].optionA, "Mumbai");
    strcpy(questions[numQuestions].optionB, "New Delhi");
    strcpy(questions[numQuestions].optionC, "Chennai");
    strcpy(questions[numQuestions].optionD, "Kolkata");
    questions[numQuestions].correctAnswer = 'B';
    numQuestions++;

    strcpy(questions[numQuestions].question, "What is the smallest country in the world?");
    strcpy(questions[numQuestions].optionA, "Monaco");
    strcpy(questions[numQuestions].optionB, "Malta");
    strcpy(questions[numQuestions].optionC, "Vatican City");
    strcpy(questions[numQuestions].optionD, "San Marino");
    questions[numQuestions].correctAnswer = 'C';
    numQuestions++;

    do {
        showMainMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                registerStudent(students, &numStudents);
                break;
            case 2:
                if (loginStudent(students, numStudents, &currentIndex)) {
                    showStudentDashboard();
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    switch (choice) {
                        case 1:
                            printf("\n\nName: %s\n", students[currentIndex].name);
                            printf("Roll No: %d\n", students[currentIndex].rollNo);
                            printf("Branch: %s\n", students[currentIndex].branch);
                            break;
                        case 2:
                            conductExam(questions, numQuestions, &numCorrect);
                            showExamResults(numQuestions, numCorrect);
                            break;
                        case 3:
                            printf("Logging out...\n");
                            break;
                        default:
                            printf("Invalid choice!\n");
                            break;
                    }
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 3);

    return 0;
}