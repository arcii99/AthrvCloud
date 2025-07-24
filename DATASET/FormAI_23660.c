//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20];
    printf("Welcome to the Fortune Teller program!\n");
    printf("Please enter your name: ");
    fgets(name, 20, stdin);
    printf("\nHello, %s\n", name);

    srand(time(NULL));
    int num = rand() % 5;

    switch(num)
    {
        case 0:
            printf("Your future looks bright!\n");
            break;
        case 1:
            printf("You will experience some challenges but ultimately succeed.\n");
            break;
        case 2:
            printf("You will meet someone very important to your future.\n");
            break;
        case 3:
            printf("Your future is unclear. Focus on the present.\n");
            break;
        case 4:
            printf("You will soon have a life-changing experience.\n");
            break;
    }

    return 0;
}