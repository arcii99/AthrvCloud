//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char question[100];
    printf("Welcome to the Automated Fortune Teller! Ask me any question and I will tell you your fortune!\n");
    printf("What is your question?\n");

    // get user input
    fgets(question, 100, stdin);

    // initialize random number generator
    srand(time(NULL));

    // generate random fortune
    int random_num = rand() % 10;
    switch (random_num) {
        case 0:
            printf("The stars are aligned in your favor. Good things lie ahead!\n");
            break;
        case 1:
            printf("Be cautious of those around you. Someone may be trying to deceive you.\n");
            break;
        case 2:
            printf("You will soon come across an unexpected opportunity. Seize it!\n");
            break;
        case 3:
            printf("Your journey will be difficult, but the reward at the end is worth it.\n");
            break;
        case 4:
            printf("You have a big decision to make. Trust your instincts.\n");
            break;
        case 5:
            printf("A loved one will need your support in the near future. Be there for them.\n");
            break;
        case 6:
            printf("You will soon receive news that will bring you great joy.\n");
            break;
        case 7:
            printf("Be prepared for changes ahead. You will overcome any obstacles that come your way.\n");
            break;
        case 8:
            printf("You have been working hard and your efforts will soon pay off.\n");
            break;
        case 9:
            printf("Do not be afraid to take risks. Great rewards await those who dare to take them.\n");
            break;
    }

    return 0;
}