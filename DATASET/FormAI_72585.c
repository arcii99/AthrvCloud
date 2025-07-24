//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //Seed random function with current time
    int fortune = rand() % 10; //Generate random number between 0-9 for fortune
    char name[100]; //Declare character array for user's name
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What is your name?\n");
    scanf("%s", name); //Read user's name from console input
    printf("\nGreetings, %s!\n\n", name);
    
    switch(fortune)
    {
        case 0:
            printf("Your future looks bright!\n");
            break;
        case 1:
            printf("You might encounter big changes soon.\n");
            break;
        case 2:
            printf("You are destined for great things.\n");
            break;
        case 3:
            printf("Be prepared for unexpected events.\n");
            break;
        case 4:
            printf("You will find happiness in unexpected places.\n");
            break;
        case 5:
            printf("Your perseverance will lead you to success.\n");
            break;
        case 6:
            printf("Take risks, they will pay off.\n");
            break;
        case 7:
            printf("The future holds great possibilities for you.\n");
            break;
        case 8:
            printf("Believe in yourself and all will be possible.\n");
            break;
        case 9:
            printf("Your hard work will soon be rewarded.\n");
            break;
    }
    printf("\nThank you for trying out the Automated Fortune Teller! Come back soon!\n");
    return 0;
}