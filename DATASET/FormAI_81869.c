//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //Initialize random seed

    while(1) { //Loop until user quits program
        printf("Welcome to the Automated Fortune Teller program!\n");
        printf("Think of a question you want the answer to, then press Enter to continue...\n");
        getchar(); //Wait for user to press Enter

        int randNum = rand() % 5; //Generate random number between 0 and 4

        switch(randNum) {
            case 0:
                printf("\nMy sources say no.\n\n");
                break;
            case 1:
                printf("\nIt is certain.\n\n");
                break;
            case 2:
                printf("\nYes, definitely.\n\n");
                break;
            case 3:
                printf("\nCannot predict now, please try again.\n\n");
                break;
            case 4:
                printf("\nDon't count on it.\n\n");
                break;
            default:
                printf("\nError: Invalid random number generated.\n\n");
                break;
        }

        printf("Press Enter to ask another question or type 'quit' to exit...\n");
        char input[10];
        fgets(input, sizeof(input), stdin);

        if(strcmp(input, "quit\n") == 0) {
            printf("Thank you for using the Automated Fortune Teller program!\n");
            break; //Exit while loop and end program
        }

        system("clear"); //Clear terminal screen for clean output
    }

    return 0;
}