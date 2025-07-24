//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int fortuneNum = rand() % 10;

    switch(fortuneNum) {
        case 0:
            printf("Your future looks bright!\n");
            break;
        case 1:
            printf("Opportunities are coming your way!\n");
            break;
        case 2:
            printf("Stay positive. Good things are about to happen!\n");
            break;
        case 3:
            printf("Be open to new ideas. They will lead you to success!\n");
            break;
        case 4:
            printf("Today is a great day to start something new!\n");
            break;
        case 5:
            printf("The universe is on your side. Keep going!\n");
            break;
        case 6:
            printf("Luck is on your side today. Take a chance!\n");
            break;
        case 7:
            printf("Your hard work will pay off soon. Keep pushing!\n");
            break;
        case 8:
            printf("Your creativity will lead you to success!\n");
            break;
        default:
            printf("Believe in yourself. You have what it takes to succeed!\n");
            break;
    }
    return 0;
}