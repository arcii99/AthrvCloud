//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    printf("Hello! Welcome to the Automated Fortune Teller.\n\n");
    printf("Think of a question and I'll give you an answer!\n");
    printf("Press Enter to continue:");
    getchar(); // Waits for user to press Enter

    int answer_number = rand() % 20;

    switch (answer_number) {
        case 0:
            printf("Without a doubt.\n");
            break;
        case 1:
            printf("Yes - definitely.\n");
            break;
        case 2:
            printf("You may rely on it.\n");
            break;
        case 3:
            printf("It is decidedly so.\n");
            break;
        case 4:
            printf("As I see it, yes.\n");
            break;
        case 5:
            printf("Most likely.\n");
            break;
        case 6:
            printf("Outlook good.\n");
            break;
        case 7:
            printf("Yes.\n");
            break;
        case 8:
            printf("Signs point to yes.\n");
            break;
        case 9:
            printf("Reply hazy, try again.\n");
            break;
        case 10:
            printf("Better not tell you now.\n");
            break;
        case 11:
            printf("Ask again later.\n");
            break;
        case 12:
            printf("Cannot predict now.\n");
            break;
        case 13:
            printf("Concentrate and ask again.\n");
            break;
        case 14:
            printf("Don't count on it.\n");
            break;
        case 15:
            printf("Outlook not so good.\n");
            break;
        case 16:
            printf("My sources say no.\n");
            break;
        case 17:
            printf("Very doubtful.\n");
            break;
        case 18:
            printf("No chance.\n");
            break;
        case 19:
            printf("Not in a million years.\n");
            break;
        default:
            printf("Error! Something went wrong.\n");
            break;
    }

    return 0;
}