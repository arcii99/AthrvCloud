//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num;
    char name[20];

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("What is your name?\n");

    scanf("%s", name);

    printf("Hello %s, please think of a number from 1 to 10.\n", name);

    srand(time(0));
    num = rand() % 10 + 1;

    if (num == 1) {
        printf("Your fortune is: You will find true love in the near future.\n");
    } else if (num == 2) {
        printf("Your fortune is: You will come into a large sum of money.\n");
    } else if (num == 3) {
        printf("Your fortune is: You will have a long and successful life.\n");
    } else if (num == 4) {
        printf("Your fortune is: You will travel to a foreign country in the coming year.\n");
    } else if (num == 5) {
        printf("Your fortune is: You will meet your soulmate soon.\n");
    } else if (num == 6) {
        printf("Your fortune is: Your hard work will pay off soon.\n");
    } else if (num == 7) {
        printf("Your fortune is: You will make new and lasting friendships soon.\n");
    } else if (num == 8) {
        printf("Your fortune is: You will achieve great success in your career.\n");
    } else if (num == 9) {
        printf("Your fortune is: You will discover new and exciting opportunities soon.\n");
    } else if (num == 10) {
        printf("Your fortune is: You will receive unexpected good news in the coming days.\n");
    }

    printf("Thank you for using the Automated Fortune Teller! Goodbye.");
    return 0;
}