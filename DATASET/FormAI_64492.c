//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: irregular
#include <stdio.h>
#define DELAY 50000000
void move(int, int, int, int, char, char, char);
int main()
{
    int n = 6;  // number of disks
    printf("\n**************************************************");
    printf("\n* Welcome to the Irregular Tower of Hanoi Problem! *");
    printf("\n**************************************************\n\n");
    printf("You are required to move all the disks from Tower A to Tower C using Tower B as an intermediary.\n");

    printf("\nTower A: ");
    for (int i = n; i >= 1; i--)
        printf("%d ", i);

    printf("\nTower B: ");
    for (int i = 1; i <= n / 2; i++)
        printf("%d ", i);

    printf("\n           ");
    for (int i = 1; i <= n / 2; i++)
        printf("%d ", i + n / 2);

    printf("\nTower C: ");

    for (int i = 1; i <= n; i++)
        printf("%d ", i);

    printf("\n\nPress any key to begin...");
    getchar();
    printf("\n");
    move(n, 1, 3, 2, 'A', 'C', 'B');
    printf("\n\n**************************************************");
    printf("\n*                Congratulations!                 *");
    printf("\n* You have successfully solved the problem!       *");
    printf("\n**************************************************\n\n");
    return 0;
}

void move(int n, int source, int dest, int spare, char source_name, char dest_name, char spare_name)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source_name, dest_name);
        delay(DELAY);
        return;
    }
    else
    {
        move(n - 1, source, spare, dest, source_name, spare_name, dest_name);
        printf("Move disk %d from %c to %c\n", n, source_name, dest_name);
        delay(DELAY);
        move(n - 1, spare, dest, source, spare_name, dest_name, source_name);
    }
}

void delay(int n)
{
    volatile int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
        }
    }
}