//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: lively
#include<stdio.h>

void TOH(int disc, char source, char auxiliary, char destination) {
    if(disc == 1) {
        printf("\nMove disk 1 from rod %c to rod %c", source, destination);
        return;
    }
    TOH(disc-1,source,destination,auxiliary);
    printf("\nMove disk %d from rod %c to rod %c",disc,source,destination);
    TOH(disc-1,auxiliary,source,destination);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    if(n<=0) {
        printf("Invalid input. Number of disks must be a positive integer.\n");
        return 0;
    }
    TOH(n,'A','B','C');
    printf("\n");
    return 0;
}