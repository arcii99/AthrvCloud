//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int fortune = rand() % 10; // Generate a random number between 0 and 9
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please think of a question in your mind and the fortune teller will help you find the answer.\n\n");
    printf("Shaking the magic ball..\n\n");
    
    switch(fortune) {
        case 0:
            printf("The answer is yes.\n");
            break;
        case 1:
            printf("The answer is no.\n");
            break;
        case 2:
            printf("You may rely on it.\n");
            break;
        case 3:
            printf("Don't count on it.\n");
            break;
        case 4:
            printf("Outlook not so good.\n");
            break;
        case 5:
            printf("Yes, definitely.\n");
            break;
        case 6:
            printf("Cannot predict now.\n");
            break;
        case 7:
            printf("Better not tell you now.\n");
            break;
        case 8:
            printf("Signs point to yes.\n");
            break;
        case 9:
            printf("Most likely.\n");
            break;
    }
    
    return 0;
}