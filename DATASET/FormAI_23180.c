//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Welcome Message
    printf("Welcome to the post-apocalyptic periodic table quiz!\n\n");

    // Initializing Variables and Arrays
    int score = 0;
    int num_ques = 10;
    int ques_list[] = {6, 16, 29, 42, 51, 63, 74, 79, 88, 96};
    char symbols[][3] = {"C", "S", "Cu", "Mo", "Sb", "Eu", "W", "Au", "Ra", "Cm"};
    char resp[2];
    
    // Randomizing Questions
    srand(time(0));
    for (int i = 0; i < 50; i++)
    {
        int random_index = rand() % 10;
        int temp = ques_list[0];
        ques_list[0] = ques_list[random_index];
        ques_list[random_index] = temp;
    }

    // Asking Questions and Evaluating Answers
    for (int i = 0; i < num_ques; i++)
    {
        printf("\nQuestion %d:\n", i+1);
        printf("What is the symbol for element %d?\n", ques_list[i]);
        scanf("%1s", resp);

        if (resp[0] == symbols[i][0] && resp[1] == symbols[i][1]) // Checking if Answer is Correct
        {
            printf("Correct!\n");
            score++;
        }

        else // If Answer is Incorrect
            printf("Incorrect. The correct answer is %s.\n", symbols[i]);
    }

    // Displaying Final Score and Message
    printf("\nQuiz completed.\n");
    printf("Final Score: %d/%d\n", score, num_ques);

    if (score == num_ques)
        printf("Congratulations, you have successfully navigated the post-apocalyptic periodic table!\n");

    else
        printf("Better luck next time! Stay safe out there.\n");

    return 0;
}