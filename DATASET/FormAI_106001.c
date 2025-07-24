//FormAI DATASET v1.0 Category: Spam Detection System ; Style: innovative
#include<stdio.h>
#include<string.h>

int main()
{
    char text[100];
    int i, j, spam_count = 0;
    double spam_percentage;

    printf("Enter message to check for spam: ");
    fgets(text, 100, stdin);

    char spam_words[5][15] = { "offer", "win", "prize", "free", "discount" };

    for(i = 0; text[i] != '\0'; i++)
    {
        if(text[i] == ' ')
        {
            char temp[15];
            int temp_len;
            for(j = i + 1; text[j] != ' ' && text[j] != '\0'; j++)
            {
                temp_len = j - i - 1;
                temp[temp_len] = tolower(text[j]);
                temp[temp_len+1] = '\0';
            }

            for(j = 0; j < 5; j++)
            {
                if(strcmp(temp, spam_words[j]) == 0)
                {
                    spam_count++;
                }
            }
        }
    }

    spam_percentage = ((double)spam_count / (double)i) * 100;

    printf("\n");

    if(spam_percentage >= 30)
    {
        printf("SPAM DETECTED!! Your message contains %d spam words.\n", spam_count);
    }
    else
    {
        printf("Your message is free from spam.\n");
    }

    return 0;
}