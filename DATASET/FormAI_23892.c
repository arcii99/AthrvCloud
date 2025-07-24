//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Automated Fortune Teller Program!\n");
    char name[20];
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Welcome, %s! Let's begin.\n", name);
    srand(time(0));
    int num = rand() % 9;

    switch(num) {
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
            printf("Reply hazy, try again.\n");
            break;
        default:
            printf("Error! Please try again later.\n");
            break;
    }
    printf("Thank you for using the Automated Fortune Teller Program, %s. Goodbye!\n", name);
    return 0;
}