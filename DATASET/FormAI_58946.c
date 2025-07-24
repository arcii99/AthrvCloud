//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: excited
#include<stdio.h>
void hanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("\nMove disk 1 from %c to %c", a, c);
        return;
    }
    hanoi(n - 1, a, c, b);
    printf("\nMove disk %d from %c to %c", n, a, c);
    hanoi(n - 1, b, a, c);
}
 
int main()
{
    int n;
    printf("Oh yeah! Let's play Tower of Hanoi game! ");
    printf("Enter the number of disks : ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    printf("\nAwesome! Congratulations! You have solved the problem.");
    return 0;
}