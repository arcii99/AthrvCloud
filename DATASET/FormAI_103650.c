//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int answer;
    srand((unsigned) time(NULL));

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Ask a yes or no question and I will tell you the answer.\n\n");

    printf("What is your question? ");
    getchar();

    answer = rand() % 10;

    switch(answer){
        case 0:
            printf("\nYes.\n");
            break;
        case 1:
            printf("\nNo.\n");
            break;
        case 2:
            printf("\nMaybe.\n");
            break;
        case 3:
            printf("\nTry again later.\n");
            break;
        case 4:
            printf("\nAbsolutely.\n");
            break;
        case 5:
            printf("\nNot likely.\n");
            break;
        case 6:
            printf("\nIt is uncertain.\n");
            break;
        case 7:
            printf("\nOutlook not so good.\n");
            break;
        case 8:
            printf("\nThe stars say yes.\n");
            break;
        case 9:
            printf("\nSigns point to no.\n");
            break;
    }

    return 0;
}