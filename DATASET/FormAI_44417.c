//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define responses for fortune-telling
char *responses[] = {
    "It is certain.",
    "It is decidedly so.",
    "Without a doubt",
    "Yes, definitely.",
    "You may rely on it.",
    "As I see it, yes.",
    "Most likely.",
    "Outlook good.",
    "Yes.",
    "Signs point to yes.",
    "Reply hazy, try again.",
    "Ask again later.",
    "Better not tell you now.",
    "Cannot predict now.",
    "Concentrate and ask again.",
    "Don't count on it.",
    "Outlook not so good.",
    "My sources say no.",
    "Very doubtful."
};

// Function to randomly select a response
char* getResponse() {
    srand((unsigned int)time(NULL)); // seed the random number generator
    int index = rand() % 19; // get random index for response array
    return responses[index]; // return the corresponding response
}

int main() {
    printf("Welcome to the Automated Fortune Teller. Please ask a yes/no question:\n");
    char question[100]; // create a buffer for the user's input
    fgets(question, 100, stdin); // get user input from console

    printf("You asked: %s\n", question);
    printf("The answer is: %s\n", getResponse()); // get and print a random response

    return 0;
}