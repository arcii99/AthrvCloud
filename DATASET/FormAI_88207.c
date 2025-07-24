//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Automated Fortune Teller Program!\n");
    printf("Please think of a question you want to ask the fortune teller.\n");
    printf("Press Enter to continue.\n");
    getchar();
    printf("The fortune teller is now generating your answer...\n");
    srand(time(NULL)); // seed the random number generator with the current time
    int answer = rand() % 10; // generate a random number between 0-9
    switch(answer)
    {
        case 0:
            printf("It is certain.\n");
            break;
        case 1:
            printf("Without a doubt.\n");
            break;
        case 2:
            printf("You may rely on it.\n");
            break;
        case 3:
            printf("Yes, definitely.\n");
            break;
        case 4:
            printf("It is decidedly so.\n");
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
            printf("Yes.\n");
            break;
    }
    printf("Thank you for using the Automated Fortune Teller Program!\n");
    return 0;
}