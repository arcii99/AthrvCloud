//FormAI DATASET v1.0 Category: Spam Detection System ; Style: creative
#include<stdio.h>
#include<string.h>

int main()
{
    char spam[100];
    int count = 0;
    printf("Enter the text:\n");
    fgets(spam, 100, stdin);

    char *spam_words[10] = {"Free", "Discount", "Subscribe", "Offer", "Limited", "Exclusive", "Act now", "Click here", "Extra income", "Double your"};
    int spam_score = 0;

    for(int i=0; i<10; i++)
    {
        if(strstr(spam, spam_words[i]) != NULL)
        {
            spam_score++;
        }
    }

    if(spam_score >= 5)
    {
        printf("The mail you entered is a spam mail.\n");
    }
    else
    {
        printf("The mail you entered is not a spam mail.\n");
    }

    return 0;
}