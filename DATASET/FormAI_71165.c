//FormAI DATASET v1.0 Category: Online Examination System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i, j, temp, score = 0;
    int answer[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int response[10];

    // Generating random questions
    srand(time(NULL));
    for (i = 0; i < 10; i++)
    {
        n = rand() % 3;
        switch(n)
        {
            case 0:
                printf("What is the value of 2+2?\n");
                answer[i] = 4;
                break;
            case 1:
                printf("Who is the first president of the United States?\n");
                answer[i] = 1;
                break;
            case 2:
                printf("What is the capital city of France?\n");
                answer[i] = 2;
                break;
        }
        scanf("%d", &response[i]);
    }

    // Counting the score
    for (i = 0; i < 10; i++)
    {
        if (response[i] == answer[i])
            score++;
    }

    printf("Your score is %d out of 10.\n", score);

    return 0;
}