//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char input[100];
    printf("Welcome to the Happy Sentiment Analysis Tool!\n");
    printf("Enter a sentence and we'll tell you how happy it is: ");
    fgets(input, 100, stdin);

    int score = 0;
    int i = 0;
    while (input[i] != '\0')
    {
        if (input[i] == 'h' || input[i] == 'H')
        {
            score += 10;
        }
        else if (input[i] == 'a' || input[i] == 'A')
        {
            score += 5;
        }
        else if (input[i] == 'p' || input[i] == 'P')
        {
            score += 3;
        }
        else if (input[i] == 'y' || input[i] == 'Y')
        {
            score += 5;
        }

        i++;
    }

    printf("Your sentence has a happiness score of %d out of 100.\n", score);
    if (score >= 80)
    {
        printf("Wow, your sentence is so happy! Keep on spreading the joy!\n");
    }
    else if (score >= 50)
    {
        printf("Your sentence is pretty happy, but there's always room for improvement. Keep smiling!\n");
    }
    else
    {
        printf("Your sentence could use a little more happiness. Don't worry, we all have bad days. Let's work on spreading more joy together!\n");
    }

    return 0;
}