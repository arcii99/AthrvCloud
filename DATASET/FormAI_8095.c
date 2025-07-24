//FormAI DATASET v1.0 Category: Online Examination System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TOTAL_QUESTIONS 5
#define TOTAL_OPTIONS 4

typedef struct {
    char question[100];
    char options[TOTAL_OPTIONS][50];
    int answer;
} Question;

void startExam(Question* questions);
void shuffleOptions(char options[][50], int correctOption);
void askQuestion(Question question);
void displayResult(int score);

int main() {
    srand(time(NULL)); // Seed random number generator

    // Define question array
    Question questions[TOTAL_QUESTIONS] = {
        {"What is the capital of India?", {"Delhi", "Mumbai", "Chennai", "Kolkata"}, 0},
        {"What is the largest country in the world?", {"Russia", "Canada", "China", "USA"}, 0},
        {"Who was the first Indian woman in space?", {"Kalpana Chawla", "Sunita Williams", "Indira Gandhi", "Pratibha Patil"}, 0},
        {"What is the highest peak in the world?", {"Mount Everest", "K2", "Kangchenjunga", "Lhotse"}, 0},
        {"What is the currency of Japan?", {"Yen", "Dollar", "Euro", "Pound"}, 0}
    };

    startExam(questions); // Start the exam

    return 0;
}

void startExam(Question* questions) {
    int score = 0;

    printf("Welcome to the Online Examination!\n\n");
    printf("You will be asked a series of questions. Please choose the correct answer from the given options.\n\n");

    for (int i = 0; i < TOTAL_QUESTIONS; i++) {
        shuffleOptions(questions[i].options, questions[i].answer);
        askQuestion(questions[i]);

        int userAnswer;
        scanf("%d", &userAnswer);

        if (userAnswer == questions[i].answer) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect! The correct answer is %s.\n", questions[i].options[questions[i].answer]);
        }
    }

    displayResult(score);
}

void shuffleOptions(char options[][50], int correctOption) {
    // swap correctOption with a random option
    int randomIndex = rand() % TOTAL_OPTIONS;
    char temp[50];
    strcpy(temp, options[correctOption]);
    strcpy(options[correctOption], options[randomIndex]);
    strcpy(options[randomIndex], temp);
}

void askQuestion(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < TOTAL_OPTIONS; i++) {
        printf("%d. %s\n", i+1, question.options[i]);
    }
    printf("Enter your answer: ");
}

void displayResult(int score) {
    printf("\nYou have completed the exam! Your score is %d out of %d.\n\n", score, TOTAL_QUESTIONS);
    if (score == TOTAL_QUESTIONS) {
        printf("Congratulations! You have passed with flying colors.\n");
    } else if (score >= 3) {
        printf("Good job! You have passed the exam.\n");
    } else {
        printf("Sorry, you have not passed the exam. Better luck next time.\n");
    }
}