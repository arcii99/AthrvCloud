//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand((unsigned) time(NULL));
    int fortune = rand() % 10;

    printf("Welcome to the Automated Fortune Teller!\n\n");

    switch (fortune) {
        case 0:
            printf("You will receive a promotion at work soon.\n");
            break;
        case 1:
            printf("A positive change is coming your way.\n");
            break;
        case 2:
            printf("You will meet someone new who will have a big impact on your life.\n");
            break;
        case 3:
            printf("Your financial situation will improve in the near future.\n");
            break;
        case 4:
            printf("You will embark on a new adventure in the coming weeks.\n");
            break;
        case 5:
            printf("Your hard work and dedication will pay off soon.\n");
            break;
        case 6:
            printf("Spend more time with your loved ones as they appreciate it the most.\n");
            break;
        case 7:
            printf("Be careful with your words as they may have a significant impact on those around you.\n");
            break;
        case 8:
            printf("Time heals all wounds. Give yourself the time you need to heal.\n");
            break;
        case 9:
            printf("Your perseverance will lead to success in all areas of your life.\n");
            break;
        default:
            printf("Error: Could not generate fortune.\n");
            break;
    }

    return 0;
}