//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Automated Fortune Teller! \n");

    int birthMonth, birthDay, luckyNum;
    char name[20], color[10];

    printf("What is your name? ");
    scanf("%s", name);

    printf("What is your birth month? (1 - 12) ");
    scanf("%d", &birthMonth);
    
    printf("What day of the month were you born? ");
    scanf("%d", &birthDay);

    printf("What is your lucky number? ");
    scanf("%d", &luckyNum);

    printf("What is your favorite color? ");
    scanf("%s", color);

    srand(time(0));
    int fortune = rand() % 5;
    switch(fortune)
    {
        case 0:
            printf("%s, your future looks bright! You will have good luck in all your endeavors. Your lucky number is %d. \n", name, luckyNum);
            break;
        case 1:
            printf("%s, you may experience some hurdles in the near future, but do not worry because the universe has got your back. Your lucky color is %s \n", name, color);
            break;
        case 2:
            printf("%s, good things take time and patience, and your time is coming soon. Keep working hard, and your dreams will come true. Your birthday is a maginificant number! \n", name);
            break;
        case 3:
            printf("%s, you will encounter a challenging opportunity but it will give you great achievement in the end. Your lucky month is %d \n", name, birthMonth);
            break;
        case 4:
            printf("%s, romance is in the air! Keep your eyes open and someone special may enter your life very soon. Your birthday number is the key to your success! \n", name);
            break;
    }

    return 0;
}