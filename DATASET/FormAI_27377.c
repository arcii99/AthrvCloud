//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: expert-level
#include <stdio.h>

void hanoi(int n, char source, char temp, char dest){
    if(n == 0){
        return;
    }
    hanoi(n-1, source, dest, temp);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    hanoi(n-1, temp, source, dest);
}

int main(){
    int numDisks;
    printf("Enter number of disks: ");
    scanf("%d", &numDisks);

    hanoi(numDisks, 'A', 'B', 'C');

    return 0;
}

/*
Sample Output:
Enter number of disks: 3
Move disk 1 from A to C
Move disk 2 from A to B
Move disk 1 from C to B
Move disk 3 from A to C
Move disk 1 from B to A
Move disk 2 from B to C
Move disk 1 from A to C
*/