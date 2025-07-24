//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed based on time

    char input[50];
    int fortune = rand() % 5; // generate a random number between 0 and 4

    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Please enter your name: ");
    fgets(input, sizeof(input), stdin);
    printf("\nHello, %s! ", input);

    switch(fortune) {
        case 0:
            printf("You will find success in your future endeavors.\n");
            break;
        case 1:
            printf("A great adventure awaits you in the near future.\n");
            break;
        case 2:
            printf("You will meet someone special in the next few days.\n");
            break;
        case 3:
            printf("Your hard work will pay off soon.\n");
            break;
        case 4:
            printf("Be cautious when making important decisions.\n");
            break;
        default:
            printf("Something went wrong...\n");
    }

    return 0;
}