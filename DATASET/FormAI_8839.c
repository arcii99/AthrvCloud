//FormAI DATASET v1.0 Category: Online Examination System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 20
#define MAX_OPTIONS 4

typedef struct {
    int id;
    char question[100];
    char options[MAX_OPTIONS][50];
    int correct_answer;
} Question;

void shuffle(Question *questions, int num_questions) {
    srand(time(NULL)); // seed the random number generator
    for (int i = 0; i < num_questions; i++) {
        int j = rand() % num_questions; // generate a random index
        Question temp = questions[i];
        questions[i] = questions[j];
        questions[j] = temp;
    }
}

void display_question(Question *question) {
    printf("%d. %s\n", question->id, question->question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%c) %s\n", 'A' + i, question->options[i]);
    }
    printf("Answer: ");
}

int get_answer() {
    char c = getchar();
    while (getchar() != '\n'); // clear the input buffer
    if (c < 'A' || c > 'D') {
        return -1; // invalid answer
    }
    return c - 'A';
}

int main() {
    Question questions[MAX_QUESTIONS] = {
        {1, "What is the capital of France?", {"Paris", "London", "New York", "Tokyo"}, 0},
        {2, "What year did World War II start?", {"1914", "1939", "1942", "1950"}, 1},
        {3, "Who wrote the book 'To Kill a Mockingbird'?", {"Jane Austen", "Harper Lee", "J.K. Rowling", "Ernest Hemingway"}, 1},
        {4, "Which planet is known as the 'Red Planet'?", {"Mercury", "Venus", "Mars", "Jupiter"}, 2},
        {5, "What is the largest continent in the world?", {"Africa", "Asia", "Europe", "South America"}, 1},
        // add more questions here
    };
    int num_questions = sizeof(questions) / sizeof(Question);
    shuffle(questions, num_questions); // shuffle the questions
    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        display_question(&questions[i]); // display the question
        int answer = get_answer(); // get the answer from the user
        if (answer == questions[i].correct_answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %c.\n", 'A' + questions[i].correct_answer);
        }
    }
    printf("Congratulations! You have scored %d out of %d.\n", score, num_questions);
    return 0;
}