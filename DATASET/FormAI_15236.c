//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: dynamic
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    srand(time(NULL));
    int fortune = rand() % 10; // generate a random number between 0 and 9
    
    switch(fortune) {
        case 0:
            printf("You will have a great day today!\n");
            break;
        case 1:
            printf("Someone special will enter your life today!\n");
            break;
        case 2:
            printf("Opportunities for success will come your way today!\n");
            break;
        case 3:
            printf("Be careful with your possessions today, they may be lost or stolen!\n");
            break;
        case 4:
            printf("Beware of unexpected expenses today!\n");
            break;
        case 5:
            printf("Someone close to you needs your help today!\n");
            break;
        case 6:
            printf("A long-awaited project will finally be completed today!\n");
            break;
        case 7:
            printf("Love is in the air today!\n");
            break;
        case 8:
            printf("You will learn something new and exciting today!\n");
            break;
        case 9:
            printf("Your hard work will pay off today!\n");
            break;
        default:
            printf("Something went wrong, please try again later.\n");
            break;
    }
    
    return 0;
}