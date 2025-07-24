//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int fortune_num, i;

    // seed the random number generator
    srand(time(0));

    // generate random fortune number between 1 and 5
    fortune_num = rand() % 5 + 1;

    // switch statement to select fortune message based on fortune number
    switch (fortune_num) {
        case 1:
            printf("This is your lucky day!\n");
            break;
        case 2:
            printf("A major change is coming your way!\n");
            break;
        case 3:
            printf("Be careful while travelling today\n");
            break;
        case 4:
            printf("You will receive good news soon\n");
            break;
        case 5:
            printf("Today is a good day to make important decisions\n");
            break;
        default:
            printf("Error: Invalid fortune number\n");
            break;
    }

    return 0;
}