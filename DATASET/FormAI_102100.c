//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initializing the random number generator
    time_t t;
    srand((unsigned) time(&t));
    
    // Getting user's question
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Ask me a question and I'll give you an answer: ");
    char question[100];
    fgets(question, 100, stdin);
    
    // Generating random fortune
    int fortune = rand() % 8;
    char* answer;
    switch(fortune) {
        case 0:
            answer = "It is certain.";
            break;
        case 1:
            answer = "Without a doubt.";
            break;
        case 2:
            answer = "You may rely on it.";
            break;
        case 3:
            answer = "Yes, definitely.";
            break;
        case 4:
            answer = "It is decidedly so.";
            break;
        case 5:
            answer = "As I see it, yes.";
            break;
        case 6:
            answer = "Most likely.";
            break;
        case 7:
            answer = "Outlook good.";
            break;
        default:
            answer = "Error: Invalid fortune.";
    }
    
    // Print the fortune
    printf("The answer to your question \"%s\" is:\n%s\n", question, answer);
    
    return 0;
}