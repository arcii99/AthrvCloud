//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));

    char response;

    printf("Welcome to the Automated Fortune Teller\n");
    printf("Please think of a question and press enter to continue\n");

    scanf("%c", &response);

    printf("Thinking. Please wait...\n");

    int randomNum = rand() % 10;

    switch(randomNum){
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
            printf("Yes.\n");
            break;

        case 9:
            printf("Signs point to yes.\n");
            break;

        default:
            printf("Error.\n");
            break;
    }

    return 0;
}