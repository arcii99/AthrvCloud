//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: careful
#include <stdio.h>

void solve(int n, char source, char destination, char spare) {

    if(n==1) { // base case
        printf("\tMove disk 1 from %c to %c\n", source, destination);
        return;
    }
    /* 
     * Move the top n-1 disks from the source tower to the spare tower 
     */
    solve(n-1, source, spare, destination);

    /* 
     * Move the n-th disk from the source tower to the destination tower 
     */
    printf("\tMove disk %d from %c to %c\n", n, source, destination);

    /*
     * Move the n-1 disks from the spare tower to the destination tower 
     */
    solve(n-1, spare, destination, source);
}

int main() {
    int n;
    printf("\nEnter the number of disks: ");
    scanf("%d", &n);
    printf("\nThe solution to the Tower of Hanoi problem for %d disks is:\n", n);
    solve(n, 'A', 'C', 'B');
    return 0;
}