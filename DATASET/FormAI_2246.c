//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char name[20];
    int birthYear, age, luckyNumber;
    srand(time(NULL));

    printf("Hello! I am your automated fortune teller. Please enter your name: ");
    scanf("%s", name);

    printf("Nice to meet you, %s! What year were you born in? ", name);
    scanf("%d", &birthYear);

    age = 2021 - birthYear;
    printf("You are %d years old.\n", age);

    printf("Please enter a lucky number: ");
    scanf("%d", &luckyNumber);

    int fortune = rand() % 4;
    switch (fortune) {
        case 0:
            printf("Your lucky number is %d, and your future is looking bright!\n", luckyNumber);
            break;
        case 1:
            printf("Be careful with your finances, %s. Money troubles are on the horizon.\n", name);
            break;
        case 2:
            printf("Your lucky number is %d, and you will soon meet someone special!\n", luckyNumber);
            break;
        case 3:
            printf("Unfortunately, %s, your lucky number will bring you no luck in the near future.\n", name);
            break;
        default:
            printf("Oops! Something went wrong.\n");
            break;
    }

    printf("Thank you for using our automated fortune teller. Good luck!\n");

    return 0;
}