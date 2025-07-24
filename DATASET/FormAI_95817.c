//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[20];
    int age;
    srand(time(NULL)); // seed random number generator with current time
    int fortune = rand() % 8; // generate random number from 0 to 7
    printf("Welcome to the Automated Fortune Teller! Please enter your name: ");
    scanf("%s", name);
    printf("And what is your age, %s? ", name);
    scanf("%d", &age);
    if (age < 18) {
        printf("I'm sorry, but you must be at least 18 years old to use this program.\n");
    } else {
        printf("Great, let's get started.\n");
        switch(fortune) {
            case 0:
                printf("%s, you will come into a great sum of money in the near future.\n", name);
                break;
            case 1:
                printf("%s, you will find true love within the next year.\n", name);
                break;
            case 2:
                printf("%s, beware of someone close to you who may betray you.\n", name);
                break;
            case 3:
                printf("%s, you will go on a journey to a far-off land soon.\n", name);
                break;
            case 4:
                printf("%s, you will find success in your career in the next few months.\n", name);
                break;
            case 5:
                printf("%s, be careful of your health in the coming weeks.\n", name);
                break;
            case 6:
                printf("%s, you will meet an old friend you haven't seen in years.\n", name);
                break;
            case 7:
                printf("%s, you will have a chance encounter that will change your life forever.\n", name);
                break;
        }
    }
    return 0;
}