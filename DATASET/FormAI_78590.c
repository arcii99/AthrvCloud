//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to move the disks recursively
void moveDisk(int diskNumber, char sourcePole, char destinationPole, char auxiliaryPole) {
    if(diskNumber == 1) {
        printf("Move disk 1 from %c to %c\n", sourcePole, destinationPole);
        return;
    }

    moveDisk(diskNumber - 1, sourcePole, auxiliaryPole, destinationPole);
    printf("Move disk %d from %c to %c\n", diskNumber, sourcePole, destinationPole);
    moveDisk(diskNumber - 1, auxiliaryPole, destinationPole, sourcePole);
}

// Function to check valid number of disks
bool isValidNumberOfDisks(int numberOfDisks) {
    return (numberOfDisks > 0) ? true : false;
}

// Function to request user input for number of disks
int askUserForNumberOfDisks() {
    int numberOfDisks;
    printf("Please enter the number of disks (positive integer): ");
    scanf("%d", &numberOfDisks);

    while(!isValidNumberOfDisks(numberOfDisks)) {
        printf("Invalid number of disks. Please enter a positive integer: ");
        scanf("%d", &numberOfDisks);
    }

    return numberOfDisks;
}

int main() {
    int numberOfDisks = askUserForNumberOfDisks();
    char sourcePole = 'A';
    char destinationPole = 'C';
    char auxiliaryPole = 'B';

    moveDisk(numberOfDisks, sourcePole, destinationPole, auxiliaryPole);

    return 0;
}