//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num;
    srand(time(NULL)); // seed for random number generator

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please think of a question and enter a number between 1 and 10: ");
    scanf("%d", &num);

    switch(num) {
        case 1:
            printf("The stars predict great success in your near future!\n");
            break;
        case 2:
            printf("You will come into great wealth, but be mindful of those who seek to take it from you.\n");
            break;
        case 3:
            printf("Your path is uncertain, but rest assured that you will find your way.\n");
            break;
        case 4:
            printf("Your past will come back to haunt you. Face it head on and it will lose its power over you.\n");
            break;
        case 5:
            printf("Love is in the air for you. Keep your heart open and be ready.\n");
            break;
        case 6:
            printf("Take a break from your routine and travel. It will refresh your soul.\n");
            break;
        case 7:
            printf("A great opportunity is coming your way. Seize it and do not let it pass.\n");
            break;
        case 8:
            printf("Be cautious of those who appear to be your friends but have ulterior motives.\n");
            break;
        case 9:
            printf("Your hard work will soon pay off. Do not give up.\n");
            break;
        case 10:
            printf("You are destined for greatness. Keep striving towards your dreams.\n");
            break;
        default:
            printf("Invalid input. Please try again.\n");
            return 0;
    }

    printf("Thank you for using the Automated Fortune Teller!\n");
    return 0;
}