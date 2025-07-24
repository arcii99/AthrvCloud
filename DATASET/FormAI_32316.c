//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int fortuneNum;
    srand(time(0));
    fortuneNum = (rand() % 10) + 1;
    printf("Welcome to the Automated Fortune Teller! \n");
    printf("I am going to predict your future....\n\n");
    switch (fortuneNum){
        case 1:
            printf("You will be offered a very exciting opportunity that you cannot refuse!\n");
            break;
        case 2:
            printf("This week, you will have a stroke of good luck that will change your life forever!\n");
            break;
        case 3:
            printf("In the near future, you will find yourself in an unexpected situation that will reveal a lot about your true character!\n");
            break;
        case 4:
            printf("In the coming days, you will learn an important lesson from a mistake. Use this knowledge to move forward in your life!\n");
            break;
        case 5:
            printf("You will meet someone special in the next few months that will change your life for the better!\n");
            break;
        case 6:
            printf("Soon, you will receive an unexpected gift or surprise from someone close to you!\n");
            break;
        case 7:
            printf("You have been working very hard and your efforts will soon pay off. Keep up the good work!\n");
            break;
        case 8:
            printf("You have been feeling lost lately, but do not worry! Something wonderful is about to happen that will help guide you on your journey!\n");
            break;
        case 9:
            printf("Take a chance and try something new! Your future promises to be full of excitement and adventure!\n");
            break;
        case 10:
            printf("Do not give up on something you have been working towards. Your perseverance will pay off in the end!\n");
            break;
        default:
            printf("Oops! Something went wrong. Please try again later.\n");
    }
    return 0;
}