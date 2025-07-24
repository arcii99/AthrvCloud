//FormAI DATASET v1.0 Category: Online Examination System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_OF_QUESTIONS 5
#define QUESTION_LENGTH 100
#define NUM_OF_OPTIONS 4

/* A struct to represent a single question */
struct Question
{
    char question[QUESTION_LENGTH];
    char options[NUM_OF_OPTIONS][QUESTION_LENGTH];
    int correct_option;
};

/* A function to display a single question */
void display_question(struct Question q)
{
    printf("\n%s\n", q.question);
    for(int i = 0; i < NUM_OF_OPTIONS; i++)
    {
        printf("%d. %s\n", i+1, q.options[i]);
    }
}

/* A function to get user's answer to a question */
int get_answer()
{
    int answer;
    printf("Enter your answer: ");
    scanf("%d", &answer);
    return answer;
}

/* A function to check if the user's answer is correct */
int verify_answer(struct Question q, int answer)
{
    if(answer == q.correct_option)
        return 1;
    else
        return 0;
}

int main()
{
    struct Question questions[NUM_OF_QUESTIONS];

    /* Populate the array of questions */
    strcpy(questions[0].question, "What is the capital of India?");
    strcpy(questions[0].options[0], "Mumbai");
    strcpy(questions[0].options[1], "Delhi");
    strcpy(questions[0].options[2], "Chennai");
    strcpy(questions[0].options[3], "Kolkata");
    questions[0].correct_option = 2;

    strcpy(questions[1].question, "Which is the largest city in the world by population?");
    strcpy(questions[1].options[0], "Shanghai");
    strcpy(questions[1].options[1], "Tokyo");
    strcpy(questions[1].options[2], "Delhi");
    strcpy(questions[1].options[3], "Beijing");
    questions[1].correct_option = 1;

    strcpy(questions[2].question, "Who is the founder of Microsoft?");
    strcpy(questions[2].options[0], "Steve Jobs");
    strcpy(questions[2].options[1], "Bill Gates");
    strcpy(questions[2].options[2], "Steve Wozniak");
    strcpy(questions[2].options[3], "Linus Torvalds");
    questions[2].correct_option = 2;

    strcpy(questions[3].question, "What is the full form of RAM?");
    strcpy(questions[3].options[0], "Random Access Memory");
    strcpy(questions[3].options[1], "Read Access Memory");
    strcpy(questions[3].options[2], "Reset Access Memory");
    strcpy(questions[3].options[3], "Recursive Access Memory");
    questions[3].correct_option = 1;

    strcpy(questions[4].question, "Which is the first programming language developed?");
    strcpy(questions[4].options[0], "Fortran");
    strcpy(questions[4].options[1], "Cobol");
    strcpy(questions[4].options[2], "C");
    strcpy(questions[4].options[3], "Java");
    questions[4].correct_option = 1;

    /* Display each question and get answer from the user */
    int score = 0;
    for(int i = 0; i < NUM_OF_QUESTIONS; i++)
    {
        display_question(questions[i]);
        int answer = get_answer();

        if(verify_answer(questions[i], answer))
        {
            printf("Correct answer!\n");
            score++;
        }
        else
        {
            printf("Wrong answer! The correct answer is option %d\n", questions[i].correct_option);
        }
    }

    /* Display the final score */
    printf("\nYour final score is %d out of %d\n", score, NUM_OF_QUESTIONS);

    return 0;
}