//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: artistic
#include <stdio.h>
 
void towers(int, char, char, char);
 
int main()
{
    int num_of_disks;
 
    printf("Enter the number of disks : ");
    scanf("%d", &num_of_disks);
    fflush(stdin);
 
    printf("\n\nThe sequence of moves involved in the Tower of Hanoi are :\n\n");
    towers(num_of_disks, 'A', 'C', 'B');
 
    return 0;
}
void towers(int num_of_disks, char from_tower, char to_tower, char aux_tower)
{
    if (num_of_disks == 1)
    {
        printf("\n Move disk 1 from tower %c to tower %c", from_tower, to_tower);
        return;
    }
    towers(num_of_disks-1, from_tower, aux_tower, to_tower);
    printf("\n Move disk %d from tower %c to tower %c", num_of_disks, from_tower, to_tower);
    towers(num_of_disks-1, aux_tower, to_tower, from_tower);
}