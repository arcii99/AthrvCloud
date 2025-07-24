//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: calm
#include <stdio.h>
void hanoi(int n, char start_peg, char end_peg, char temp_peg)
{
    if (n == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", start_peg, end_peg);
        return;
    }
    hanoi(n - 1, start_peg, temp_peg, end_peg);
    printf("Move disk %d from peg %c to peg %c\n", n, start_peg, end_peg);
    hanoi(n - 1, temp_peg, end_peg, start_peg);
}
int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The moves involved in the Tower of Hanoi are:\n");
    hanoi(n, 'A', 'C', 'B');
    return 0;
}