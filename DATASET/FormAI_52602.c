//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: excited
// Yay, let's solve the Tower of Hanoi problem!
#include<stdio.h>

void moveDisks(int, char, char, char); // function prototype

int main() {
    int numDisks;

    // let's ask the user for the number of disks
    printf("Welcome, let's solve the Tower of Hanoi problem!\n");
    printf("How many disks would you like? ");

    scanf("%d", &numDisks);

    // let's ensure the user inputs a positive number
    while (numDisks <= 0) {
        printf("Please enter a positive integer: ");
        scanf("%d", &numDisks);
    }

    // let's call the move disks function recursively to solve the problem
    printf("Alright, let's solve the problem!\n");
    moveDisks(numDisks, 'A', 'C', 'B');

    return 0;
}

// let's define the move disks function
void moveDisks(int num, char source, char target, char spare) {
    if (num == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, target);
        return;
    }

    moveDisks(num-1, source, spare, target);
    printf("Move disk %d from rod %c to rod %c\n", num, source, target);
    moveDisks(num-1, spare, target, source);
}