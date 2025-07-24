//FormAI DATASET v1.0 Category: Spam Detection System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPAM_WORDS 100
#define MAX_SPAM_SCORE 10

char spam_words[MAX_SPAM_WORDS][50] = {"free", "money back", "click here", "limited time offer", "discount", "prize", "win", "act now", "no investment", "cash", "autographed", "for only", "special promotion", "offer ends", "supplies running out", "double your", "earn", "extra income", "get paid", "incredible offer", "make money", "million", "risk free", "satisfaction guaranteed", "save big", "winner", "compare", "debt", "lower rate", "mortgage", "refinance", "consolidate", "fast cash", "hidden", "income", "investment", "loans", "remove", "stop", "trial"};

int spam_scores[MAX_SPAM_WORDS] = {2, 5, 3, 4, 2, 6, 5, 4, 4, 6, 6, 3, 4, 5, 5, 5, 6, 5, 5, 3, 6, 7, 3, 7, 5, 6, 4, 5, 6, 6, 6, 5, 4, 5, 6, 4, 4, 4, 5, 5, 7, 7};

int main()
{
    char input[10000];
    int scores[MAX_SPAM_WORDS];
    int total_score = 0;
    int spam_counter = 0;

    printf("Enter your message:\n");
    fgets(input, sizeof(input), stdin);

    for (int i = 0; i < MAX_SPAM_WORDS; i++)
    {
        scores[i] = 0;
    }

    char *word = strtok(input, " ,.-\n");

    while (word != NULL)
    {
        for (int i = 0; i < MAX_SPAM_WORDS; i++)
        {
            if (strcmp(word, spam_words[i]) == 0)
            {
                scores[i] += spam_scores[i];
            }
        }
        word = strtok(NULL, " ,.-\n");
    }

    for (int i = 0; i < MAX_SPAM_WORDS; i++)
    {
        if (scores[i] > 0)
        {
            spam_counter++;
            total_score += scores[i];
        }
    }

    if (spam_counter > 0 && total_score >= MAX_SPAM_SCORE)
    {
        printf("The message you entered is identified as spam.\n");
    }
    else
    {
        printf("The message you entered is not identified as spam.\n");
    }

    return 0;
}