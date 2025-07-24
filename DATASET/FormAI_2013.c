//FormAI DATASET v1.0 Category: Online Examination System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definition of Question structure
typedef struct question {
    char question[200];
    char options[4][50];
    int correct_option;
} Question;

// Declaration of global variables
int score = 0;
int current_question = 0;
Question questions[10];

// Function to initialize questions
void initialize_questions() {
    strcpy(questions[0].question, "What is the capital of Japan?");
    strcpy(questions[0].options[0], "Tokyo");
    strcpy(questions[0].options[1], "Kyoto");
    strcpy(questions[0].options[2], "Osaka");
    strcpy(questions[0].options[3], "Hiroshima");
    questions[0].correct_option = 0;
    
    // Add more questions here
    // ...
}

// Function to display a question
void display_question(Question q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i+1, q.options[i]);
    }
}

// Function to get user input
int get_input() {
    int input;
    scanf("%d", &input);
    return input-1;
}

// Function to check answer
void check_answer(int answer) {
    if (answer == questions[current_question].correct_option) {
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect!\n");
    }
}

// Function to display score
void display_score() {
    printf("Your score is: %d\n", score);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize questions
    initialize_questions();
    
    // Shuffle the questions
    for (int i = 0; i < 10; i++) {
        int j = rand() % 10;
        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
    
    // Display the first question
    display_question(questions[0]);
    
    // Loop through each question
    for (int i = 0; i < 10; i++) {
        int answer = get_input();
        check_answer(answer);
        current_question++;
        display_score();
        if (current_question < 10) {
            display_question(questions[current_question]);
        }
    }
    
    return 0;
}