//FormAI DATASET v1.0 Category: Spam Detection System ; Style: surprised
#include <stdio.h>
#include <string.h>

int main()
{
    printf("Welcome to the C Spam Detection System!\n");

    char spamWords[10][20] = {"money", "free", "cialis", "viagra", "online", "discount", "investment", "opportunity", "limited", "offer"};

    char message[1000];
    printf("Please enter your message:\n");
    fgets(message, 1000, stdin);

    int count = 0;
    char *substr;
    for (int i = 0; i < 10; i++)
    {
        substr = strstr(message, spamWords[i]);
        if (substr != NULL)
        {
            count++;
        }
    }

    if (count > 0)
    {
        printf("Warning! This message contains %d spam words.\n", count);
        printf("Please revise your message and try again.\n");
    }
    else
    {
        printf("Great news! Your message passed the spam filter.\n");
        printf("Sending message...\n");
        // Insert code to send message here
        printf("Message sent successfully!\n");
    }
    return 0;
}