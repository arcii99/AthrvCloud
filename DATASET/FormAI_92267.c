//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char* answers[] = {"Yes", "No", "Maybe", "Outlook not so good", "Definitely", "Ask again later", "Signs point to yes", "Cannot predict now", "Better not tell you now"};
    int num_answers = sizeof(answers)/sizeof(answers[0]);
    char question[256];

    printf("Welcome to the Automated Fortune Teller\n");
    printf("Please ask your question, or type 'quit' to exit.\n");

    while(1) {
        printf("\n> ");
        fgets(question, sizeof(question), stdin);
        question[strcspn(question, "\n")] = 0; // remove trailing newline

        if(strcmp(question, "quit") == 0) {
            break;
        }

        // generate random answer
        srand(time(NULL)); // seed the random number generator
        int index = rand() % num_answers;
        printf("%s\n", answers[index]);
    }

    printf("Thank you for using the Automated Fortune Teller!\n");

    return 0;
}