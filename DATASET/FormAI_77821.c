//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sleep(int milliseconds)
{
    clock_t time_end;
    time_end = clock() + milliseconds * CLOCKS_PER_SEC / 1000;
    while (clock() < time_end)
    {
    }
}

int main()
{
    char fortune[6][50] = {"You will soon come into money",
                           "Your wildest dreams will come true",
                           "You will meet the love of your life soon",
                           "You will live a long and fruitful life",
                           "A great adventure awaits you",
                           "Luck is on your side today"};

    char response[50];

    printf("Welcome to the automated Fortune Teller!\n\n");
    sleep(1500);
    printf("Please ask me a question to receive your fortune.\n\n");
    scanf("%[^\n]s", response);
    sleep(1500);

    printf("The answer to your question \"%s\" is...\n\n", response);
    sleep(1500);

    int random = rand() % 6;

    printf("Drum roll please...\n\n");
    sleep(2000);

    printf("%s.\n", fortune[random]);

    return 0;
}