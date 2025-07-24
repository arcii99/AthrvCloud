//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    int fortuneNum = rand() % 10;

    switch(fortuneNum) {
        case 0:
            printf("You will have a long and prosperous life.\n");
            break;
        case 1:
            printf("You will find success in your career.\n");
            break;
        case 2:
            printf("A windfall is headed your way!\n");
            break;
        case 3:
            printf("Your romantic life will flourish.\n");
            break;
        case 4:
            printf("An opportunity for travel will present itself soon.\n");
            break;
        case 5:
            printf("Be cautious in financial matters.\n");
            break;
        case 6:
            printf("A new friendship will bring joy into your life.\n");
            break;
        case 7:
            printf("Your hard work will pay off in the near future.\n");
            break;
        case 8:
            printf("Be kind to yourself and take time for self care.\n");
            break;
        case 9:
            printf("Trust your intuition in important decisions.\n");
            break;
        default:
            printf("Error: invalid fortune number.\n");
            break;
    }

    return 0;
}