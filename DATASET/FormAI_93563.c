//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int option;

    printf("Welcome to the Automated Fortune Teller\n");
    printf("Please choose your reading:\n");
    printf("1. Love and Relationships\n");
    printf("2. Career and Finances\n");
    printf("3. Life and Success\n");
    scanf("%d", &option);

    switch(option)
    {
        case 1:
            printf("You will soon meet someone special who will bring great joy and happiness into your life.\n");
            break;
        case 2:
            printf("Your hard work and dedication will pay off in your career. Expect a promotion or raise soon.\n");
            break;
        case 3:
            printf("You are destined for great success. Keep working hard and never give up on your dreams.\n");
            break;
        default:
            printf("Invalid option selected. Please choose from 1-3.\n");
            break;
    }

    // Generate a random number to predict a lucky number
    srand(time(0));
    int lucky_number = rand() % 10 + 1;

    printf("Your lucky number for today is: %d\n", lucky_number);

    return 0;
}