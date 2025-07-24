//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: careful
#include<stdio.h>

//Function declaration
void tower_of_hanoi(int n, char source, char destination, char intermediate);

int main()
{
    int n;

    //Input number of discs
    printf("Enter the number of discs: ");
    scanf("%d", &n);

    //Call function
    tower_of_hanoi(n, 'A', 'C', 'B');

    return 0;
}

//Function to solve Tower of Hanoi problem
void tower_of_hanoi(int n, char source, char destination, char intermediate)
{
    if(n==1)  //Base case
    {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }

    tower_of_hanoi(n-1, source, intermediate, destination);   //Move n-1 discs from source to intermediate

    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);  //Move nth disk from source to destination

    tower_of_hanoi(n-1, intermediate, destination, source);   //Move n-1 discs from intermediate to destination
}