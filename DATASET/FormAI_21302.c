//FormAI DATASET v1.0 Category: Spam Detection System ; Style: puzzling
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    char message[1000];
    printf("Enter your message: ");
    scanf("%[^\n]s", message);
    bool is_spam = false;
    char spam_words[5][15] = {"offer", "free", "money", "deal", "win"};
    for (int i = 0; i < strlen(message); i++)
    {
        if (message[i] == ' ')
        {
            char temp[15];
            int temp_index = 0;
            for (int j = i+1, k = 0; j < strlen(message) && message[j] != ' '; j++, k++)
            {
                temp[k] = message[j];
                temp_index++;
            }
            temp[temp_index] = '\0';
            for (int k = 0; k < 5; k++)
            {
                if (strcmp(temp, spam_words[k]) == 0)
                {
                    is_spam = true;
                    break;
                }
            }
        }
        if (is_spam)
        {
            printf("Warning! Your message contains spam words.");
            return 0;
        }
    }
    printf("Your message is clean!");
    return 0;
}