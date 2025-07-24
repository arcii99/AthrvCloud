//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: happy
#include <stdio.h>

//Function to move the disks from source to destination
void towerOfHanoi(int num_of_disks, char source_rod, char destination_rod, char auxiliary_rod)
{
    if (num_of_disks == 1)
    {
        printf("1 disk moved from %c to %c\n", source_rod, destination_rod);
        return;
    }

    towerOfHanoi(num_of_disks - 1, source_rod, auxiliary_rod, destination_rod);
    printf("%d disk moved from %c to %c\n", num_of_disks, source_rod, destination_rod);
    towerOfHanoi(num_of_disks - 1, auxiliary_rod, destination_rod, source_rod);
}

int main()
{
    int num_of_disks;
    printf("Welcome to the Tower of Hanoi problem game!\n");
    printf("Please enter the number of disks you want to play with: ");
    scanf("%d", &num_of_disks);
    
    printf("Alright, let's begin...\n");
    towerOfHanoi(num_of_disks, 'A', 'C', 'B');
    printf("Congratulations! You have won the Tower of Hanoi game!\n");
    return 0;
}