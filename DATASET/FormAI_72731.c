//FormAI DATASET v1.0 Category: Online Examination System ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_QUESTIONS 50
#define MAX_OPTIONS 4

//Structure to hold question and its answer options
typedef struct {
    char question[100];
    char options[MAX_OPTIONS][50];
    int correctOption;
} Question;

//Function to shuffle an array of integers
void shuffle(int *arr, int n) {
    srand(time(NULL));
    for(int i=n-1; i>0; i--) {
        int j = rand() % (i+1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    //Initialize questions
    Question questions[MAX_QUESTIONS];
    strcpy(questions[0].question, "Which is the largest planet in our solar system?");
    strcpy(questions[0].options[0], "Earth");
    strcpy(questions[0].options[1], "Venus");
    strcpy(questions[0].options[2], "Jupiter");
    strcpy(questions[0].options[3], "Mars");
    questions[0].correctOption = 2;

    strcpy(questions[1].question, "Who painted the Mona Lisa?");
    strcpy(questions[1].options[0], "Leonardo da Vinci");
    strcpy(questions[1].options[1], "Pablo Picasso");
    strcpy(questions[1].options[2], "Vincent van Gogh");
    strcpy(questions[1].options[3], "Claude Monet");
    questions[1].correctOption = 0;

    //Add more questions (up to MAX_QUESTIONS)

    //Initialize variables
    int score = 0;
    int attemptedQuestions[MAX_QUESTIONS];
    for(int i=0; i<MAX_QUESTIONS; i++) {
        attemptedQuestions[i] = 0;
    }

    //Start exam
    printf("*** Welcome to the Online Examination System ***\n\n");

    int i=0;
    while(i < MAX_QUESTIONS) {
        //Select a random unattempted question
        int questionIndex = rand() % MAX_QUESTIONS;
        while(attemptedQuestions[questionIndex] == 1) {
            questionIndex = rand() % MAX_QUESTIONS;
        }

        attemptedQuestions[questionIndex] = 1;
        i++;

        //Prompt user for answer
        printf("Q%d. %s\n", i, questions[questionIndex].question);
        int optionIndices[MAX_OPTIONS] = {0, 1, 2, 3};
        shuffle(optionIndices, MAX_OPTIONS);

        for(int j=0; j<MAX_OPTIONS; j++) {
            printf("%d. %s\n", j+1, questions[questionIndex].options[optionIndices[j]]);
        }

        printf("Enter your answer (1-4): ");
        int answer;
        scanf("%d", &answer);

        if(answer == questions[questionIndex].correctOption+1) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong. The correct answer is %s\n\n", questions[questionIndex].options[questions[questionIndex].correctOption]);
        }
    }

    //Display final score
    printf("Exam Complete! You scored %d out of %d.\n", score, MAX_QUESTIONS);

    return 0;
}