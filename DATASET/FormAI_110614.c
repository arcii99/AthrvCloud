//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: mind-bending
#include <stdio.h>

void moveDisk(char fromPeg, char toPeg, int diskNo)
{
    printf("Moving disk %d from %c to %c\n", diskNo, fromPeg, toPeg);
}

void towerOfHanoi(int numDisks, char fromPeg, char toPeg, char auxPeg)
{
    if (numDisks == 1)
    {
        moveDisk(fromPeg, toPeg, 1);
        return;
    }

    towerOfHanoi(numDisks - 1, fromPeg, auxPeg, toPeg);
    moveDisk(fromPeg, toPeg, numDisks);
    towerOfHanoi(numDisks - 1, auxPeg, toPeg, fromPeg);
}

int main()
{
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);
    towerOfHanoi(numDisks, 'A', 'C', 'B');

    printf("\nWow! You just completed the legendary Tower of Hanoi problem.\nAs a reward, here's a fun fact:\n\nIn an alternate universe, there exists a version of the Tower of Hanoi problem where the disks are replaced with cats and the pegs are replaced with boxes.\nWould you like to give that a try? (y/n): ");

    char choice;
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        printf("\nOkay, let's do this!\nKeep in mind, the cats can only be moved one at a time and a larger cat cannot be placed on top of a smaller cat.\n\n");
        towerOfHanoi(numDisks, 'A', 'C', 'B');
        printf("\nCongratulations on successfully completing the Cat Tower of Hanoi problem!\n\nThanks for using this program, hope you had fun!");
    }
    else
    {
        printf("\nNo worries, maybe next time!\nThanks for using this program, hope you had fun!");
    }

    return 0;
}