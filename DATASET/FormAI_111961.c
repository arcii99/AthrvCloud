//FormAI DATASET v1.0 Category: Online Examination System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct for storing questions and answers
typedef struct {
    char question[100];
    char answer[50];
} Question;

//Function to display the questions and receive the answers from user
void display_questions(Question *questions, int num_questions)
{
    char input[50];
    int score = 0;

    for (int i = 0; i < num_questions; i++)
    {
        printf("\nQuestion %d: %s\n", i+1, questions[i].question);
        printf("Answer: ");
        scanf("%s", input);

        //If the answer is correct, increment score
        if (strcmp(input, questions[i].answer) == 0)
            score++;
    }

    printf("\n\nCongratulations! You have completed the exam.\n");
    printf("Your score: %d/%d\n", score, num_questions);
}

int main()
{
    //Creating questions and storing them in an array
    Question questions[5];
    strcpy(questions[0].question,"What is the capital of India?");
    strcpy(questions[0].answer,"New Delhi");
    strcpy(questions[1].question,"What is the currency of Japan?");
    strcpy(questions[1].answer,"Yen");
    strcpy(questions[2].question,"What is the largest continent?");
    strcpy(questions[2].answer,"Asia");
    strcpy(questions[3].question,"What is the smallest country in the world?");
    strcpy(questions[3].answer,"Vatican City");
    strcpy(questions[4].question,"What is the national animal of Australia?");
    strcpy(questions[4].answer,"Kangaroo");

    printf("Welcome to the C Online Examination System!\n");
    printf("You will be presented with 5 multiple choice questions.\n");
    printf("Please type your answer as a single word without spaces.\n\n");

    //Displaying the questions and receiving answers
    display_questions(questions, 5);

    return 0;
}