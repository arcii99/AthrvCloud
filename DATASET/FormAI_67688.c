//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    srand(time(NULL)); // initialize the random seed

    char question[100];
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Ask me a question...\n");
    fgets(question, sizeof(question), stdin); // get user input

    switch(rand() % 10) { // randomly generate a number between 0-9
        case 0:
            printf("The stars say yes!\n"); 
            break;
        case 1:
            printf("Outlook not so good...\n");
            break;
        case 2:
            printf("You may rely on it.\n");
            break;
        case 3:
            printf("Don't count on it.\n");
            break;
        case 4:
            printf("My sources say no.\n");
            break;
        case 5:
            printf("It is certain.\n");
            break;
        case 6:
            printf("Better not tell you now.\n");
            break;
        case 7:
            printf("Signs point to yes.\n");
            break;
        case 8:
            printf("Cannot predict now.\n");
            break;
        case 9: 
            printf("Yes, definitely.\n");
            break;
    }

    return 0;
}