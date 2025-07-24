//FormAI DATASET v1.0 Category: Online Examination System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure to store the questions, options and solutions
struct Question
{
    char question[100];
    char options[4][40];
    int answer;
};

//function to initialize the questions
void initQuestions(struct Question *questions)
{
    strcpy(questions[0].question, "What is the capital of India?");
    strcpy(questions[0].options[0], "Delhi");
    strcpy(questions[0].options[1], "Mumbai");
    strcpy(questions[0].options[2], "Kolkata");
    strcpy(questions[0].options[3], "Chennai");
    questions[0].answer = 0;

    strcpy(questions[1].question, "Who is the author of Harry Potter book series?");
    strcpy(questions[1].options[0], "Mark Twain");
    strcpy(questions[1].options[1], "J.K. Rowling");
    strcpy(questions[1].options[2], "Agatha Christie");
    strcpy(questions[1].options[3], "George Orwell");
    questions[1].answer = 1;

    strcpy(questions[2].question, "What is the currency of Japan?");
    strcpy(questions[2].options[0], "Yuan");
    strcpy(questions[2].options[1], "Won");
    strcpy(questions[2].options[2], "Yen");
    strcpy(questions[2].options[3], "Ruble");
    questions[2].answer = 2;

    strcpy(questions[3].question, "Who was the first president of the United States?");
    strcpy(questions[3].options[0], "Thomas Jefferson");
    strcpy(questions[3].options[1], "George Washington");
    strcpy(questions[3].options[2], "Abraham Lincoln");
    strcpy(questions[3].options[3], "John Adams");
    questions[3].answer = 1;

    strcpy(questions[4].question, "What is the largest planet in our solar system?");
    strcpy(questions[4].options[0], "Venus");
    strcpy(questions[4].options[1], "Mars");
    strcpy(questions[4].options[2], "Jupiter");
    strcpy(questions[4].options[3], "Saturn");
    questions[4].answer = 2;

    strcpy(questions[5].question, "What is the capital of Australia?");
    strcpy(questions[5].options[0], "Melbourne");
    strcpy(questions[5].options[1], "Sydney");
    strcpy(questions[5].options[2], "Canberra");
    strcpy(questions[5].options[3], "Brisbane");
    questions[5].answer = 2;
}

//function to display the questions and options
void displayQuestion(struct Question question)
{
    printf("\n%s\n", question.question);
    printf("A. %s\n", question.options[0]);
    printf("B. %s\n", question.options[1]);
    printf("C. %s\n", question.options[2]);
    printf("D. %s\n", question.options[3]);
}

int main()
{
    struct Question questions[6];
    int userAnswer, score = 0;

    initQuestions(questions); //initialize the questions

    printf("\t***Welcome to the Online Examination System***\n");
    printf("\t-----------------------------------------------\n");

    for(int i = 0; i < 6; i++) //loop through all the questions
    {
        printf("\nQuestion %d:", i+1);
        displayQuestion(questions[i]); //display the current question

        printf("\nEnter your answer (A/B/C/D): ");
        scanf(" %c", &userAnswer);

        if(userAnswer == 'a' || userAnswer == 'A')
        {
            if(questions[i].answer == 0)
            {
                printf("\nCorrect Answer!");
                score++; //increment score if answer is correct
            }
            else
                printf("\nWrong Answer!");
        }
        else if(userAnswer == 'b' || userAnswer == 'B')
        {
            if(questions[i].answer == 1)
            {
                printf("\nCorrect Answer!");
                score++;
            }
            else
                printf("\nWrong Answer!");
        }
        else if(userAnswer == 'c' || userAnswer == 'C')
        {
            if(questions[i].answer == 2)
            {
                printf("\nCorrect Answer!");
                score++;
            }
            else
                printf("\nWrong Answer!");
        }
        else if(userAnswer == 'd' || userAnswer == 'D')
        {
            if(questions[i].answer == 3)
            {
                printf("\nCorrect Answer!");
                score++;
            }
            else
                printf("\nWrong Answer!");
        }
        else
        {
            printf("\nInvalid Option!");
            i--; //decrement i so that current question is asked again
        }
    }

    printf("\n\nYour Score: %d/6\n", score); //display the score

    return 0;
}