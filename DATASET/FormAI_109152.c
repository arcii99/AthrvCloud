//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surrealist
#include <stdio.h>

void hanoi(int disks, char source, char destination, char auxillary){
    if(disks == 1){
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    hanoi(disks - 1, source, auxillary, destination);
    printf("Move disk %d from rod %c to rod %c\n", disks, source, destination);
    hanoi(disks - 1, auxillary, destination, source);
}

int main(){
    int n = 3;
    printf("Surreal Tower of Hanoi Problem\n");
    printf("Watch as the disks move themselves...\n");
    hanoi(n, 'A', 'C', 'B');
    printf("All disks have been moved\n");
    return 0;
}