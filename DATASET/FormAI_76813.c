//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    char question[100];
    printf("Welcome to the automated fortune teller!\nAsk me any yes/no question and I'll give you an answer.\n");
    printf("What is your question?\n");
    scanf("%[^\n]%*c", question); // Reads the entire line of input

    // Setting up the random generator
    srand(time(NULL)); 
    int answer = rand() % 10;

    // Initializing the possible answers
    char *responses[] = {
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

    printf("\nThinking...\n\n");

    // Delaying the response for dramatic effect
    for (int i = 1; i <= 100000000; i++){}

    printf("%s\n", responses[answer]);

    return 0;
}