//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fortune_teller(){
    char name[20];
    int age, lucky_number;
    printf("Welcome to the automated Fortune Teller.\n");
    printf("Please enter your name:");
    scanf("%s", name);
    printf("Please enter your age:");
    scanf("%d", &age);
    printf("Please enter your lucky number:");
    scanf("%d", &lucky_number);

    srand(time(NULL));
    int fortune = rand() % 5;

    switch(fortune){
        case 0: printf("%s, your lucky number %d will bring you abundance and prosperity!\n", name, lucky_number);
                break;
        case 1: printf("%s, beware of taking any risky decisions today.\n", name);
                break;
        case 2: printf("You are in for a wonderful surprise %s! Keep an eye out for unexpected opportunities.\n", name);
                break;
        case 3: printf("Today is a day of learning for you, %s. Make the most of it.\n", name);
                break;
        case 4: printf("Things may seem overwhelming right now %s, but do not lose hope. The universe is conspiring in your favour.\n", name);
                break;
        default: printf("%s, something went wrong! Please try again.\n", name);
    }
}

int main(){
    fortune_teller();
    return 0;
}