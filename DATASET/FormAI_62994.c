//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL));
    int fortune = rand() % 6;

    switch(fortune) {
        case 0:
            printf("You will receive a surprise gift today!\n");
            break;
        case 1:
            printf("Beware of strangers today!\n");
            break;
        case 2:
            printf("Good news is coming your way soon!\n");
            break;
        case 3:
            printf("Your hard work will pay off soon!\n");
            break;
        case 4:
            printf("Avoid making any major decisions today!\n");
            break;
        case 5:
            printf("You will meet someone new and interesting today!\n");
            break;
        default:
            printf("Something went wrong. Please try again later.\n");
            break;
    }

    return 0;
}