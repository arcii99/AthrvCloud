//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int num;
    char name[50];

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What is your name?\n");
    scanf("%s", name);

    printf("Hello %s, please think of a number between 1 and 10.\n", name);

    srand(time(NULL)); //seeding random number generator with current time

    num = rand() % 10 + 1; //generating random number between 1 to 10

    switch(num){
        case 1:
            printf("Your fortune: Things will go your way today!\n");
            break;
        case 2:
            printf("Your fortune: Beware of unexpected expenses today.\n");
            break;
        case 3:
            printf("Your fortune: You will find your true love soon.\n");
            break;
        case 4:
            printf("Your fortune: You will succeed in your career.\n");
            break;
        case 5:
            printf("Your fortune: You will receive unexpected good news today!\n");
            break;
        case 6:
            printf("Your fortune: You may face some challenges today, but remember they will make you stronger.\n");
            break;
        case 7:
            printf("Your fortune: A long-awaited opportunity will come your way today.\n");
            break;
        case 8:
            printf("Your fortune: Things may not go your way today, but keep going! Better days are ahead.\n");
            break;
        case 9:
            printf("Your fortune: You will make a new friend today.\n");
            break;
        case 10:
            printf("Your fortune: You will receive help from an unexpected source today.\n");
            break;
    }

    printf("Thank you for using the Automated Fortune Teller! Goodbye!\n");

    return 0;
}