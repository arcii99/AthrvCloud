//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: high level of detail
#include <stdio.h>

//Function to move disks
void moveDisk(int n, char source, char destination, char auxiliary) {
    //Base case
    if(n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    //Recursive call
    moveDisk(n-1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    moveDisk(n-1, auxiliary, destination, source);
}

//Main function
int main() {
    int num_disks;

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    //Calling the function to move disks
    moveDisk(num_disks, 'A', 'C', 'B');

    return 0;
}