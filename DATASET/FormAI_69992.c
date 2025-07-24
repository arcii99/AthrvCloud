//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int num = rand() % 10 + 1; // Generate a number between 1 and 10

    printf("Welcome to the automated fortune teller!\n");
    printf("Ask me a question and I will give you an answer...\n\n");

    char question[100];
    printf("What is your question? ");
    fgets(question, 100, stdin); // Get question from user

    printf("Let me consult my crystal ball...\n");

    switch (num) {
        case 1:
            printf("It is certain.\n");
            break;
        case 2:
            printf("It is decidedly so.\n");
            break;
        case 3:
            printf("Without a doubt.\n");
            break;
        case 4:
            printf("Yes - definitely.\n");
            break;
        case 5:
            printf("You may rely on it.\n");
            break;
        case 6:
            printf("As I see it, yes.\n");
            break;
        case 7:
            printf("Most likely.\n");
            break;
        case 8:
            printf("Outlook good.\n");
            break;
        case 9:
            printf("Yes.\n");
            break;
        case 10:
            printf("Signs point to yes.\n");
            break;
        default:
            printf("Oops! Something went wrong.\n");
            break;
    }

    printf("Thanks for using the automated fortune teller! Goodbye.\n");

    return 0;
}