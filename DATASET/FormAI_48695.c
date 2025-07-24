//FormAI DATASET v1.0 Category: Online Examination System ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define the structure for each question
typedef struct
{
    char question[100];
    char optionA[50];
    char optionB[50];
    char optionC[50];
    char optionD[50];
    int answer;
} question_t;

// Define the structure for the student's test results
typedef struct
{
    int totalQuestions;
    int correctAnswers;
    int incorrectAnswers;
} result_t;

// Function to display the menu and get the user's choice
int menu()
{
    int choice;
    printf("----Welcome to the Online Examination System----\n\n");
    printf("1. Start Exam\n");
    printf("2. Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

// Function to start the exam
void startExam(question_t questions[], int numOfQuestions, result_t *result)
{
    int i, answer;
    printf("\n----Starting Exam----\n\n");
    result->totalQuestions = numOfQuestions;
    for(i = 0; i < numOfQuestions; i++)
    {
        printf("Question %d: %s\n", i+1, questions[i].question);
        printf("A. %s\n", questions[i].optionA);
        printf("B. %s\n", questions[i].optionB);
        printf("C. %s\n", questions[i].optionC);
        printf("D. %s\n", questions[i].optionD);
        printf("Enter your answer (A=1, B=2, C=3, D=4): ");
        scanf("%d", &answer);
        if(answer == questions[i].answer)
            result->correctAnswers++;
        else
            result->incorrectAnswers++;
    }
    printf("\n----Exam Completed!----\n\n");
    printf("Number of Correct Answers: %d\n", result->correctAnswers);
    printf("Number of Incorrect Answers: %d\n\n", result->incorrectAnswers);
}

int main()
{
    // Define the questions
    question_t questions[5];
    strcpy(questions[0].question, "What is the capital of France?");
    strcpy(questions[0].optionA, "London");
    strcpy(questions[0].optionB, "Paris");
    strcpy(questions[0].optionC, "Berlin");
    strcpy(questions[0].optionD, "Madrid");
    questions[0].answer = 2;

    strcpy(questions[1].question, "What is the largest country in the world?");
    strcpy(questions[1].optionA, "Canada");
    strcpy(questions[1].optionB, "Russia");
    strcpy(questions[1].optionC, "China");
    strcpy(questions[1].optionD, "United States");
    questions[1].answer = 2;

    strcpy(questions[2].question, "What is the capital of India?");
    strcpy(questions[2].optionA, "New Delhi");
    strcpy(questions[2].optionB, "Mumbai");
    strcpy(questions[2].optionC, "Kolkata");
    strcpy(questions[2].optionD, "Bangalore");
    questions[2].answer = 1;

    strcpy(questions[3].question, "What is the largest animal in the world?");
    strcpy(questions[3].optionA, "Elephant");
    strcpy(questions[3].optionB, "Giraffe");
    strcpy(questions[3].optionC, "Blue whale");
    strcpy(questions[3].optionD, "Kangaroo");
    questions[3].answer = 3;

    strcpy(questions[4].question, "What is the currency of Japan?");
    strcpy(questions[4].optionA, "Dollar");
    strcpy(questions[4].optionB, "Euro");
    strcpy(questions[4].optionC, "Yen");
    strcpy(questions[4].optionD, "Ruble");
    questions[4].answer = 3;

    int choice, numOfQuestions = 5;
    result_t result = {0};

    do
    {
        choice = menu();
        switch(choice)
        {
            case 1:
                startExam(questions, numOfQuestions, &result);
                break;
            case 2:
                printf("Exiting...\n\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    } while(choice != 2);

    return 0;
}