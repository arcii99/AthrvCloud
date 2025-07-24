//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Automated Fortune Teller!\n\n");
    printf("Think of a question, any question, and I will give you an answer!\n\n");

    // Set up an array of possible answers
    char *answers[] = {
        "It is certain",
        "Without a doubt",
        "You may rely on it",
        "Yes, definitely",
        "It is decidedly so",
        "As I see it, yes",
        "Most likely",
        "Yes",
        "Outlook good",
        "Signs point to yes",
        "Reply hazy, try again",
        "Better not tell you now",
        "Ask again later",
        "Cannot predict now",
        "Concentrate and ask again",
        "Don't count on it",
        "Outlook not so good",
        "My sources say no",
        "Very doubtful",
        "My reply is no"
    };

    // Seed the random number generator
    srand(time(NULL));

    // Get a random answer from the array and output it
    int index = rand() % 20;
    printf("%s\n", answers[index]);

    return 0;
}