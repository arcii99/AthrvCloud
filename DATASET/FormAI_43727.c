//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: energetic
#include <stdio.h>

// Function to move disks from source to destination
void move(int n, char source, char destination, char auxiliary)
{
    if(n == 1) // Base case: If only one disk is there, move it directly from source to destination
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    // Move (n-1) disks from source to auxiliary using the destination pole
    move(n - 1, source, auxiliary, destination);

    // Move the last disk from source to destination pole
    printf("Move disk %d from %c to %c\n", n, source, destination);

    // Move (n-1) disks from auxiliary to destination using the source pole
    move(n - 1, auxiliary, destination, source);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("Steps to solve the Tower of Hanoi problem with %d disks:\n", n);
    move(n,'A','C','B'); // function call to move n disks from pole 'A' to pole 'C' with 'B' as auxiliary pole

    return 0;
}