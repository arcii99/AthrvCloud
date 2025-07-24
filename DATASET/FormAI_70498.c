//FormAI DATASET v1.0 Category: Online Examination System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
 * C Online Examination System
 */

// define constants
#define TOTAL_QUESTIONS 10
#define MAX_QUESTION_LENGTH 100
#define MAX_ANSWER_LENGTH 50
#define MAX_NAME_LENGTH 30

// define question structure
struct question {
    char* text;
    char* answer;
};

// function prototypes
void shuffle_questions(struct question questions[], int size);
void display_instructions();
void start_test(char* name, struct question questions[], int size);

int main() {
    // initialize random seed
    srand(time(NULL));
    
    // define questions
    struct question questions[TOTAL_QUESTIONS] = {
        {"What is the capital of France?", "Paris"},
        {"What is the largest continent?", "Asia"},
        {"What is the tallest mammal?", "Giraffe"},
        {"What is the currency of Japan?", "Yen"},
        {"What is the largest organ in the human body?", "Skin"},
        {"What is the boiling point of water in Celsius?", "100"},
        {"What is the smallest planet in our solar system?", "Mercury"},
        {"What is the most populated country in the world?", "China"},
        {"What is the highest mountain in the world?", "Mount Everest"},
        {"What is the chemical symbol for gold?", "Au"}
    };
    
    // shuffle questions
    shuffle_questions(questions, TOTAL_QUESTIONS);
    
    // display instructions
    display_instructions();
    
    // get user's name
    char name[MAX_NAME_LENGTH];
    printf("Enter your name: ");
    fgets(name, MAX_NAME_LENGTH, stdin);
    name[strlen(name)-1] = '\0'; // remove newline character
    
    // start test
    start_test(name, questions, TOTAL_QUESTIONS);

    return 0;
}

// shuffle questions
void shuffle_questions(struct question questions[], int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        struct question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

// display instructions
void display_instructions() {
    printf("Welcome to the Online Examination System!\n\n");
    printf("This is a multiple choice test with %d questions.\n", TOTAL_QUESTIONS);
    printf("Each question has one correct answer.\n");
    printf("Answer each question by entering the corresponding letter (A, B, C, or D).\n");
    printf("You will receive your score at the end of the test.\n\n");
}

// start test
void start_test(char* name, struct question questions[], int size) {
    printf("Good luck, %s!\n\n", name);
    
    int score = 0;
    
    for (int i = 0; i < size; i++) {
        // display question
        printf("Question %d: %s\n", i+1, questions[i].text);
        printf("A) %s\n", questions[i].answer);
        
        // generate random dummy answers
        char dummy1[MAX_ANSWER_LENGTH];
        char dummy2[MAX_ANSWER_LENGTH];
        char dummy3[MAX_ANSWER_LENGTH];
        do {
            strcpy(dummy1, questions[rand() % size].answer);
        } while (strcmp(dummy1, questions[i].answer) == 0);
        do {
            strcpy(dummy2, questions[rand() % size].answer);
        } while (strcmp(dummy2, questions[i].answer) == 0 || strcmp(dummy2, dummy1) == 0);
        do {
            strcpy(dummy3, questions[rand() % size].answer);
        } while (strcmp(dummy3, questions[i].answer) == 0 || strcmp(dummy3, dummy1) == 0 || strcmp(dummy3, dummy2) == 0);
        
        // display dummy answers
        switch (rand() % 4) {
            case 0:
                printf("B) %s\nC) %s\nD) %s\n", dummy1, dummy2, dummy3);
                break;
            case 1:
                printf("B) %s\nC) %s\nD) %s\n", dummy2, dummy1, dummy3);
                break;
            case 2:
                printf("B) %s\nC) %s\nD) %s\n", dummy3, dummy1, dummy2);
                break;
            case 3:
                printf("B) %s\nC) %s\nD) %s\n", dummy1, dummy3, dummy2);
                break;
        }
        
        // get user's answer
        char answer[MAX_ANSWER_LENGTH];
        printf("Your answer: ");
        fgets(answer, MAX_ANSWER_LENGTH, stdin);
        answer[strlen(answer)-1] = '\0'; // remove newline character
        
        // check answer
        if (strcmp(answer, "A") == 0) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n\n", questions[i].answer);
        }
    }
    
    // display score
    printf("Your score is %d out of %d.\n", score, TOTAL_QUESTIONS);
}