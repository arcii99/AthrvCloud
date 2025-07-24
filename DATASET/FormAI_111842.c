//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i, j, k, score = 0, correct = 0, incorrect = 0;
    char input;
    char words[10][20] = {"university", "computer", "language", "keyboard", "chair", "book", "student", "desk", "monitor", "teacher"};
    srand(time(NULL));
    printf("Welcome to the Typing Speed Test Program!\n");
    printf("You will be presented with 10 random words and need to type them correctly as fast as possible.\n");
    printf("Press ENTER to begin.\n");
    getchar();
    for(i=0; i<10; i++)
    {
        printf("\n\n%s\n", words[i]);
        clock_t start = clock();
        j = 0;
        do
        {
            input = getchar();
            if(input != words[i][j])
            {
                incorrect++;
            }
            else
            {
                correct++;
            }
            j++;
        } while(input != '\n');
        clock_t end = clock();
        double time_taken = ((double)end-start)/CLOCKS_PER_SEC;
        printf("\nTime taken: %lf seconds\n", time_taken);
        if(time_taken < 3.0)
        {
            score += 10;
        }
        else if(time_taken < 5.0)
        {
            score += 5;
        }
        else
        {
            score += 1;
        }
    }
    printf("\n\nTyping Speed Test Complete!\n\n");
    printf("Correct: %d words\n", correct);
    printf("Incorrect: %d words\n", incorrect);
    printf("Score: %d\n\n", score);
    return 0;
}