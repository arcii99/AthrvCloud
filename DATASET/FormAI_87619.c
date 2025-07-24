//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

void move(char start_pole, char end_pole, int num_of_disks)
{
    if(num_of_disks == 1)
    {
        printf("Move disk 1 from pole %c to pole %c\n", start_pole, end_pole);
        return;
    }
    move(start_pole, 'B', num_of_disks - 1);
    printf("Move disk %d from pole %c to pole %c\n", num_of_disks, start_pole, end_pole);
    move('B', end_pole, num_of_disks - 1);
}

int main()
{
    int num_of_disks;
    printf("Enter the number of disks to be moved: ");
    scanf("%d", &num_of_disks);
    if(num_of_disks <= 0)
    {
        printf("Invalid Input\n");
        exit(0);
    }
    move('A', 'C', num_of_disks);
    return 0;
}