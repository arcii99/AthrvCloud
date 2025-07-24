//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //welcome message to the user
    printf("***Welcome to the Automated Fortune Teller!***\n");

    //get the user's name
    char name[20];
    printf("Please enter your name: ");
    scanf("%s", name);

    //print a personalized message to the user
    printf("Hello, %s! I will now tell your fortune.\n", name);

    //generate a random number between 1 and 5
    srand(time(NULL));
    int num = rand() % 5 + 1;

    //use the random number to generate a fortune message
    switch(num) {
        case 1:
            printf("Your future looks bright!\n");
            break;
        case 2:
            printf("You will face many challenges, but ultimately come out victorious.\n");
            break;
        case 3:
            printf("Unexpected opportunities will come your way.\n");
            break;
        case 4:
            printf("Your hard work will pay off in the end.\n");
            break;
        case 5:
            printf("Be cautious of those around you, they may not have your best interests at heart.\n");
            break;
    }

    //thank the user for using the program
    printf("Thank you for using the Automated Fortune Teller!\n");

    return 0;
}