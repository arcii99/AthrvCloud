//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: beginner-friendly
#include<stdio.h>
void tower_of_hanoi(int num, char from_rod, char to_rod, char aux_rod)
{
    if (num == 1) // base case
    {
        printf("\n Move disk 1 from %c to %c", from_rod, to_rod);
        return;
    }
    tower_of_hanoi(num - 1, from_rod, aux_rod, to_rod); // recursive call for n-1 discs
    printf("\n Move disk %d from %c to %c", num, from_rod, to_rod);
    tower_of_hanoi(num - 1, aux_rod, to_rod, from_rod); // recursive call for n-1 discs
}
int main()
{
    int num;
    printf("Enter the number of disks: ");
    scanf("%d", &num);
    tower_of_hanoi(num, 'A', 'C', 'B'); // call the function
    return 0;
}