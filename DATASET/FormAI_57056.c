//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("\nHello %s, I am the Automated Fortune Teller. Ask me a yes or no question and I will tell you the answer!\n\n", name);

    char question[50];
    printf("Ask me a question: ");
    scanf(" %[^\n]", question);

    // Random number generator to determine the fortune
    srand(time(NULL));
    int fortune = rand() % 10;

    // Switch statement to display fortune based on the random number
    switch(fortune) {
        case 0:
            printf("\nCannot predict now. Try again later.\n");
            break;
        case 1:
            printf("\nYes, definitely!\n");
            break;
        case 2:
            printf("\nIt is decidedly so.\n");
            break;
        case 3:
            printf("\nWithout a doubt.\n");
            break;
        case 4:
            printf("\nMost likely.\n");
            break;
        case 5:
            printf("\nOutlook good.\n");
            break;
        case 6:
            printf("\nBetter not tell you now.\n");
            break;
        case 7:
            printf("\nDon't count on it.\n");
            break;
        case 8:
            printf("\nVery doubtful.\n");
            break;
        case 9:
            printf("\nMy sources say no.\n");
            break;
        default:
            printf("\nError.\n");
            break;
    }

    printf("\nThank you for using the Automated Fortune Teller. Goodbye!\n");

    return 0;
}