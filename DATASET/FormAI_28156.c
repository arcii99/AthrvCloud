//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: unmistakable
#include <stdio.h>

void towerOfHanoi(int n, char source, char auxiliary, char target) {
    if(n==1) {
        printf("\nMove disk 1 from rod %c to rod %c",source,target);
        return;
    }
    towerOfHanoi(n-1,source,target,auxiliary);
    printf("\nMove disk %d from rod %c to rod %c",n,source,target);
    towerOfHanoi(n-1,auxiliary,source,target);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    towerOfHanoi(n,'A','B','C');
    return 0;
}