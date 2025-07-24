//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_fortune() {
    int num = rand() % 10;
    switch(num) {
        case 0:
            printf("You will come into a large sum of money.\n");
            break;
        case 1:
            printf("You will find true love in the next year.\n");
            break;
        case 2:
            printf("Your hard work will pay off with a promotion.\n");
            break;
        case 3:
            printf("Be cautious of someone close to you, they may not have your best interests at heart.\n");
            break;
        case 4:
            printf("Luck will be on your side during your next gambling outing.\n");
            break;
        case 5:
            printf("Your creativity will lead to a successful business venture.\n");
            break;
        case 6:
            printf("Your perseverance will bring you great success.\n");
            break;
        case 7:
            printf("You will soon face a difficult decision, weigh your options carefully.\n");
            break;
        case 8:
            printf("A long overdue reconciliation with a loved one will occur.\n");
            break;
        case 9:
            printf("Travel is in your future, it will bring great joy and new experiences.\n");
            break;
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator
    printf("Welcome to the Automated Fortune Teller!\n");
    while(1) {
        printf("Would you like a fortune? (y/n): ");
        char response;
        scanf(" %c", &response);
        if(response == 'y') {
            print_fortune();
            printf("\n");
        } else if(response == 'n') {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid response, please try again.\n");
        }
    }
    return 0;
}