//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[20];
    int age, luckyNum, future;

    printf("Hey there! I am the Automated Fortune Teller. What's your name?\n");
    scanf("%s", name);

    printf("Nice to meet you %s! What's your age?\n", name);
    scanf("%d", &age);

    printf("Interesting! What's your lucky number?\n");
    scanf("%d", &luckyNum);

    srand(time(0));
    future = rand() % 5;

    printf("Let me gaze into my crystal ball...\n\n");

    switch (future) {
        case 0:
            printf("You will meet someone special in the near future. Keep an open mind and heart.\n");
            break;
        case 1:
            printf("Your financial opportunities will improve significantly in the coming days.\n");
            break;
        case 2:
            printf("You will embark on a new adventure that will take you to unexpected places.\n");
            break;
        case 3:
            printf("You will encounter a challenge that will test your resolve. Believe in yourself!\n");
            break;
        case 4:
            printf("You will receive unexpected news that will change your life in a positive way.\n");
            break;
    }

    printf("\nThank you for using Automated Fortune Teller. Goodbye %s!", name);

    return 0;
}