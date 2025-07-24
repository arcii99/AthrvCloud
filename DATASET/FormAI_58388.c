//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: cheerful
#include <stdio.h>

void hanoi(int n, char source_rod, char destination_rod, char auxiliary_rod) 
{
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source_rod, destination_rod);
        return;
    }
    hanoi(n - 1, source_rod, auxiliary_rod, destination_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, source_rod, destination_rod);
    hanoi(n - 1, auxiliary_rod, destination_rod, source_rod);
}
 
int main() 
{
    int num_disk;
    printf("Welcome to the Tower of Hanoi game!\n");
    printf("How many disks would you like to play with? ");
    scanf("%d", &num_disk);
    printf("Alright! Let's get started!\n\n");
    hanoi(num_disk, 'A', 'C', 'B');
    printf("\nCongratulations, you finished the game!\n");
    return 0;
}