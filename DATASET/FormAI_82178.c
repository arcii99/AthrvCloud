//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>

int main(){
    char user[20];
    printf("Hello! I am your automated fortune teller. What's your name?\n");
    scanf("%s", user);

    printf("Welcome, %s! Let's see what the future holds for you...\n", user);
    printf("Your fortune is:\n");

    //randomly select a fortune
    int fortune_num = rand() % 6;

    switch(fortune_num){
        case 0:
            printf("A bright future is ahead of you.\n");
            break;
        case 1:
            printf("An unexpected windfall is on its way to you.\n");
            break;
        case 2:
            printf("You will find love in unexpected places.\n");
            break;
        case 3:
            printf("Your hard work will pay off in the near future.\n");
            break;
        case 4:
            printf("Be wary of those who try to deceive you.\n");
            break;
        case 5:
            printf("Take a chance and see where it leads you.\n");
            break;
    }

    printf("Thank you for visiting! Come again!\n");

    return 0;
}