//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: portable
#include <stdio.h>

void tower_of_hanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1){
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    tower_of_hanoi(n-1, source, auxiliary, destination);
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    tower_of_hanoi(n-1, auxiliary, destination, source);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tower_of_hanoi(n, 'A', 'C', 'B'); 
    return 0;
}