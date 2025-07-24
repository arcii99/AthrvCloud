//FormAI DATASET v1.0 Category: Online Examination System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// Define constants for validation checks
#define MIN_QUESTION_COUNT 10
#define MAX_QUESTION_COUNT 25
#define MAX_ANSWER_LENGTH 128
#define MAX_QUESTION_LENGTH 512
#define MAX_USERNAME_LENGTH 32
#define MAX_PASSWORD_LENGTH 32
#define MAX_TRIES_ALLOWED 3

// Define question and answer structures for storing exam data
typedef struct {
    char question[MAX_QUESTION_LENGTH];
    char answer[MAX_ANSWER_LENGTH];
} Question;

// Define the user structure for holding user credentials
typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

// Define the exam structure to hold all data related to the exam
typedef struct {
    int question_count;
    Question *questions;
} Exam;

// Declare function prototypes for use in the main function
void clearBuffer();
char* encrypt(const char* input);
bool validateUser(User* user);
bool validateQuestionCount(int question_count);
bool validateQuestion(Question* question);

int main() {
    // Initialize variables
    User user;
    Exam exam;
    int i, j, tries_left;
    bool valid_input;
    srand(time(NULL));

    // Prompt user for credentials and validate
    do {
        printf("Please enter your username: ");
        fgets(user.username, MAX_USERNAME_LENGTH, stdin);
        printf("Please enter your password: ");
        fgets(user.password, MAX_PASSWORD_LENGTH, stdin);
        valid_input = validateUser(&user);
        if (!valid_input) {
            printf("Invalid username or password.\n");
        }
    } while (!valid_input);

    // Prompt user for number of questions and validate
    do {
        printf("Please enter the number of questions (between %d and %d): ", MIN_QUESTION_COUNT, MAX_QUESTION_COUNT);
        scanf("%d", &exam.question_count);
        clearBuffer();
        valid_input = validateQuestionCount(exam.question_count);
        if (!valid_input) {
            printf("Invalid number of questions.\n");
        }
    } while (!valid_input);

    // Allocate memory for questions and answers
    exam.questions = malloc(exam.question_count * sizeof(Question));
    // Populate exam with questions and answers
    for (i = 0; i < exam.question_count; i++) {
        do {
            printf("Enter question %d: ", i+1);
            fgets(exam.questions[i].question, MAX_QUESTION_LENGTH, stdin);
            printf("Enter answer %d: ", i+1);
            fgets(exam.questions[i].answer, MAX_ANSWER_LENGTH, stdin);
            valid_input = validateQuestion(&exam.questions[i]);
            if (!valid_input) {
                printf("Invalid question or answer.\n");
            }
        } while (!valid_input);
    }

    // Shuffle exam questions for randomization
    for (i = exam.question_count-1; i > 0; i--) {
        j = rand() % (i+1);
        Question temp = exam.questions[i];
        exam.questions[i] = exam.questions[j];
        exam.questions[j] = temp;
    }

    // Start the exam and track number of tries
    tries_left = MAX_TRIES_ALLOWED;
    for (i = 0; i < exam.question_count; i++) {
        printf("\nQuestion %d:\n%s\nYour answer: ", i+1, exam.questions[i].question);
        char* encrypted_answer = encrypt(exam.questions[i].answer);
        char user_answer[MAX_ANSWER_LENGTH];
        fgets(user_answer, MAX_ANSWER_LENGTH, stdin);
        if (strcmp(encrypt(user_answer), encrypted_answer) == 0) {
            printf("Correct!\n");
        } else {
            tries_left--;
            printf("Incorrect answer. %d attempts remaining.\n", tries_left);
            if (tries_left == 0) {
                printf("You have reached the maximum number of attempts. Please contact the exam administrator.\n");
                break;
            }
            i--;
        }
    }

    // Deallocate memory and exit program
    free(exam.questions);
    printf("\nThank you for taking the exam.\n");
    return 0;
}

// Function to clear input buffer
void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to encrypt input using simple substitution cipher
char* encrypt(const char* input) {
    int i, offset = (rand() % 26);
    char* result = malloc(strlen(input) * sizeof(char));
    for (i = 0; i < strlen(input); i++) {
        char c = input[i];
        if (isupper(c)) {
            c = ((c - 'A') + offset) % 26 + 'A';
        } else if (islower(c)) {
            c = ((c - 'a') + offset) % 26 + 'a';
        }
        result[i] = c;
    }
    return result;
}

// Function to validate user credentials
bool validateUser(User* user) {
    // Perform some basic checks on username and password, e.g. length, etc.
    if (strlen(user->username) < 6 || strlen(user->password) < 8) {
        return false;
    }
    // Authentication checks can be added as per requirements
    return true;
}

// Function to validate the number of questions specified by the user
bool validateQuestionCount(int question_count) {
    if (question_count < MIN_QUESTION_COUNT || question_count > MAX_QUESTION_COUNT) {
        return false;
    }
    return true;
}

// Function to validate question input
bool validateQuestion(Question* question) {
    if (strlen(question->question) == 0 || strlen(question->answer) == 0) {
        return false;
    }
    return true;
}