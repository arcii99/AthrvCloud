//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    printf("Welcome to the Automated Fortune Teller program!\n\n");
    printf("Think of your question and press enter to know your answer!\n");

    char question[256];
    fgets(question, 256, stdin);

    srand(time(NULL));
    int fortune_num = rand() % 10;

    char fortune[10][256] = {"It is certain.", "It is decidedly so.", "Without a doubt.", "Yes - definitely.", "You may rely on it.",
                             "As I see it, yes.", "Most likely.", "Outlook good.", "Yes.", "Signs point to yes."};

    printf("\nYour answer is:\n%s\n", fortune[fortune_num]);

    return 0;
}