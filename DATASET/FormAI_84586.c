//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    printf("Welcome to the Happy Fortune Teller Program!\n");
    int num = rand()%10+1; // generate a random number between 1 and 10
    printf("Today is your lucky day! The number you should choose is %d.\n", num);
    char color[15];
    printf("What is your favourite color?\n");
    scanf("%s", color);
    if (strcmp(color,"red")==0 || strcmp(color,"Red")==0)
    {
        printf("Red symbolizes passion and excitement. Your fortune is looking bright today!\n");
    }
    else if (strcmp(color,"blue")==0 || strcmp(color,"Blue")==0)
    {
        printf("Blue represents calmness and tranquility. Your fortune is predicting a peaceful and happy day for you.\n");
    }
    else if (strcmp(color,"green")==0 || strcmp(color,"Green")==0)
    {
        printf("Green is the color of growth and new beginnings. Your fortune is telling you to embrace change today.\n");
    }
    else if (strcmp(color,"yellow")==0 || strcmp(color,"Yellow")==0)
    {
        printf("Yellow symbolizes happiness and optimism. Your fortune is predicting a cheerful and joyful day for you.\n");
    }
    else
    {
        printf("Sorry, we do not have information on that color. Please try again with a different color.\n");
        return 0;
    }
    char name[20];
    printf("What is your name?\n");
    scanf("%s", name);
    int letter_count = strlen(name);
    if (letter_count%2 == 0)
    {
        printf("%s, since your name has an even number of letters, your fortune is predicting stability and balance for you today.\n", name);
    }
    else
    {
        printf("%s, since your name has an odd number of letters, your fortune is predicting spontaneity and adventure for you today!\n", name);
    }
    printf("Thank you for using the Happy Fortune Teller Program. Have a wonderful day!\n");
    return 0;
}