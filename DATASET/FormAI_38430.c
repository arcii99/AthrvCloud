//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char answers[10][100] = {"It is certain", "Without a doubt", "You may rely on it", "Yes definitely", "It is decidedly so", 
                             "As I see it, yes", "Most likely", "Outlook good", "Yes", "Signs point to yes"};
    char questions[5][100] = {"What is my future?", "Will I get a job soon?", "Will I find true love?", "Should I make a big change?", "What should I do next?"};

    srand(time(0));

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Ask me any question and I will give you the answer.\n");
    printf("Type 'quit' to end the program.\n");

    while(1) {
        char input[100];
        printf("\nAsk me a question: ");
        fgets(input, 100, stdin);

        if(strcmp(input, "quit\n") == 0) {
            printf("Goodbye!\n");
            break;
        }

        int random_answer = rand() % 10;
        printf("\nYour question is: %s", questions[random_answer % 5]);
        printf("Thinking...\n");
        sleep(2);

        printf("Your answer is: %s\n", answers[random_answer]);
    }

    return 0;
}