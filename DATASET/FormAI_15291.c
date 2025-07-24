//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>

void printMessage(char *message, int delay);
void solveHanoi(int n, char source, char aux, char target);

int main() {
    printf("\n\t----- Welcome to the Mind-Bending Tower of Hanoi -----");
    printf("\n\t-----------------------------------------------------\n\n");
    printMessage("Are you ready to test your mental abilities? Press enter to continue...", 10);
    getchar();
    system("clear");

    int numOfDisks = 0;
    while(numOfDisks < 3) {
        printf("\n\tPlease enter the number of disks (minimum of 3): ");
        scanf("%d", &numOfDisks);
        if(numOfDisks < 3) {
            printMessage("Invalid input, please enter a minimum of 3.", 5);
        }
    }

    char choice = ' ';
    while(choice != 'y' && choice != 'n') {
        printf("\n\tAre you ready to solve the Tower of Hanoi puzzle? (y/n): ");
        scanf(" %c", &choice);
        if(choice != 'y' && choice != 'n') {
            printMessage("Invalid input, please choose either y or n.", 5);
        }
    }

    if(choice == 'n') {
        printMessage("No problem, come back when you're ready to test your mind!", 10);
        return 0;
    }

    system("clear");
    printf("\n\t\t*** Starting the Tower of Hanoi game with %d disks ***\n\n", numOfDisks);
    printMessage("Solving puzzles requires logical reasoning and patience. Are you ready? Press enter to continue...", 10);
    getchar();
    system("clear");

    solveHanoi(numOfDisks, 'A', 'B', 'C');
    printf("\n\n\tCongratulations! You have successfully solved the puzzle with %d disks!\n", numOfDisks);
    printMessage("Thank you for playing the Mind-Bending Tower of Hanoi game. Press enter to exit...", 10);
    getchar();

    return 0;
}

void printMessage(char *message, int delay) {
    printf("\t");
    for(int i = 0; message[i] != '\0'; i++) {
        printf("%c", message[i]);
        fflush(stdout);
        usleep(delay * 1000);
    }
    printf("\n");
}

void solveHanoi(int n, char source, char aux, char target) {
    if(n == 1) {
        printf("\n\tMove disk 1 from %c to %c", source, target);
        usleep(500000);
        return;
    }

    solveHanoi(n - 1, source, target, aux);
    printf("\n\tMove disk %d from %c to %c", n, source, target);
    usleep(500000);
    solveHanoi(n - 1, aux, source, target);
}