//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Automated Fortune Teller! \n");
    printf("Ask me a question and I will give you an answer. \n");

    // seed random number generator
    srand(time(NULL));

    // array of possible answers
    char* answers[] = {
        "It is certain.",
        "Without a doubt.",
        "You may rely on it.",
        "Yes, definitely.",
        "It is decidedly so.",
        "As I see it, yes.",
        "Most likely.",
        "Yes.",
        "Outlook good.",
        "Signs point to yes.",
        "Reply hazy, try again.",
        "Better not tell you now.",
        "Ask again later.",
        "Cannot predict now.",
        "Concentrate and ask again.",
        "Don't count on it.",
        "Outlook not so good.",
        "My sources say no.",
        "Very doubtful.",
        "My reply is no."
    };

    // generate random index and print answer
    int index = rand() % 20;
    printf("\n%s\n", answers[index]);

    return 0;
}