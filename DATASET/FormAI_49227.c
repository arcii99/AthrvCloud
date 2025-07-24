//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_QUESTIONS 10 // maximum number of questions in the quiz

/* Function Declarations */
void askQuestion(int questionNumber, int *score); // function to ask each question
void generateQuestions(int *questionList); // function to generate the order of questions
void displayScore(int score); // function to display the final score

/* Main function */
int main()
{
    int questionList[MAX_QUESTIONS]; // array to hold the order of questions
    int score = 0; // score variable
    srand(time(0)); // seed the random number generator

    printf("---- Welcome to the Periodic Table Quiz! ----\n\n");

    // generate the order of questions
    generateQuestions(questionList);

    // ask each question and update the score
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        askQuestion(questionList[i], &score);
    }

    // display the final score
    displayScore(score);

    return 0;
}

/* Function to ask each question */
void askQuestion(int questionNumber, int *score)
{
    char answer[20]; // array to hold the user's answer
    char correct[20]; // array to hold the correct answer

    switch (questionNumber)
    {
        case 1:
            printf("Question 1: What is the symbol for Carbon? ");
            gets(answer);
            strcpy(correct, "C");
            break;

        case 2:
            printf("Question 2: What is the atomic number of Oxygen? ");
            gets(answer);
            strcpy(correct, "8");
            break;

        case 3:
            printf("Question 3: What is the symbol for Sodium? ");
            gets(answer);
            strcpy(correct, "Na");
            break;

        case 4:
            printf("Question 4: What is the atomic number of Nitrogen? ");
            gets(answer);
            strcpy(correct, "7");
            break;

        case 5:
            printf("Question 5: What is the symbol for Iron? ");
            gets(answer);
            strcpy(correct, "Fe");
            break;

        case 6:
            printf("Question 6: What is the atomic number of Neon? ");
            gets(answer);
            strcpy(correct, "10");
            break;

        case 7:
            printf("Question 7: What is the symbol for Hydrogen? ");
            gets(answer);
            strcpy(correct, "H");
            break;

        case 8:
            printf("Question 8: What is the atomic number of Calcium? ");
            gets(answer);
            strcpy(correct, "20");
            break;

        case 9:
            printf("Question 9: What is the symbol for Potassium? ");
            gets(answer);
            strcpy(correct, "K");
            break;

        case 10:
            printf("Question 10: What is the atomic number of Copper? ");
            gets(answer);
            strcpy(correct, "29");
            break;

        default:
            break;
    }

    // check if the answer is correct and update the score
    if (strcmp(answer, correct) == 0)
    {
        printf("Correct! Well done!\n");
        (*score)++;
    }
    else
    {
        printf("Incorrect. The correct answer is %s.\n", correct);
    }

    printf("\n");
}

/* Function to generate the order of questions */
void generateQuestions(int *questionList)
{
    int i, j, temp;

    // initialize the array with the question numbers
    for (i = 0; i < MAX_QUESTIONS; i++)
    {
        questionList[i] = i + 1;
    }

    // shuffle the array using the Fisher-Yates algorithm
    for (i = MAX_QUESTIONS - 1; i > 0; i--)
    {
        j = rand() % (i + 1);
        temp = questionList[i];
        questionList[i] = questionList[j];
        questionList[j] = temp;
    }
}

/* Function to display the final score */
void displayScore(int score)
{
    printf("---- Quiz Complete ----\n");
    printf("Final Score: %d/%d\n\n", score, MAX_QUESTIONS);
    if (score == MAX_QUESTIONS)
    {
        printf("Congratulations! You got a perfect score!\n");
    }
    else if (score > MAX_QUESTIONS/2)
    {
        printf("Well done! You passed the quiz.\n");
    }
    else
    {
        printf("Sorry, you did not pass the quiz. Better luck next time!\n");
    }
}