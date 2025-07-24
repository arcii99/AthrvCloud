//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: curious
#include<stdio.h>
void tower_of_hanoi(int, char, char, char);
int main()
{
    int n;
    printf("Hello there! Welcome to a curious and unique Tower of Hanoi problem.\n");
    printf("Tell me, how many disks do you want to play with today? : ");
    scanf("%d",&n);
    printf("\n");

    if(n <= 0)
    {
        printf("Oh no, that won't do. The number of disks should be greater than 0!\n");
        printf("Bye now! Have a good day.\n");
        return 0;
    }
    
    printf("Very good! So we have %d disks today to play with.\n", n);
    printf("Now hold onto your hats, let's start the game!\n\n");
    
    tower_of_hanoi(n, 'A', 'C', 'B');
    printf("\n\nWell done! You have successfully completed the game of Tower of Hanoi.\n");
    printf("You might want to consider applying for a job at NASA. Your brain is out of this world.\n");
    return 0;
}

void tower_of_hanoi(int n, char src, char dest, char tmp)
{
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n",src,dest);
        return;
    }
    
    tower_of_hanoi(n-1, src, tmp, dest);
    printf("Move disk %d from %c to %c\n",n,src,dest);
    tower_of_hanoi(n-1, tmp, dest, src);
}