//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char *phrases[] = {"It is certain", "Without a doubt", "You may rely on it", "Yes, definitely", "It is decidedly so", "As I see it, yes", "Most likely", "Yes", "Outlook good", "Signs point to yes", "Reply hazy, try again", "Better not tell you now", "Ask again later", "Cannot predict now", "Concentrate and ask again", "Don't count on it", "Outlook not so good", "My sources say no", "Very doubtful", "My reply is no"};
    int response = 1;

    srand(time(NULL));

    while (response)
    {
        printf("Ask me any question: ");

        // Clear input buffer
        fflush(stdin);

        // Get question from user
        char question[256];
        fgets(question, sizeof(question), stdin);

        if (question[strlen(question) - 1] == '\n')
            question[strlen(question) - 1] = '\0';  // Remove newline character

        // Randomly generate and display fortune
        int i = rand() % 20;
        printf("\n%s\n\n", phrases[i]);

        // Ask user if they want to ask another question
        printf("Do you want to ask another question? (1/0): ");
        scanf("%d", &response);
    }

    return 0;
}