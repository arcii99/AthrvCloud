//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int range;
    char name[20];

    printf("Welcome to the Automated Fortune Teller\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s! Please choose a number between 1 and 10: ", name);
    scanf("%d", &range);

    srand(time(0));
    int fortune = (rand() % range) + 1;

    printf("\n%s's fortune is:\n\n", name);

    switch(fortune) {
        case 1:
            printf("You will have a great day today!\n");
            break;
        case 2:
            printf("Be careful with money today -- avoid any impulse buys.\n");
            break;
        case 3:
            printf("Good news is coming your way!\n");
            break;
        case 4:
            printf("Don't be afraid to take risks today. The payoff will be worth it.\n");
            break;
        case 5:
            printf("Your hard work will pay off soon!\n");
            break;
        case 6:
            printf("Expect some unexpected news or a surprise today!\n");
            break;
        case 7:
            printf("You will face a challenge today, but you will come out on top.\n");
            break;
        case 8:
            printf("Be mindful of your health today and take care of yourself.\n");
            break;
        case 9:
            printf("Your creativity and imagination will shine today!\n");
            break;
        case 10:
            printf("Take some time for self-reflection and meditation today.\n");
            break;
        default:
            printf("Something went wrong with the fortune-telling machine!\n");
            break;
    }

    return 0;
}