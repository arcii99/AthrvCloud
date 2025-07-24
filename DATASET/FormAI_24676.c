//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int score=0;

    printf("Welcome to the C Periodic Table Quiz!\n");

    printf("\nQuestion 1:\nWhat is the symbol for Oxygen?\n");
    char answer1[2];
    scanf("%1s", answer1);
    char correct_answer1[]="O";
    if(answer1[0]==correct_answer1[0]){
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is %s.\n", correct_answer1);
    }

    printf("\nQuestion 2:\nWhat is the symbol for Sodium?\n");
    char answer2[2];
    scanf("%1s", answer2);
    char correct_answer2[]="Na";
    if(answer2[0]==correct_answer2[0] && answer2[1]==correct_answer2[1]){
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is %s.\n", correct_answer2);
    }

    printf("\nQuestion 3:\nWhat is the symbol for Iron?\n");
    char answer3[2];
    scanf("%1s", answer3);
    char correct_answer3[]="Fe";
    if(answer3[0]==correct_answer3[0] && answer3[1]==correct_answer3[1]){
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is %s.\n", correct_answer3);
    }

    printf("\nQuestion 4:\nWhat is the symbol for Gold?\n");
    char answer4[2];
    scanf("%1s", answer4);
    char correct_answer4[]="Au";
    if(answer4[0]==correct_answer4[0] && answer4[1]==correct_answer4[1]){
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is %s.\n", correct_answer4);
    }

    printf("\nQuestion 5:\nWhat is the symbol for Carbon?\n");
    char answer5[2];
    scanf("%1s", answer5);
    char correct_answer5[]="C";
    if(answer5[0]==correct_answer5[0]){
        printf("Correct!\n");
        score++;
    } else {
        printf("Incorrect. The correct answer is %s.\n", correct_answer5);
    }

    printf("\n\nQuiz complete!\nYou scored %d out of 5.\n", score);
    if(score==5){
        printf("Congratulations, you scored full marks!\n");
    } else if(score>=3 && score<5){
        printf("Well done, you scored %d out of 5.\n", score);
    } else if(score>=1 && score<3){
        printf("Keep practising, you scored %d out of 5.\n", score);
    } else {
        printf("Better luck next time, you scored %d out of 5.\n", score);
    }

    return 0;
}