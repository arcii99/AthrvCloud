//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, a, b, c, d, e;
    char name[50];

    //prompts user for name
    printf("Greetings, I am the code oracle, please tell me your name: \n");
    scanf("%s", name);
    printf("Thank you, %s, please follow my instructions carefully.\n", name);

    //creates random numbers using current time as seed
    srand(time(NULL));
    a = rand() % 10 + 1;
    b = rand() % 10 + 1;
    c = rand() % 10 + 1;
    d = rand() % 10 + 1;
    e = rand() % 10 + 1;

    //puzzling questions and predictions
    printf("Please enter a number between 1 and 10: \n");
    scanf("%d", &i);

    if (i < a)
        printf("Your future is looking cloudy...but do not lose hope, %s.\n", name);
    else if (i > a && i < b)
        printf("I see great things in your future, %s!\n", name);
    else if (i > b && i < c)
        printf("Hmm, I sense a period of confusion and misdirection in your future...\n");
    else if (i > c && i < d)
        printf("Better days lie ahead for you, %s. Keep faith and stay focused!\n", name);
    else if (i > d && i < e)
        printf("Your future is looking bright! Seize the moment, %s.\n", name);
    else
        printf("I cannot predict what lies ahead for you, %s. Your fate is in your own hands...\n", name);

    printf("Thank you for consulting the code oracle. Goodbye!\n");

    return 0;
}