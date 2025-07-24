//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Setting up the random seed
    srand(time(NULL));

    // Defining the responses array
    char *responses[] = {
        "It is certain",
        "It is decidedly so",
        "Without a doubt",
        "Yes - definitely",
        "You may rely on it",
        "As I see it, yes",
        "Most likely",
        "Outlook good",
        "Yes",
        "Signs point to yes",
        "Reply hazy, try again",
        "Ask again later",
        "Better not tell you now",
        "Cannot predict now",
        "Concentrate and ask again",
        "Don't count on it",
        "Outlook not so good",
        "My sources say no",
        "Very doubtful"
    };

    // Generating a random number to select the response
    int index = rand() % 19;

    // Outputting the response
    printf("The fortune teller says: ");
    printf("%s\n", responses[index]);

    return 0;
}