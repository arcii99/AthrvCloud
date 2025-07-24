//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the amazing fortune teller! \n");
    printf("What do you want to know? Enter your question: ");

    char question[100];
    fgets(question, 100, stdin);

    printf("\nHmm.. Let me think about that for a moment...\n");

    srand(time(NULL));
    int random_num = rand() % 10 + 1;

    switch (random_num) {
        case 1:
            printf("All signs point to yes.");
            break;
        case 2:
            printf("Yes, definitely.");
            break;
        case 3:
            printf("You may rely on it.");
            break;
        case 4:
            printf("Outlook good.");
            break;
        case 5:
            printf("Ask again later. (I'm going for a coffee break)");
            break;
        case 6:
            printf("Reply hazy, try again.");
            break;
        case 7:
            printf("Better not tell you now. (I'm on a spy mission)");
            break;
        case 8:
            printf("My sources say no.");
            break;
        case 9:
            printf("I see failure in your future. (just joking!)");
            break;
        case 10:
            printf("Very doubtful.");
            break;
        default:
            printf("I'm on vacation. Try again later.");
            break;
    }

    printf("\nThanks for playing! Come back anytime :)");
    return 0;
}