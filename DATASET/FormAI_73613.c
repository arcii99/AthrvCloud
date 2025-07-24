//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

void move(char from, char to, int level)
{
    printf("Move disk %d from rod %c to rod %c\n", level, from, to);
}

void tower_of_hanoi(char source, char auxiliary, char destination, int level)
{
    if (level == 1) {
        move(source, destination, level);
    } else {
        tower_of_hanoi(source, destination, auxiliary, level - 1);
        move(source, destination, level);
        tower_of_hanoi(auxiliary, source, destination, level - 1);
    }
}

int main()
{
    int level;
    printf("Enter the number of disks: ");
    scanf("%d", &level);
    
    if (level <= 0) {
        printf("Invalid number of disks!\n");
        exit(1);
    }
    
    tower_of_hanoi('A', 'B', 'C', level);
    return 0;
}