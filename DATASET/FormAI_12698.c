//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_fortune_number(void);
void print_fortune(int fortune_number);

int main(void)
{
    srand(time(NULL));
    int fortune_number = get_fortune_number();
    print_fortune(fortune_number);
    return 0;
}

int get_fortune_number(void)
{
    return rand() % 10;
}

void print_fortune(int fortune_number)
{
    switch (fortune_number)
    {
        case 0:
            printf("You will have a great future ahead of you.\n");
            break;
        case 1:
            printf("Your hard work and dedication will pay off soon.\n");
            break;
        case 2:
            printf("A new opportunity will arise that will change your life.\n");
            break;
        case 3:
            printf("Take a chance on something new, it may surprise you.\n");
            break;
        case 4:
            printf("Your luck will change for the better in the next few weeks.\n");
            break;
        case 5:
            printf("Be careful of those around you, they may have ulterior motives.\n");
            break;
        case 6:
            printf("You will be faced with a difficult decision soon, think carefully.\n");
            break;
        case 7:
            printf("You will soon receive unexpected news that will change your life.\n");
            break;
        case 8:
            printf("Remember to take care of yourself first before helping others.\n");
            break;
        case 9:
            printf("A long-awaited dream will finally come true.\n");
            break;
        default:
            printf("Error: Invalid fortune number.\n");
            break;
    }
}