//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char userInput;
    srand(time(NULL));
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your question:\n");
    scanf("%c", &userInput);
    printf("Calculating...\n");
    int randomNum = rand() % 10; //random number between 0-9
    //pick random fortune based on random number
    switch (randomNum) {
        case 0:
            printf("It is certain.\n");
            break;
        case 1:
            printf("It is decidedly so.\n");
            break;
        case 2:
            printf("Without a doubt.\n");
            break;
        case 3:
            printf("Yes - definitely.\n");
            break;
        case 4:
            printf("You may rely on it.\n");
            break;
        case 5:
            printf("As I see it, yes.\n");
            break;
        case 6:
            printf("Most likely.\n");
            break;
        case 7:
            printf("Outlook good.\n");
            break;
        case 8:
            printf("Signs point to yes.\n");
            break;
        case 9:
            printf("Cannot predict now.\n");
            break;
        default:
            printf("Error: Invalid Random Number.\n");
            return 1;
    }
    return 0;
}