//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: post-apocalyptic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    char question[100];
    printf("Welcome to the Post Apocalyptic Fortune Teller!\n");
    printf("What would you like to know?\n");
    scanf("%[^\n]", question);
    srand(time(NULL));
    int fortune = rand() % 5;
    switch(fortune) {
        case 0:
            printf("The future looks bleak for you. Be careful.\n");
            break;
        case 1:
            printf("Your journey will be long and full of danger.\n");
            break;
        case 2:
            printf("There is hope for you yet. A great destiny awaits.\n");
            break;
        case 3:
            printf("The gods are with you. You will find what you seek.\n");
            break;
        case 4:
            printf("Your future is shrouded in mystery. Beware of those around you.\n");
            break;
        default:
            printf("Sorry, I cannot predict the future at this time.\n");
    }
    printf("Thank you for visiting the Post Apocalyptic Fortune Teller!\n");
    return 0;
}